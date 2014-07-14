/*
** scene.c for raytracer in /home/paasch_j/Dropbox/raytracer/paasch_j/raytracer
**
** Made by johan paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Tue May 27 14:33:03 2014 johan paasche
** Last update Wed Jun 18 02:04:47 2014 johan paasche
*/

#include "client_rt.h"

void		init_ray(t_rt_client *rt, t_ray *ray, int x, int y)
{
  if (!ray || !rt)
    return;
  ray->x = x;
  ray->y = y;
  ray->k = 1e6;
  ray->color->color = 0;
  init_tab(ray->eye, 0, 3);
  init_tab(ray->p1, 0, 3);
  init_tab(ray->v, 0, 3);
}

void		assign_ray(t_rt_client *rt, t_ray *ray, t_obj *obj)
{
  if (!rt || !ray || !obj)
    return ;
  ray->eye[0] = rt->eye->eye_pos[0];
  ray->eye[1] = rt->eye->eye_pos[1];
  ray->eye[2] = rt->eye->eye_pos[2];
  ray->p1[0] = rt->eye->eye_rot[0];
  ray->p1[1] = (WINX / 2) - ray->x - rt->eye->eye_rot[1];
  ray->p1[2] = (WINY / 2) - ray->y - rt->eye->eye_rot[2];
  ray->v[0] = ray->p1[0];
  ray->v[1] = ray->p1[1];
  ray->v[2] = ray->p1[2];
  ray->eye[0] -= obj->obj_pos[0];
  ray->eye[1] -= obj->obj_pos[1];
  ray->eye[2] -= obj->obj_pos[2];
  x_rotation(ray, obj);
  y_rotation(ray, obj);
  z_rotation(ray, obj);
}

t_obj  		*cast_ray(t_ray *ray, t_obj *obj, t_obj *current_obj)
{
  double	k;

  k = -1;
  if (obj && obj->k)
    k = obj->k(ray, obj);
  if (k > LOW && k < ray->k)
    {
      ray->k = k;
      ray->color->color = obj->color->color;
      return (obj);
    }
  return (current_obj);
}

colour		get_the_scene(t_rt_client *rt, int x, int y)
{
  t_ray		ray;
  t_color	color;
  t_obj		*tmp;
  t_obj		*obj_result;

  tmp = rt->objs;
  obj_result = NULL;
  ray.color = &color;
  init_ray(rt, &ray, x, y);
  while (rt && tmp && tmp->color)
    {
      assign_ray(rt, &ray, tmp);
      obj_result = cast_ray(&ray, tmp, obj_result);
      tmp = tmp->next;
    }
  if (obj_result && obj_result->color)
    {
      assign_ray(rt, &ray, obj_result);
      obj_result->color->color = perlin_color(rt, &ray, obj_result);
      lighting(&ray, obj_result, rt->spot);
      shadows(rt, &ray, obj_result);
    }
  return (ray.color->color);
}
