/*
** parse_obj.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/MUL_2013_rtracer
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Thu Jun 19 14:08:34 2014 chambon emmanuel
** Last update Sun Jul 13 22:41:36 2014 chambon emmanuel
*/

#include "rt.h"

int		add_info_obj_app_re(char *line, t_obj *tmp)
{
  if (!(tmp->color = my_xmalloc(sizeof(t_color) * 2)))
    return (-1);
  tmp->color->color = 0;
  if ((sscanf(line, O_MODEL,
	     (int *)&tmp->type, &tmp->obj_pos[0],
	     &tmp->obj_pos[1], &tmp->obj_pos[2], &tmp->obj_rot[0],
	     &tmp->obj_rot[1], &tmp->obj_rot[2], (int *)&tmp->color->rgba[0],
	     (int *)&tmp->color->rgba[1], (int *)&tmp->color->rgba[2],
	     &tmp->angle, &tmp->rayon, &tmp->brill,
		  &tmp->special, (int *)&tmp->texture)) < 15)
    return (-1);
  set_fct_ptr(tmp, 0);
  return (0);
}

int		add_info_obj_app(char *line, t_obj *tmp, int opt)
{
  if (opt == 1)
    return (add_info_obj_app_re(line, tmp));
  if (!(tmp->color = my_xmalloc(sizeof(t_color) * 2)))
    return (-1);
  tmp->color->color = 0;
  if ((sscanf(line, OBJ_MODEL,
	     (int *)&tmp->type, &tmp->obj_pos[0],
	     &tmp->obj_pos[1], &tmp->obj_pos[2], &tmp->obj_rot[0],
	     &tmp->obj_rot[1], &tmp->obj_rot[2], (int *)&tmp->color->rgba[0],
	     (int *)&tmp->color->rgba[1], (int *)&tmp->color->rgba[2],
	     &tmp->angle, &tmp->rayon, &tmp->brill,
		  &tmp->special, (int *)&tmp->texture)) < 15)
    return (-1);
  set_fct_ptr(tmp, 0);
  redraw = 1;
  return (0);
}

int		set_second_obj_app(t_obj *objs, t_obj *tmp, char *line, int opt)
{
  objs->next = tmp;
  tmp->next = NULL;
  tmp->previous = objs;
  if (add_info_obj_app(line, tmp, opt) == -1)
    return (-1);
  return (0);
}

void		add_obj_app(char *line, t_obj *objs, int opt)
{
  t_obj		*tmp;

  while (render == 1);
  if (!(tmp = my_xmalloc(sizeof(t_obj))))
    return ;
  if (objs->next)
    {
      while (objs->next)
        objs = objs->next;
      tmp->next = NULL;
      if (add_info_obj_app(line, tmp, opt) == -1)
        return ;
      objs->next = tmp;
      tmp->previous = objs;
    }
  else if (!objs->next && !objs->color)
    {
      free(tmp);
      if (add_info_obj_app(line, objs, opt) == -1)
        return ;
    }
  else if (set_second_obj_app(objs, tmp, line, opt) == -1)
    return ;
}
