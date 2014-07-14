/*
** cone.c for raytracer in /home/paasch_j/Dropbox/raytracer/paasch_j/raytracer
**
** Made by johan paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Thu May 22 23:14:52 2014 johan paasche
** Last update Sun Jun  8 09:26:47 2014 johan paasche
*/

#include "rt.h"

double		cone_equation(t_ray *ray, t_obj *obj)
{
  double	a[3];
  double	b[3];
  double	c[3];
  double	abc[3];
  double	delta;
  double	sqrtan;
  int		i;

  sqrtan = pow(tan(obj->angle), 2);
  i = 0;
  while (i < 3)
    {
      a[i] = ray->v[i] * ray->v[i];
      b[i] = ray->v[i] * ray->eye[i];
      c[i] = ray->eye[i] * ray->eye[i];
      ++i;
    }
  abc[0] = a[0] + a[1] - (a[2] / sqrtan);
  abc[1] = 2 * (b[0] + b[1] - (b[2] / sqrtan));
  abc[2] = c[0] + c[1] - ((c[2] / sqrtan) + obj->special);
  delta = (abc[1] * abc[1]) - (4 * abc[0] * abc[2]);
  return (find_k(delta, abc[0], abc[1]));
}

double		cone_normale(t_ray *ray, UNUSED t_obj *obj, t_spot *light)
{
  int		i;
  double	values[5];

  i = 0;
  init_tab(values, 0, 5);
  while (i < 2)
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
