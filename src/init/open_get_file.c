/*
** open_get_file.c for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Wed Apr 23 15:46:40 2014 chambon emmanuel
** Last update Sat May 31 02:50:55 2014 chambon emmanuel
*/

#include "rt.h"

int		open_file(char *file)
{
  int		fd;

  if (strlen(file) < 5 || (strcmp(&file[strlen(file) - 5], ".conf")))
    return (print_error(WRONG_EXTENSION));
  if ((fd = open(file, O_RDONLY)) == -1)
    {
      print_error(file);
      return (print_error(NO_FILE));
    }
  return (fd);
}

void		clean_comment(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == COMMENT_CHAR)
        {
          str[i] = 0;
          return ;
        }
      i++;
    }
}

int		get_lines(t_parse *lines, int fd)
{
  char		*line;

  init_lines(lines);
  while ((line = get_next_line(fd)))
    {
      clean_comment(line);
      line = epur_str(line);
      if (line && strlen(line) > 0)
        {
          if (add_line(lines, line) == -1)
            return (-1);
        }
      free(line);
    }
  return (0);
}

t_parse		*parse_file(char *file)
{
  int		fd;
  t_parse	*lines;

  if (((fd = open_file(file)) == -1)
      || (!(lines = my_xmalloc(sizeof(t_parse))))
      || (get_lines(lines, fd) == -1))
    return (NULL);
  return (lines);
}
