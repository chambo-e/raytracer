/*
** free_rt_client.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder/client
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun Jun  1 01:46:20 2014 chambon emmanuel
** Last update Thu Jun  5 22:24:24 2014 emmanuel chambon
*/

#include "client_rt.h"

void		free_objs_client(t_obj *objs)
{
  t_obj		*tmp;

  while (objs)
    {
      tmp = objs;
      objs = objs->next;
      if (tmp->color)
        free(tmp->color);
      free(tmp);
    }
}

void		free_spot_client(t_spot *spot)
{
  t_spot	*tmp;

  while (spot)
    {
      tmp = spot;
      spot = spot->next;
      if (tmp->color)
        free(tmp->color);
      free(tmp);
    }
}

int		free_rt_client(t_rt_client *rt)
{
  if (rt)
    {
      if (rt->eye)
	free(rt->eye);
      if (rt->objs)
	free_objs_client(rt->objs);
      if (rt->spot)
	free_spot_client(rt->spot);
      free(rt);
    }
  return (0);
}
