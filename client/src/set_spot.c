/*
** set_spot.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder/client
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sat May 31 07:05:59 2014 chambon emmanuel
** Last update Sat Jul  5 21:05:16 2014 chambon emmanuel
*/

#include "client_rt.h"

int			init_struct(t_rt_client *rt)
{
  if (!(rt->spot = my_xmalloc(sizeof(t_spot)))
      || !(rt->objs = my_xmalloc(sizeof(t_obj))))
    return (-1);
  rt->eye = NULL;
  rt->imend = 0;
  rt->spot->pos[0] = 0;
  rt->spot->next = NULL;
  rt->spot->color = NULL;
  rt->spot->previous = NULL;
  rt->objs->type = -1;
  rt->objs->obj_pos[0] = 0;
  rt->objs->obj_rot[0] = 0;
  rt->objs->color = NULL;
  rt->objs->brill = 0;
  rt->objs->texture = 0;
  rt->objs->next = NULL;
  rt->objs->previous = NULL;
  return (0);
}

int			add_info_spot(char *line, t_spot *spot)
{
  if (!(spot->color = my_xmalloc(sizeof(t_color) * 2)))
    return (-1);
  if (sscanf(line, SPOT_FORMAT, &spot->pos[0],
             &spot->pos[1], &spot->pos[2], (int *)&spot->type,
             (int *)&spot->color->rgba[0], (int *)&spot->color->rgba[1],
             (int *)&spot->color->rgba[2], (int *)&spot->color->rgba[3]) != 8)
    return (-1);
  return (0);
}

int			set_second_spot(t_spot *spot, t_spot *tmp, char *line)
{
  spot->next = tmp;
  tmp->next = NULL;
  tmp->previous = spot;
  if (add_info_spot(line, tmp) == -1)
    return (-1);
  return (0);
}

int			set_spot(char *line, t_spot *spot)
{
  t_spot		*tmp;

  if (!(tmp = my_xmalloc(sizeof(t_spot))))
    return (-1);
  if (spot->next)
    {
      while (spot->next)
        spot = spot->next;
      tmp->next = NULL;
      if (add_info_spot(line, tmp) == -1)
        return (-1);
      spot->next = tmp;
      tmp->previous = spot;
    }
  else if (!spot->next && !spot->color)
    {
      free(tmp);
      if (add_info_spot(line, spot) == -1)
        return (-1);
    }
  else if (set_second_spot(spot, tmp, line) == -1)
    return (-1);
  return (0);
}
