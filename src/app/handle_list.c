/*
** handle_list.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/MUL_2013_rtracer
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun Jul 13 22:28:39 2014 chambon emmanuel
** Last update Sun Jul 13 22:32:03 2014 chambon emmanuel
*/

#include "rt.h"

char                    *get_host_app(char type, char *demand)
{
  if (type == 0)
    return (&demand[6]);
  else if (type == 1)
    return (&demand[7]);
  else if (type == 2)
    return (&demand[8]);
  return (NULL);
}

int                     get_socket_app(char type, char *demand)
{
  struct addrinfo       hints;
  struct addrinfo       *servinfo;
  int                   sock = 0;

  bzero(&hints, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  if (getaddrinfo(get_host_app(type, demand), "7879" , &hints, &servinfo))
    return (-1);
  while (servinfo)
    {
      if ((sock = socket(servinfo->ai_family, servinfo->ai_socktype,
                         servinfo->ai_protocol)) == -1)
        {
          servinfo = servinfo->ai_next;
          continue ;
        }
      if (connect(sock, servinfo->ai_addr, servinfo->ai_addrlen) == -1)
        {
          close(sock);
          servinfo = servinfo->ai_next;
          continue ;
        }
      break ;
    }
  if (!servinfo)
    return (-1);
  return (sock);
}

void            reset_obj(char *objs, t_rt *rt)
{
  char          **obj;
  t_obj         *new;
  int           i;

  i = 1;
  if (!(obj = my_str_to_wordtab(objs, 'O')))
    return ;
  if (!(new = my_xmalloc(sizeof(t_obj))))
    return ;
  new->type = -1;
  new->obj_pos[0] = 0;
  new->obj_rot[0] = 0;
  new->color = NULL;
  new->brill = 0;
  new->texture = 0;
  new->next = NULL;
  new->previous = NULL;
  while (obj[i])
    {
      add_obj_app(obj[i], new, 1);
      i++;
    }
  free_objs(rt->objs);
  rt->objs = new;
  redraw = 1;
}

void            reset_spot(char *spots, t_rt *rt)
{
  char          **spot;
  t_spot        *new;
  int           i;

  i = 1;
  if (!(spot = my_str_to_wordtab(spots, 'S')))
    return ;
  if (!(new = my_xmalloc(sizeof(t_spot))))
    return ;
  new->pos[0] = 0;
  new->color = NULL;
  new->next = NULL;
  new->previous = NULL;
  while (spot[i])
    {
      add_spot_app(spot[i], new, 1);
      i++;
    }
  free_spot(rt->spot);
  rt->spot = new;
  redraw = 1;
}
