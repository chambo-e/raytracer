/*
** rotation.c for raytracer in /home/paasch_j/Dropbox/raytracer/paasch_j/raytracer
**
** Made by johan paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Mon Jun  2 22:30:12 2014 johan paasche
** Last update Sun Jun  8 16:59:16 2014 chambon emmanuel
*/

#include "client_rt.h"

void		x_rotation(t_ray *ray, t_obj *obj)
{
  double	copy[3];

  if (ray && obj->obj_rot[X] != 0 && obj->type != 2)
    {
      copy[X] = ray->v[X];
      copy[Y] = ray->v[Y];
      copy[Z] = ray->v[Z];
      ray->v[Y] = cos(obj->obj_rot[X]) * copy[Y]
	- sin(obj->obj_rot[X]) * copy[Z];
      ray->v[Z] = cos(obj->obj_rot[X]) * copy[Z]
	+ sin(obj->obj_rot[X]) * copy[Y];
    }
}

void		y_rotation(t_ray *ray, t_obj *obj)
{
  double	copy[3];

  if (ray && obj->obj_rot[Y] != 0 && obj->type != 2)
    {
      copy[0] = ray->v[0];
      copy[1] = ray->v[1];
      copy[2] = ray->v[2];
      ray->v[X] = cos(obj->obj_rot[Y]) * copy[X]
	+ sin(obj->obj_rot[Y]) * copy[Z];
      ray->v[Z] = cos(obj->obj_rot[Y]) * copy[Z]
	- sin(obj->obj_rot[Y]) * copy[X];
    }
}

void		z_rotation(t_ray *ray, t_obj *obj)
{
  double	copy[3];

  if (ray && obj->obj_rot[Z] != 0 && obj->type != 2)
    {
      copy[X] = ray->v[X];
      copy[Y] = ray->v[Y];
      copy[Z] = ray->v[Z];
      ray->v[X] = cos(obj->obj_rot[Z]) * copy[X]
	- sin(obj->obj_rot[Z]) * copy[Y];
      ray->v[Y] = cos(obj->obj_rot[Z]) * copy[Y]
	+ sin(obj->obj_rot[Z]) * copy[X];
    }
}
