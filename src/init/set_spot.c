/*
** get_spot.c for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Wed Apr 23 17:29:33 2014 chambon emmanuel
** Last update Fri Jun  6 18:52:40 2014 chambon emmanuel
*/

#include "rt.h"

int			set_default_spot(t_spot *spot)
{
  spot->type = 0;
  spot->pos[0] = 0;
  spot->pos[1] = 0;
  spot->pos[2] = 0;
  if (!(spot->color = my_xmalloc(sizeof(t_color))))
    return (-1);
  memset(spot->color, 255, 4);
  spot->next = NULL;
  return (0);
}

int			set_spot(t_parse *lines, t_rt *rt)
{
  t_parse       *tmp;

  tmp = lines;
  while (tmp && tmp->line)
    {
      if (!(strncmp(tmp->line, "SPOT", 4)))
	if (add_spot(tmp->line, rt->spot) == -1)
	  return (-1);
      tmp = tmp->next;
    }
  if (!rt->spot->color)
    if (set_default_spot(rt->spot) == -1)
      return (-1);
  return (0);
}

int			get_spot(t_parse *lines, t_rt *rt)
{
  if (!(rt->spot = my_xmalloc(sizeof(t_spot))))
    return (-1);
  rt->spot->pos[0] = 0;
  rt->spot->color = NULL;
  rt->spot->next = NULL;
  rt->spot->previous = NULL;
  if (set_spot(lines, rt) == -1)
    return (-1);
  return (0);
}
