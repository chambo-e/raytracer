/*
** obj_c.c for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sat Apr 26 15:23:41 2014 chambon emmanuel
** Last update Sun Jul 13 22:48:30 2014 chambon emmanuel
*/

#include "rt.h"

int             set_fct_ptr(t_obj *obj, int mode)
{
  static double (**equation_array)() = NULL;
  static double (**normale_array)() = NULL;

  if (mode == 1)
    {
      if (equation_array)
	free(equation_array);
      if (normale_array)
	free(normale_array);
      return (0);
    }
  if (normale_array == NULL)
    equation_array = set_equation_array();
  if (normale_array == NULL)
    normale_array = set_normale_array();
  if (obj->type > 0)
    {
      obj->k = equation_array[(int)obj->type];
      obj->cos = normale_array[(int)obj->type];
      return (0);
    }
  return (print_error("Invalid OBJ type.\n"));
}

int		add_info_obj(t_parse *line, t_obj *tmp)
{
  if ((tmp->type = get_type(line->line)) == -1)
    return (-1);
  tmp->k = NULL;
  tmp->cos = NULL;
  if (set_fct_ptr(tmp, 0) == -1)
    return (-1);
  line = line->next;
  if (get_pos(line->line, tmp) == -1)
    return (-1);
  line = line->next;
  if (get_rot(line->line, tmp) == -1)
    return (-1);
  line = line->next;
  if (get_rayon_angle(line->line, tmp) == -1)
    return (-1);
  line = line->next;
  if (!(tmp->color = get_color(line->line)))
    return (-1);
  line = line->next;
  if (get_misc(line->line, tmp) == -1)
    return (-1);
  return (0);
}

int		set_second_obj(t_obj *objs, t_obj *tmp, t_parse *line)
{
  objs->next = tmp;
  tmp->next = NULL;
  tmp->previous = objs;
  if (add_info_obj(line, tmp) == -1)
    return (-1);
  return (0);
}

int		add_obj(t_parse *line, t_obj *objs)
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
