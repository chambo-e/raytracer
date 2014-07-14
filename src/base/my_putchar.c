/*
** my_putchar.c for RT in /home/chambo_e/Dropbox/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Fri Apr 18 18:27:35 2014 chambon emmanuel
** Last update Wed May 14 22:07:15 2014 chambon emmanuel
*/

#include "rt.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}
