/*
** rainbow.c for raytracer in /home/paasch_j/Dropbox/raytracer/paasch_j/raytracer
**
** Made by johan paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Thu May 29 14:11:47 2014 johan paasche
** Last update Sun Jun  8 16:59:30 2014 chambon emmanuel
*/

#include "client_rt.h"

colour		new_color(t_color *base_color, double coeff)
{
  int		i;
  double	tmp;
  t_color	new_color;

  i = 0;
  while (i < 4)
    {
      tmp = (double)base_color->rgba[i] * coeff;
      if (tmp > 255)
	tmp = 255;
      new_color.rgba[i] = (unsigned char)tmp;
      ++i;
    }
  return (new_color.color);
}

colour		shining(t_color *ray_color, t_color *light_color,
			double shine, double cos)
{
  t_color	result;
  double	tmp;
  int		i;

  if (shine == 0)
    return (ray_color->color);
  i = 0;
  while (i < 4)
    {
      tmp = shine * (double)light_color->rgba[i] * cos;
      result.rgba[i] = (1 - shine) * ray_color->rgba[i] + tmp;
      ++i;
    }
  return (result.color);
}
