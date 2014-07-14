/*
** init_client.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder/client
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sat May 31 06:57:25 2014 chambon emmanuel
** Last update Thu Jun 12 17:00:52 2014 chambon emmanuel
*/

#include "client_rt.h"

int				create_sock(struct addrinfo *tmp)
{
  int				sock;
  int				yes;

  yes = 1;
  if ((sock = socket(tmp->ai_family, tmp->ai_socktype,
		     tmp->ai_protocol)) == -1)
    {
      perror("server: socket");
      return (-1);
    }
  if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
    {
      perror("setsockopt");
      return (-1);
    }
  if (bind(sock, tmp->ai_addr, tmp->ai_addrlen) == -1)
    {
      close(sock);
      perror("server: bind");
      return (-1);
    }
  return (sock);
}

int				bind_sock(struct addrinfo *servinfo)
{
  struct addrinfo		*tmp;
  int				sock;

  tmp = servinfo;
  while (tmp)
    {
      if ((sock = create_sock(tmp)) == -1)
        tmp = tmp->ai_next;
      else
        break;
    }
  return (sock);
}

int				init_client(void)
{
  struct addrinfo		*servinfo;
  struct addrinfo		hints;
  int				gai_ret;
  int				sock;

  bzero(&hints, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = INADDR_ANY | AI_PASSIVE;
  if ((gai_ret = getaddrinfo(NULL, PORT, &hints, &servinfo)))
    {
      fprintf(stderr, "getaddrinfo : %s\n", gai_strerror(gai_ret));
      return (-1);
    }
  if ((sock = bind_sock(servinfo)) == -1)
    return (-1);
  freeaddrinfo(servinfo);
  return (sock);
}

void				*get_in_addr(struct sockaddr *sa)
{
  if (sa->sa_family == AF_INET)
    return &(((struct sockaddr_in*)sa)->sin_addr);
  return &(((struct sockaddr_in6*)sa)->sin6_addr);
}
