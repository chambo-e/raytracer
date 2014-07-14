/*
** init_app.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/MUL_2013_rtracer
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Thu Jun 19 14:32:29 2014 chambon emmanuel
** Last update Mon Jul 14 15:56:17 2014 chambon emmanuel
*/

#include "rt.h"

/* Create the local socket and bind it */

int			create_sock_app(struct addrinfo *tmp)
{
  int			sock;
  int			yes;

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
      close(sock);
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

/* Loop through the addrinfo list */

int			socket_app(struct addrinfo *servinfo)
{
  struct addrinfo	*tmp;
  int			sock;

  tmp = servinfo;
  while (tmp)
    {
      if ((sock = create_sock_app(tmp)) == -1)
        tmp = tmp->ai_next;
      else
        break;
    }
  return (sock);
}

/* Create local addrinfo struct */

int			init_socket_app(void)
{
  struct addrinfo	*servinfo;
  struct addrinfo	hints;
  int			gai_ret;
  int			sock;

  bzero(&hints, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = INADDR_ANY | AI_PASSIVE;
  if ((gai_ret = getaddrinfo(NULL, PORT_APP, &hints, &servinfo)))
    {
      fprintf(stderr, "getaddrinfo : %s\n", gai_strerror(gai_ret));
      return (-1);
    }
  if ((sock = socket_app(servinfo)) == -1)
    return (-1);
  freeaddrinfo(servinfo);
  return (sock);
}
