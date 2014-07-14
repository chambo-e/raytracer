/*
** set_window.c for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Wed Apr 23 15:58:50 2014 chambon emmanuel
** Last update Fri Jun  6 22:46:28 2014 chambon emmanuel
*/

#include "rt.h"

int		set_window(char *line, t_rt *rt)
{
  char		**param;
  int		i;

  i = 0;
  while (line[i] && line[i] != DEFINE_CHAR)
    i++;
  if (line[i])
    {
      if (!(param = my_str_to_wordtab(&line[i + 1], PARAM_CHAR)))
	return (-1);
      i = -1;
      while (param[++i])
        param[i] = epur_str(param[i]);
    }
  if (i > 2 || i == 0)
    return (print_error(WR_ARG_WINDOW));
  if ((rt->winsize_x = atoi(param[0])) < 25)
    return (print_error(WR_WINX));
  if ((rt->winsize_y = atoi(param[1])) < 25)
    return (print_error(WR_WINY));
  free_tab(param);
  return (0);
}

int		get_window(t_parse *lines, t_rt *rt)
{
  t_parse	*tmp;

  tmp = lines;
  while (tmp && tmp->line)
    {
      if ((!(strncmp(tmp->line, "WINDOW", 6))) && (rt->winsize_x != -1))
	return (print_error(MULTIDEF_WINDOW));
      else if (!(strncmp(tmp->line, "WINDOW", 6)))
        {
          if (set_window(tmp->line, rt) == -1)
            return (-1);
        }
      tmp = tmp->next;
    }
  if (rt->winsize_x == -1)
    return (print_error(NO_WINDOW));
  return (0);
}
