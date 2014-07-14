/*
** cluster.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Fri May 30 20:32:42 2014 chambon emmanuel
** Last update Sun Jun  8 23:28:03 2014 chambon emmanuel
*/

#include "rt.h"

char	*get_double_som(int flag, t_spot *spot, t_obj *obj, t_opt *eye)
{
  char	*ret;

  if (!(ret = my_xmalloc(128)))
    return (NULL);
  bzero(ret, 128);
  if (flag == 0)
    sprintf(ret, "%lf;%lf;%lf;", eye->eye_pos[0], eye->eye_pos[1],
	    eye->eye_pos[2]);
  else if (flag == 1)
    sprintf(ret, "%lf;%lf;%lf;", eye->eye_rot[0], eye->eye_rot[1],
	    eye->eye_rot[2]);
  else if (flag == 2)
    sprintf(ret, "%lf;%lf;%lf;", spot->pos[0], spot->pos[1], spot->pos[2]);
  else if (flag == 3)
    sprintf(ret, "%lf;%lf;%lf;", obj->obj_pos[0], obj->obj_pos[1],
            obj->obj_pos[2]);
  else if (flag == 4)
    sprintf(ret, "%lf;%lf;%lf;", obj->obj_rot[0], obj->obj_rot[1],
            obj->obj_rot[2]);
  return (ret);
}

int	handle_recv(t_arg_thread *arg, int socket_fd)
{
  char	buffer[MAX];
  int	bytes;
  int	bytes_neces;

  bytes_neces = arg->client->beg * 4;
  while (1)
    {
      bzero(buffer, MAX);
      bytes = recv(socket_fd, buffer, MAX - 1, 0);
      if (bytes == 0 || bytes == -1)
	{
	  if (bytes == 1)
	    perror("recv");
	  return (-1);
	}
      memcpy(&arg->rt->img->data[bytes_neces], buffer, bytes);
      bytes_neces += bytes;
    }
  return (0);
}

void		*connect_client(void *data)
{
  t_arg_thread	*arg;
  int		socket_fd;

  arg = (t_arg_thread *)data;
  if ((socket_fd = send_info(arg, 0)) == -1)
    {
      free(arg);
      return (NULL);
    }
  handle_recv(arg, socket_fd);
  free(arg);
  close(socket_fd);
  return (NULL);
}

void	wait_thread(pthread_t *thread, t_client *client)
{
  int	i;

  i = 0;
  while (i < get_nb_client(client))
    {
      pthread_join(thread[i], NULL);
      i++;
    }
  free(thread);
}

int		activate_client(t_client *client, t_rt *rt)
{
  t_client	*tmp;
  t_arg_thread	*arg;
  pthread_t	*thread;
  int		i;

  i = 0;
  if (!(thread = my_xmalloc((get_nb_client(client)) * sizeof(pthread_t))))
    return (-1);
  tmp = client;
  while (tmp && tmp->servinfo)
    {
      if (!(arg = my_xmalloc(sizeof(t_arg_thread))))
	return (-1);
      arg->rt = rt;
      arg->client = tmp;
      if (pthread_create(&thread[i], NULL, connect_client, (void *)arg) != 0)
	fprintf(stderr, THREAD_ERROR, tmp->hostname);
      tmp = tmp->next;
      i++;
    }
  wait_thread(thread, client);
  return (0);
}
