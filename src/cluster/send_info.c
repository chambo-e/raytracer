/*
** send_info.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sat May 31 01:42:37 2014 chambon emmanuel
** Last update Sun Jun  8 23:09:26 2014 chambon emmanuel
*/

#include "rt.h"

int			assemble_and_send(t_send *s_str, int socket_fd)
{
  char			*se;

  if (!(se = my_xmalloc(strlen(s_str->limit) + strlen(s_str->eye)
			+ strlen(s_str->spot) + strlen(s_str->obj) + 6)))
    return (-1);
  bzero(se, strlen(s_str->limit) + strlen(s_str->eye) + strlen(s_str->spot)
	+ strlen(s_str->obj) + 5);
  strcat(se, s_str->limit);
  strcat(se, s_str->eye);
  strcat(se, s_str->spot);
  strcat(se, s_str->obj);
  strcat(se, "DONE!");
  if (send(socket_fd, (void *)se, strlen(se), 0) == -1)
    {
      perror("send");
      return (-1);
    }
  free(s_str->eye);
  free(s_str->obj);
  free(s_str->spot);
  free(s_str->limit);
  free(se);
  return (0);
}

char			*concat_limit(t_client *client, t_rt *rt)
{
  char			*ret;

  if (!(ret = my_xmalloc((4 * sizeof(int)) + 48)))
    return (NULL);
  bzero(ret, (4 * sizeof(int)) + 48);
  sprintf(ret, "LM;%d;%d;%d;%d*", client->beg, client->end, WINX, WINY);
  return (ret);
}

int			send_data(int socket_fd, t_rt *rt, t_client *client)
{
  t_send		send_struct;

  if (!(send_struct.limit = concat_limit(client, rt)))
    return (-1);
  if (!(send_struct.eye = concat_opt_struct(rt->eye)))
    return (-1);
  if (!(send_struct.spot = concat_spot_struct(rt->spot)))
    return (-1);
  if (!(send_struct.obj = concat_obj_struct(rt->objs)))
    return (-1);
  if (assemble_and_send(&send_struct, socket_fd) == -1)
    return (-1);
  return (0);
}

int			check_client(struct addrinfo *serv,
				     t_client *client, int *test)
{
  int			socket_fd;

  if ((socket_fd = socket(serv->ai_family, serv->ai_socktype,
                          serv->ai_protocol)) == -1)
    {
      fprintf(stderr, SOCK_ERROR, strerror(errno), (*test), client->hostname);
      return (-1);
    }
  if (connect(socket_fd, serv->ai_addr, serv->ai_addrlen) == -1)
    {
      close(socket_fd);
      fprintf(stderr, CONNECT_ERROR, strerror(errno), (*test),
              client->hostname);
      return (-1);
    }
  printf("%s connecté\n", client->hostname);
  return (socket_fd);
}

int			send_info(t_arg_thread *arg, int socket_fd)
{
  struct addrinfo	*serv;
  int			test;

  test = 1;
  serv = arg->client->servinfo;
  while (serv)
    {
      printf("Trying to connect to : %s - test n°%d\n",
             arg->client->hostname, test);
      if ((socket_fd = check_client(serv, arg->client, &test)) == -1)
        serv = serv->ai_next;
      else
        break ;
      test++;
    }
  if (!serv)
    {
      fprintf(stderr, UNREACH, arg->client->hostname);
      return (-1);
    }
  if (send_data(socket_fd, arg->rt, arg->client) == -1)
    return (-1);
  return (socket_fd);
}
