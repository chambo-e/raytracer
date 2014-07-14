/*
** set_eye.c for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Wed Apr 23 15:55:25 2014 chambon emmanuel
** Last update Sat Jul  5 21:16:20 2014 chambon emmanuel
*/

#include "rt.h"

int		set_eye_rot(char *line, t_rt *rt, int i)
{
  char		**param;

  if (!line)
    {
      rt->eye->eye_rot[0] = 0;
      rt->eye->eye_rot[1] = 0;
      rt->eye->eye_rot[2] = 0;
      return (0);
    }
  while (line[++i] != DEFINE_CHAR && line[i]);
  if (line[i])
    {
      if (!(param = my_str_to_wordtab(&line[i + 1], PARAM_CHAR)))
	return (-1);
      i = -1;
      while (param[++i])
        param[i] = epur_str(param[i]);
    }
  if (i > 3 || i == 0)
    return (print_error(WR_ARG_EYE_ROT));
  rt->eye->eye_rot[0] = atoi(param[0]);
  rt->eye->eye_rot[1] = atoi(param[1]);
  rt->eye->eye_rot[2] = atoi(param[2]);
  free_tab(param);
  return (0);
}

int		get_eye_rot(t_parse *lines, t_rt *rt)
{
  t_parse	*tmp;

  tmp = lines;
  while (tmp)
    {
      if (!(strncmp(tmp->line, "EYE_ROT", 7))
	  && (rt->eye->eye_rot[0] != -1))
	return (print_error(MULTIDEF_EYE_ROT));
      else if (!(strncmp(tmp->line, "EYE_ROT", 7)))
        {
          if (set_eye_rot(tmp->line, rt, -1) == -1)
            return (-1);
        }
      tmp = tmp->next;
    }
  if (rt->eye->eye_rot[0] == -1)
    return (set_eye_rot(NULL, rt, -1));
  return (0);
}

int		set_eye_pos(char *line, t_rt *rt)
{
  char		**param;
  int		i;

  i = 0;
  while (line[i] != DEFINE_CHAR && line[i])
    i++;
  if (line[i])
    {
      if (!(param = my_str_to_wordtab(&line[i + 1], PARAM_CHAR)))
	return (-1);
      i = -1;
      while (param[++i])
        param[i] = epur_str(param[i]);
    }
  if (i > 3 || i == 0)
    return (print_error(WR_ARG_EYE_POS));
  rt->eye->eye_pos[0] = atoi(param[0]);
  rt->eye->eye_pos[1] = atoi(param[1]);
  rt->eye->eye_pos[2] = atoi(param[2]);
  free_tab(param);
  return (0);
}

int		get_eye_pos(t_parse *lines, t_rt *rt)
{
  t_parse	*tmp;

  tmp = lines;
  while (tmp)
    {
      if (!(strncmp(tmp->line, "EYE_POS", 7)) && (rt->eye->eye_pos[0] != -1))
	return (print_error(MULTIDEF_EYE));
      else if (!(strncmp(tmp->line, "EYE_POS", 7)))
        {
          if (set_eye_pos(tmp->line, rt) == -1)
            return (-1);
        }
      tmp = tmp->next;
    }
  if (rt->eye->eye_pos[0] == -1)
    return (print_error(NO_EYE_POS));
  return (0);
}

int		get_eye(t_parse *lines, t_rt *rt)
{
  if (!(rt->eye = my_xmalloc(sizeof(t_opt))))
    return (-1);
  rt->eye->eye_pos[0] = -1;
  rt->eye->eye_rot[0] = -1;
  rt->eye->aa = -1;
  rt->eye->filter = -1;
  rt->eye->texture = -1;
  if (get_eye_pos(lines, rt) == -1)
    return (-1);
  if (get_eye_rot(lines, rt) == -1)
    return (-1);
  return (0);
}
