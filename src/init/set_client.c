/*
** set_client.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 13:14:49 2014 chambon emmanuel
** Last update Fri Jun  6 11:44:40 2014 chambon emmanuel
*/

#include "rt.h"

char			*get_host(char *line)
{
  int			i;

  i = 0;
  while (line[i] && line[i] != DEFINE_CHAR)
    i++;
  return (strdup(epur_str(&line[i + 1])));
}

int			delete_client(t_client *tmp)
{
  if (tmp->servinfo)
    freeaddrinfo(tmp->servinfo);
  if (tmp->hostname)
    free(tmp->hostname);
  if (tmp->service)
    free(tmp->service);
  free(tmp);
  return (-1);
}

int			already_there(char *service, t_client *client)
{
  t_client		*tmp;

  if (!client)
    return (-1);
  tmp = client;
  while (tmp && tmp->servinfo)
    {
      if (!(strcmp(service, tmp->service)))
	return (0);
      tmp = tmp->next;
    }
  return (-1);
}

int			add_info_client(char *line, t_client *tmp, t_client *client)
{
  struct addrinfo	hints;
  char			*host;
  char			service[INET6_ADDRSTRLEN];
  int			res;

  bzero(&hints, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = INADDR_ANY | AI_PASSIVE;
  if (!(host = get_host(line)) || (strlen(host) <= 1))
    return (print_error(CLIENT_MISSING));
  if ((res = getaddrinfo(host, PORT, &hints, &tmp->servinfo)))
    return (print_error(UNKNOW_HOST));
  bzero(service, INET6_ADDRSTRLEN);
  if (!(inet_ntop(tmp->servinfo->ai_family,
			      get_in_addr((struct sockaddr *)tmp->servinfo->ai_addr),
			      service, INET6_ADDRSTRLEN)))
    return (print_error(INVALID_ADRESS));
  if (!(tmp->service = strdup(service)))
    return (print_error(MALLOC_ERROR));
  tmp->hostname = host;
  if (!(already_there(service, client)))
    return (delete_client(tmp));
  return (0);
}
