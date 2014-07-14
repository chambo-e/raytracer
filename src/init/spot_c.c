/*
** spot_l.c for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Wed Apr 23 21:35:05 2014 chambon emmanuel
** Last update Sun Jun  8 17:16:40 2014 chambon emmanuel
*/

#include "rt.h"

int			set_color(t_color *color, char **col)
{
  int			i;

  i = 0;
  while (col[i])
    {
      if (atoi(col[i]) > 255 || atoi(col[i]) < 0)
        return (print_error(COL_VALUE_MAX));
      i++;
    }
  color->rgba[0] = atoi(col[0]);
  color->rgba[1] = atoi(col[1]);
  color->rgba[2] = atoi(col[2]);
  color->rgba[3] = 0;
  return (0);
}

int			check_color(t_spot *spot, char **param)
{
  int			i;

  i = 1;
  while (i < 4)
    {
      spot->pos[i - 1] = atof(param[i]);
      i++;
    }
  if (!(spot->color = my_xmalloc(sizeof(t_color))))
    return (-1);
  if (set_color(spot->color, &param[4]) == -1)
    {
      free_tab(param);
      return (-1);
    }
  free_tab(param);
  return (0);
}

int			add_info_spot(char *line, t_spot *spot, int i)
{
  char			**param;

  while (line[i] != DEFINE_CHAR && line[i])
    if (check_define(&i, line) == -1)
      return (-1);
  if (!(param = my_str_to_wordtab(epur_str(&line[i + 1]), PARAM_CHAR)))
    return (-1);
  if (strlen_tab(param) != 7)
    return (print_error(WR_ARG_SPOT));
  if ((spot->type = atoi(param[0])) > MAX_LIGHT)
    {
      fprintf(stderr, LIGHT_MAX, MAX_LIGHT);
      return (-1);
    }
  return (check_color(spot, param));
}

int			set_second_spot(t_spot *spot, t_spot *tmp, char *line)
{
  spot->next = tmp;
  tmp->next = NULL;
  tmp->previous = spot;
  if (add_info_spot(line, tmp, 0) == -1)
    return (-1);
  return (0);
}

int			add_spot(char *line, t_spot *spot)
{
  t_spot		*tmp;

  if (!(tmp = my_xmalloc(sizeof(t_spot))))
    return (-1);
  if (spot->next)
    {
      while (spot->next)
        spot = spot->next;
      tmp->next = NULL;
      if (add_info_spot(line, tmp, 0) == -1)
        return (-1);
      spot->next = tmp;
      tmp->previous = spot;
    }
  else if (!spot->next && !spot->color)
    {
      free(tmp);
      if (add_info_spot(line, spot, 0) == -1)
        return (-1);
    }
  else if (set_second_spot(spot, tmp, line) == -1)
    return (-1);
  return (0);
}
