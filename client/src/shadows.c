/*
** shadows.c for raytracer in /home/paasch_j/Dropbox/raytracer/paasch_j/raytracer
**
** Made by johan paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Mon Jun  2 23:03:54 2014 johan paasche
** Last update Sun Jun  8 23:16:45 2014 david tran
*/

#include "client_rt.h"

void   	init_shine_vector(t_ray *shine, t_ray *ray)
{
  shine->k = -1;
  shine->x = ray->x;
  shine->y = ray->y;
  init_tab(shine->eye, 0, 3);
  init_tab(shine->p1, 0, 3);
  init_tab(shine->v, 0, 3);
  shine->color = NULL;
}

void   	get_light_vector(t_ray *shine, t_ray *ray,
			 t_spot *light, t_rt_client *rt)
{
  int  	i;

  i = 0;
  ray->p1[0] = rt->eye->eye_rot[0];
  ray->p1[1] = (WINX / 2) - ray->x - rt->eye->eye_rot[1];
  ray->p1[2] = (WINY / 2) - ray->y - rt->eye->eye_rot[2];
  while (i < 3)
    {
      ray->eye[i] = rt->eye->eye_pos[i];
      ray->v[i] = ray->p1[i];
      shine->eye[i] = ray->eye[i] + ray->k * ray->v[i];
      shine->p1[i] = light->pos[i];
      shine->v[i] = shine->eye[i] - shine->p1[i];
      ++i;
    }
}

void	set_shine_vector(t_ray *shine, t_obj *obj)
{
  shine->eye[0] -= obj->obj_pos[0];
  shine->eye[1] -= obj->obj_pos[1];
  shine->eye[2] -= obj->obj_pos[2];
  x_rotation(shine, obj);
  y_rotation(shine, obj);
  z_rotation(shine, obj);
  shine->k = (obj->k) ? obj->k(shine, obj) : -1.0;
}

colour		shadows(t_rt_client *rt, t_ray *ray, t_obj *obj)
{
  t_ray		shine;
  t_obj		*obj_list;
  t_spot	*lights;

  lights = rt->spot;
  init_shine_vector(&shine, ray);
  while (lights && lights->color)
    {
      obj_list = rt->objs;
      while (obj_list && obj_list->color)
  	{
  	  get_light_vector(&shine, ray, lights, rt);
	  set_shine_vector(&shine, obj_list);
	  if (obj_list != obj && 0.0 < shine.k && shine.k < 1.0)
  	    {
  	      ray->color->color = new_color(ray->color, 0.8);
  	      break;
  	    }
  	  obj_list = obj_list->next;
  	}
      lights = lights->next;
    }
  return (ray->color->color);
}
