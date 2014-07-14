/*
** decrypt.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder/client
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sat May 31 07:00:17 2014 chambon emmanuel
** Last update Sun Jun  8 23:09:18 2014 david tran
*/

#include "client_rt.h"

int				set_limit(char *line, t_rt_client *rt)
{
  if (sscanf(line, "LM;%d;%d;%d;%d", &rt->beg, &rt->end,
	     &rt->winsize_x, &rt->winsize_y) != 4)
    return (-1);
  return (0);
}

int				draw_image(t_rt_client *rt, int socket_server)
{
  t_color			color;
  int				i;
  int				x;
  int				y;

  i = 0;
  if (!(rt->data = my_xmalloc((rt->end - rt->beg) * 4)))
    return (0);
  bzero(rt->data, (rt->end - rt->beg) * 4);
#pragma omp parallel for schedule (dynamic) private(x, y) private (color)
  for (i = 0; i < rt->end - rt->beg; i++)
    {
      x = (rt->beg + i) % WINX;
      y = (rt->beg + i) / WINX;
      if (rt->eye->aa == 1)
	color.color = cast_a_ray_alias(rt, x, y);
      else
	color.color = get_the_scene(rt, x, y);
      pxl(rt, i, color.color);
    }
  send_data(rt->data, rt, socket_server);
  return (0);
}

int				find_cor(char *line, t_rt_client *rt)
{
  if (!(strncmp(line, "LM;", 3)))
    {
      if (set_limit(line, rt) == -1)
	return (-1);
    }
  else if (!(strncmp(line, "EY;", 3)))
    {
      if (set_eye(line, rt) == -1)
	return (-1);
    }
  else if (!(strncmp(line, "SP;", 3)))
    {
      if (set_spot(line, rt->spot) == -1)
	return (-1);
    }
  else if (!(strncmp(line, "OB;", 3)))
    if (set_obj(line, rt->objs) == -1)
      return (-1);
  if (!(*line + 1) && strcmp(line, "DONE!"))
    {
      fprintf(stderr, "Problem while receiving informations\n");
      return (-1);
    }
  return (0);
}

int				decrypt(char buffer[], int socket_server)
{
  t_rt_client			*rt;
  char				**t;
  int				i;

  i = 0;
  if (!(t = my_str_to_wordtab(buffer, '*'))
      || !(rt = my_xmalloc(sizeof(t_rt_client))))
    return (0);
  if (init_struct(rt) == -1)
    return (0);
  while (t[i])
    {
      if (find_cor(t[i], rt) == -1)
	return (free_rt_client(rt));
      i++;
    }
  if (draw_image(rt, socket_server) == -1)
    return (0);
  free_rt_client(rt);
  return (0);
}

int				handle_client(int sock, int bytes)
{
  int				socket_server;
  socklen_t			size;
  struct sockaddr_storage	connect_info;
  char				buffer[MAX];

  bzero(buffer, 10);
  while (42)
    {
      size = sizeof(connect_info);
      socket_server = accept(sock, (struct sockaddr *)&connect_info, &size);
      if (socket_server == -1)
        {
          perror("accept");
          continue;
        }
      if ((bytes = recv(socket_server, buffer, MAX - 1, 0)) == -1)
        {
          perror("recv");
          return (-1);
        }
      buffer[bytes] = 0;
      if (decrypt(buffer, socket_server) == -1)
        return (-1);
    }
  return (0);
}
