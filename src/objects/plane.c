/*
** plane.c for raytracer in /home/paasch_j/Dropbox/raytracer/paasch_j/raytracer
**
** Made by johan paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Thu May 22 20:54:02 2014 johan paasche
** Last update Sun Jun  8 23:25:06 2014 chambon emmanuel
*/

#include "rt.h"

double		plane_equation(t_ray *ray, UNUSED t_obj *obj)
{
  return (-1 * (ray->eye[2] / ray->v[2]));
}

double		plane_normale(t_ray *ray, t_obj *obj, t_spot *light)
{
  int		i;
  double	values[5];

  init_tab(values, 0, 5);
  i = 0;
  while (i < 3)
    {
      values[0] = -light->pos[i];
      if (i == Z)
	values[0] = (1000 - obj->obj_pos[Z]);
      values[1] = ray->eye[i] + ray->k * ray->v[i] - light->pos[i];
      values[2] += pow(values[0], 2);
      values[3] += pow(values[1], 2);
      values[4] += values[0] * values[1];
      ++i;
      }
  return (values[4] / (sqrt(values[2]) * sqrt(values[3])));
}
