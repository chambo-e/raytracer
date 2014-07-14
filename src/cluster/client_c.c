/*
** client_c.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Fri Jun  6 11:43:14 2014 chambon emmanuel
** Last update Fri Jun  6 11:44:32 2014 chambon emmanuel
*/

#include "rt.h"

int			set_second_client(t_client *client, t_client *tmp, char *line)
{
  if (add_info_client(line, tmp, client) == -1)
    return (-1);
  client->next = tmp;
  tmp->next = NULL;
  return (0);
}

int			add_client(char *line, t_client *client)
{
  t_client		*tmp;
  t_client		*wheel;

  if (!(tmp = my_xmalloc(sizeof(t_client))))
    return (-1);
  if (client && client->next)
    {
      wheel = client;
      while (wheel->next)
        wheel = wheel->next;
      if (add_info_client(line, tmp, client) == -1)
        return (-1);
      tmp->next = NULL;
      wheel->next = tmp;
    }
  else if (!client->servinfo && !client->next)
    {
      free(tmp);
      if (add_info_client(line, client, NULL) == -1)
        return (-1);
    }
  else if (set_second_client(client, tmp, line) == -1)
    return (-1);
  return (0);
}

int			get_client(t_parse *lines, t_rt *rt)
{
  t_parse		*tmp;

  if (!(rt->client = my_xmalloc(sizeof(t_client))))
    return (-1);
  rt->client->servinfo = NULL;
  rt->client->next = NULL;
  rt->client->service = NULL;
  rt->client->hostname = NULL;
  tmp = lines;
  while (tmp)
    {
      if (!(strncmp(tmp->line, "CLIENT", 6)))
        add_client(tmp->line, rt->client);
      tmp = tmp->next;
    }
  return (0);
}
