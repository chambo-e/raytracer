/*
** my_putstr.c for RT in /home/chambo_e/Dropbox/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Fri Apr 18 18:28:13 2014 chambon emmanuel
** Last update Wed May 14 22:06:47 2014 chambon emmanuel
*/

#include "rt.h"

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}
