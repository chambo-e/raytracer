/*
** set_objs.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder/client
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sat May 31 07:10:22 2014 chambon emmanuel
** Last update Sat Jul  5 21:03:26 2014 chambon emmanuel
*/

#include "client_rt.h"

int		add_info_obj(char *line, t_obj *tmp)
{
  if (!(tmp->color = my_xmalloc(sizeof(t_color) * 2)))
    return (-1);
  if (sscanf(line, OBJ_FORMAT, &tmp->obj_pos[0], &tmp->obj_pos[1],
	     &tmp->obj_pos[2], &tmp->obj_rot[0], &tmp->obj_rot[1],
	     &tmp->obj_rot[2], (int *)&tmp->type, &tmp->special,
	     &tmp->rayon, &tmp->angle, (int *)&tmp->color->rgba[0],
	     (int *)&tmp->color->rgba[1], (int *)&tmp->color->rgba[2],
	     (int *)&tmp->color->rgba[3],
	     &tmp->brill, (int *)&tmp->texture) < 16)
    return (-1);
  set_fct_ptr(tmp, 0);
  return (0);
}

int		set_second_obj(t_obj *objs, t_obj *tmp, char *line)
{
  objs->next = tmp;
  tmp->next = NULL;
  tmp->previous = objs;
  if (add_info_obj(line, tmp) == -1)
    return (-1);
  return (0);
}

int		set_obj(char *line, t_obj *objs)
{
  t_obj		*tmp;

  if (!(tmp = my_xmalloc(sizeof(t_obj))))
    return (-1);
  if (objs->next)
    {
      while (objs->next)
        objs = objs->next;
      tmp->next = NULL;
      if (add_info_obj(line, tmp) == -1)
        return (-1);
      objs->next = tmp;
      tmp->previous = objs;
    }
  else if (!objs->next && !objs->color)
    {
      free(tmp);
      if (add_info_obj(line, objs) == -1)
        return (-1);
    }
  else if (set_second_obj(objs, tmp, line) == -1)
    return (-1);
  return (0);
}
