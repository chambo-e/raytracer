/*
** parse_spot.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/MUL_2013_rtracer
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Thu Jun 19 14:09:36 2014 chambon emmanuel
** Last update Sun Jul 13 22:41:26 2014 chambon emmanuel
*/

#include "rt.h"

int			add_info_spot_app_str(char *line, t_spot *tmp)
{
  if (!(tmp->color = my_xmalloc(sizeof(t_color) * 2)))
    return (-1);
  tmp->color->color = 0;
  tmp->type = 0;
  if (sscanf(line, S_MODEL, &tmp->pos[0],
             &tmp->pos[1], &tmp->pos[2], (int *)&tmp->color->rgba[0],
	     (int *)&tmp->color->rgba[1], (int *)&tmp->color->rgba[2]) < 6)
    return (-1);
  return (0);
}

int			add_info_spot_app(char *line, t_spot *tmp, int flag)
{
  if (flag == 1)
    return (add_info_spot_app_str(line, tmp));
  if (!(tmp->color = my_xmalloc(sizeof(t_color) * 2)))
    return (-1);
  tmp->color->color = 0;
  if (sscanf(line, SPOT_MODEL, &tmp->pos[0],
             &tmp->pos[1], &tmp->pos[2], (int *)&tmp->color->rgba[0],
	     (int *)&tmp->color->rgba[1], (int *)&tmp->color->rgba[2]) < 6)
    return (-1);
  redraw = 1;
  return (0);
}

int			set_second_spot_app(t_spot *spot, t_spot *tmp, char *line, int flag)
{
  spot->next = tmp;
  tmp->next = NULL;
  tmp->previous = spot;
  if (add_info_spot_app(line, tmp, flag) == -1)
    return (-1);
  return (0);
}

void			add_spot_app(char *line, t_spot *spot, int flag)
{
  t_spot		*tmp;

  while (render == 1);
  if (!(tmp = my_xmalloc(sizeof(t_spot))))
    return ;
  if (spot->next)
    {
      while (spot->next)
        spot = spot->next;
      tmp->next = NULL;
      if (add_info_spot_app(line, tmp, flag) == -1)
        return ;
      spot->next = tmp;
      tmp->previous = spot;
    }
  else if (!spot->next && !spot->color)
    {
      free(tmp);
      if (add_info_spot_app(line, spot, flag) == -1)
        return ;
    }
  else if (set_second_spot_app(spot, tmp, line, flag) == -1)
    return ;
}
