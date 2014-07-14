/*
** print_usage.c for RT in /home/chambo_e/Dropbox/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Fri Apr 18 18:23:24 2014 chambon emmanuel
** Last update Mon Jun  2 21:59:14 2014 chambon emmanuel
*/

#include "rt.h"

int		print_usage(char *exe)
{
  fprintf(stderr, "USAGE : \"%s path/to/.conf/file [--output=xxx.bmp/.ppm]\n",
	  exe);
  return (-1);
}
