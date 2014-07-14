/*
** get_next_line.c for Corewar in /home/chambo_e/Dropbox/Corewar/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun Mar 30 19:38:38 2014 chambon emmanuel
** Last update Wed May 14 22:06:52 2014 chambon emmanuel
*/

#include "rt.h"

void		gtnxln(char *file, int *x, size_t *i)
{
  file[*x] = 0;
  *x = 0;
  while (file[*x] != '\n' && file[*x])
    {
      (*i)++;
      (*x)++;
    }
}

char		*get_next_line(int fd)
{
  char		file[BUFF_SIZE];
  char		*ret;
  static size_t	i = 0;
  int		x;

  x = 0;
  if (fd == -1)
    {
      i = 0;
      return (NULL);
    }
  if (lseek(fd, i, SEEK_SET) == -1)
    return (NULL);
  if ((x = read(fd, file, BUFF_SIZE)) <= 0)
    {
      i = 0;
      return (NULL);
    }
  gtnxln(file, &x, &i);
  if (!(ret = my_xmalloc(sizeof(char) * (x + 1))))
    exit(EXIT_FAILURE);
  ret[x] = 0;
  ret = strncpy(ret, file, x);
  i++;
  return (ret);
}
