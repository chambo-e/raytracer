/*
** lines_c.c for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Wed Apr 23 15:53:45 2014 chambon emmanuel
** Last update Wed May 14 22:05:29 2014 chambon emmanuel
*/

#include "rt.h"

void		init_lines(t_parse *lines)
{
  lines->line = NULL;
  lines->next = NULL;
}

int		add_second(t_parse *lines, t_parse *tmp, char *line)
{
  lines->next = tmp;
  if (!(tmp->line = strdup(line)))
    return (-1);
  tmp->next = NULL;
  return (0);
}

int		add_line(t_parse *lines, char *line)
{
  t_parse	*tmp;

  if (!(tmp = my_xmalloc(sizeof(t_parse))))
    return (-1);
  if (lines->next)
    {
      while (lines->next)
        lines = lines->next;
      if (!(tmp->line = strdup(line)))
        return (-1);
      tmp->next = NULL;
      lines->next = tmp;
    }
  else if (!lines->next && !lines->line)
    {
      free(tmp);
      if (!(lines->line = strdup(line)))
        return (-1);
    }
  else if (add_second(lines, tmp, line) == -1)
    return (-1);
  return (0);
}
