/*
** get_opt.c for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Wed Apr 23 16:00:49 2014 chambon emmanuel
** Last update Sat Jul  5 21:19:40 2014 chambon emmanuel
*/

#include "rt.h"

int		check_define(int *i, char *line)
{
  if (!line[*i + 1])
    return (print_error(MISSING_SEP));
  (*i)++;
  return (0);
}

int		get_aa(t_parse *lines, t_rt *rt, int i)
{
  t_parse	*tmp;

  tmp = lines;
  while (tmp)
    {
      if ((!(strncmp(tmp->line, "AA", 2))) && (rt->eye->aa != -1))
	return (print_error(MULTIDEF_AA));
      else if (!(strncmp(tmp->line, "AA", 2)))
        {
          while (tmp->line[i] != DEFINE_CHAR && tmp->line[i])
	    if (check_define(&i, tmp->line) == -1)
	      return (-1);
          rt->eye->aa = atoi(&tmp->line[i + 1]);
          if (rt->eye->aa > 1 || rt->eye->aa < 0)
            return (print_error(WRONG_AA));
        }
      tmp = tmp->next;
    }
  if (rt->eye->aa == -1)
    rt->eye->aa = 0;
  return (0);
}

int		get_filter(t_parse *lines, t_rt *rt, int i)
{
  t_parse	*tmp;

  tmp = lines;
  while (tmp)
    {
      if ((!(strncmp(tmp->line, "FILTER", 6))) && (rt->eye->filter != -1))
	return (print_error(MULTIDEF_FILTER));
      else if (!(strncmp(tmp->line, "FILTER", 6)))
        {
          while (tmp->line[i] != DEFINE_CHAR && tmp->line[i])
	    if (check_define(&i, tmp->line) == -1)
	      return (-1);
          rt->eye->filter = atoi(&tmp->line[i + 1]);
          if (rt->eye->filter > FILTER_MAX || rt->eye->filter < 0)
            return (print_error(WRONG_FILTER));
        }
      tmp = tmp->next;
    }
  if (rt->eye->filter == -1)
    rt->eye->filter = 0;
  return (0);
}

int		get_opt(t_parse *lines, t_rt *rt)
{
  if ((get_aa(lines, rt, 0) == -1)
      || (get_filter(lines, rt, 0) == -1)
      || (get_texture(lines, rt, 0) == -1)
      || check_texture_img(rt))
    return (-1);
  return (0);
}
