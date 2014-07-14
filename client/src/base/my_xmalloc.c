/*
** my_xmalloc.c for Corewar in /home/chambo_e/Dropbox/Corewar/build/asm/src/base
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun Apr 13 19:14:23 2014 chambon emmanuel
** Last update Sat May 31 02:38:39 2014 chambon emmanuel
*/

#include "client_rt.h"

void	*my_xmalloc(size_t size)
{
  char	*dest;

  dest = malloc(size);
  if (dest == NULL)
    fprintf(stderr, MALLOC_ERROR);
  return (dest);
}
