/*
** connect_app.c for rt in /home/chambo-e/rtracer/src/app
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Wed Jun 11 17:25:38 2014 chambon emmanuel
** Last update Thu Jun 19 14:40:53 2014 chambon emmanuel
*/

#include "rt.h"

void			recv_from(int socket_app, t_rt *rt)
{
  char			buffer[MAX];
  int			bytes;

  bytes = 1;
  while (bytes > 0)
    {
      bzero(buffer, MAX - 1);
      if ((bytes = recv(socket_app, buffer, MAX - 1, 0)) == -1)
	{
	  perror("recv");
	  return ;
	}
      if (parse_received(buffer, rt) == -1)
	return ;
    }
}

int				handle_app(int sock, t_rt *rt)
{
  int				socket_app;
  socklen_t			size;
  struct sockaddr_storage	connect_info;

  while (42)
    {
      size = sizeof(connect_info);
      if ((socket_app = accept(sock, (struct sockaddr *)&connect_info,
			       &size)) == -1)
	{
	  perror("accept");
	  continue;
	}
      recv_from(socket_app, rt);
    }
  return (0);
}

void			*init_app(void *data)
{
  t_rt			*rt;
  int			sock;

  rt = (t_rt *)data;
  if ((sock = init_socket_app()) == -1)
    return (NULL);
  if (listen(sock, 1) == -1)
    return (NULL);
  if (handle_app(sock, rt) == -1)
    return (NULL);
  return (NULL);
}

void			mlx_app(t_rt *rt)
{
  pthread_t		app_thread;

  if (pthread_create(&app_thread, NULL, init_app, (void *)rt) != 0)
    {
      print_error(THREAD_APP);
      return ;
    }
}
