/*
** print_error.c for RT in /home/chambo_e/Dropbox/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Fri Apr 18 18:19:11 2014 chambon emmanuel
** Last update Fri Jun  6 11:41:42 2014 chambon emmanuel
*/

#include "rt.h"

int	print_error(char *error)
{
  fprintf(stderr, "ERROR : %s", error);
  return (-1);
}
