/*
** sphere.c for raytracer in /home/paasch_j/Dropbox/raytracer/paasch_j/raytracer
**
** Made by johan paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Thu May 22 22:53:14 2014 johan paasche
** Last update Fri Jun  6 22:15:21 2014 johan paasche
*/

#include "rt.h"

double		sphere_equation(t_ray *ray, t_obj *obj)
{
  int		i;
  double	values[4];

  i = 0;
  init_tab(values, 0, 4);
  while (i < 3)
    {
      values[0] += ray->v[i] * ray->v[i];
      values[1] += ray->v[i] * ray->eye[i];
      values[2] += ray->eye[i] * ray->eye[i];
      ++i;
    }
  values[1] *= 2;
  values[2] -= (obj->rayon * obj->rayon);
  values[3] = (values[1] * values[1]) - (4 * values[0] * values[2]);
  return (find_k(values[3], values[0], values[1]));
}

double		sphere_normale(t_ray *ray, UNUSED t_obj *obj, t_spot *light)
{
  int		i;
  double	values[5];

  i = 0;
  init_tab(values, 0, 5);
  while (i < 3)
    {
      values[0] = ray->eye[i] + ray->k * ray->v[i];
      values[1] = ray->eye[i] + ray->k * ray->v[i] - light->pos[i];
      values[2] += pow(values[0], 2);
      values[3] += pow(values[1], 2);
      values[4] += values[0] * values[1];
      ++i;
    }
  return (values[4] / (sqrt(values[2]) * sqrt(values[3])));
}
