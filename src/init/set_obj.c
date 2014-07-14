/*
** set_obj.c for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Wed Apr 23 23:18:34 2014 chambon emmanuel
** Last update Sun Jul 13 22:49:47 2014 chambon emmanuel
*/

#include "rt.h"

int		get_rayon_angle(char *line, t_obj *tmp)
{
  char		**ar;

  if (!(ar = my_str_to_wordtab(line, PARAM_CHAR)))
    return (-1);
  if (strlen_tab(ar) != 2)
    {
      free_tab(ar);
      return (print_error(WR_AR));
    }
  free_tab(ar);
  if ((sscanf(epur_str(line), "%lf,%lf", &tmp->rayon, &tmp->angle)) != 2)
    return (print_error(WR_AR));
  return (0);
}

int		get_misc(char *line, t_obj *tmp)
{
  char		**misc;

  if (!(misc = my_str_to_wordtab(line, PARAM_CHAR)))
    return (-1);
  if (strlen_tab(misc) != 3)
    {
      free_tab(misc);
      return (print_error(WR_MISC));
    }
  free_tab(misc);
  if ((sscanf(epur_str(line), "%lf, %d, %lf", &tmp->special,
		  (int *)&tmp->texture, &tmp->brill)) != 3)
    return (print_error(WR_MISC));
  if (tmp->texture < 0 || tmp->texture > TEXTURE_MAX)
    return (print_error(WR_TEXTURE));
  if (tmp->special > INT_MAX || tmp->special < INT_MIN)
    return (print_error(WR_SPECIAL));
  if (tmp->brill < 0 || tmp->brill > 1)
    return (print_error(WR_BRILL));
  return (0);
}

int		set_objs(t_parse *lines, t_rt *rt)
{
  t_parse	*tmp;

  tmp = lines;
  while (tmp)
    {
      if (!(strncmp(tmp->line, "OBJ", 3)))
	if (add_obj(tmp, rt->objs) == -1)
	  return (-1);
      tmp = tmp->next;
    }
  return (0);
}

int		get_obj(t_parse *lines, t_rt *rt)
{
  if (!(rt->objs = my_xmalloc(sizeof(t_obj))))
      return (-1);
  rt->objs->type = -1;
  rt->objs->obj_pos[0] = 0;
  rt->objs->obj_rot[0] = 0;
  rt->objs->color = NULL;
  rt->objs->brill = 0;
  rt->objs->texture = 0;
  rt->objs->next = NULL;
  rt->objs->previous = NULL;
  if (set_objs(lines, rt) == -1)
    return (-1);
  return (0);
}
