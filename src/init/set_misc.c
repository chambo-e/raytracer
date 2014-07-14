/*
** set_misc.c for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sat Apr 26 15:14:06 2014 chambon emmanuel
** Last update Fri Jun  6 11:18:33 2014 chambon emmanuel
*/

#include "rt.h"

int		set_default_eye_rot(t_rt *rt)
{
  rt->eye->eye_rot[0] = 0;
  rt->eye->eye_rot[1] = 0;
  rt->eye->eye_rot[2] = 0;
  return (0);
}

char		get_type(char *line)
{
  int		i;

  i = 0;
  while (line[i] != DEFINE_CHAR && line[i])
    if (check_define(&i, line) == -1)
      return (-1);
  if (!(strcmp(epur_str(&line[i + 1]), PL)))
    return (PLAN_TYPE);
  else if (!(strcmp(epur_str(&line[i + 1]), SPH)))
    return (SPHERE_TYPE);
  else if (!(strcmp(epur_str(&line[i + 1]), CO)))
    return (CONE_TYPE);
  else if (!(strcmp(epur_str(&line[i + 1]), CYL)))
    return (CYLINDRE_TYPE);
  else if (!(strcmp(epur_str(&line[i + 1]), TO)))
    return (TORE_TYPE);
  else if (!(strcmp(epur_str(&line[i + 1]), CT)))
    return (CUBE_TYPE);
  return (print_error(WR_TYPE));
}

int		get_pos(char *line, t_obj *tmp)
{
  char		**pos;
  int		r;

  if (!(pos = my_str_to_wordtab(line, PARAM_CHAR)))
    return (-1);
  if (strlen_tab(pos) != 3)
    {
      free_tab(pos);
      return (print_error(WR_POS));
    }
  free_tab(pos);
  if ((r = sscanf(epur_str(line), "%lf,%lf,%lf", &tmp->obj_pos[0],
		  &tmp->obj_pos[1], &tmp->obj_pos[2])) != 3)
    return (print_error(WR_POS));
  return (0);
}

int		get_rot(char *line, t_obj *tmp)
{
  char		**rot;
  int		r;

  if (!(rot = my_str_to_wordtab(line, PARAM_CHAR)))
    return (-1);
  if (strlen_tab(rot) != 3)
    {
      free_tab(rot);
      return (print_error(WR_ROT));
    }
  free_tab(rot);
  if ((r = sscanf(epur_str(line), "%lf,%lf,%lf", &tmp->obj_rot[0],
		  &tmp->obj_rot[1], &tmp->obj_rot[2])) != 3)
    return (print_error(WR_ROT));
  return (0);
}

t_color		*get_color(char *line)
{
  char		**col;
  t_color	*color;

  if (!(col = my_str_to_wordtab(line, PARAM_CHAR)))
    return (NULL);
  if (strlen_tab(col) != 3)
    {
      free_tab(col);
      print_error(WR_COL);
      return (NULL);
    }
  if (!(color = my_xmalloc(sizeof(t_color))))
    return (NULL);
  bzero(color, 4);
  if (set_color(color, col) == -1)
    return (NULL);
  free_tab(col);
  return (color);
}
