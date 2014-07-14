/*
** aliasing.c for raytracer in /home/tran_0/Dropbox/raytracer/chambo_e/link_folder
**
** Made by david tran
** Login   <tran_0@epitech.net>
**
** Started on  Sat Jun  7 20:45:42 2014 david tran
** Last update Sun Jun  8 23:23:19 2014 david tran
*/

#include "rt.h"

int	transform_pixel(int red, int green, int blue)
{
  int	color;

  color = 0;
  color <<= 8;
  color |= blue / 64;
  color <<= 8;
  color |= green / 64;
  color <<= 8;
  color |= red / 64;
  return (color);
}

void		calc_final_alias(t_color *rayco, int *blue, int *red, int *green)
{
  *red += rayco->rgba[0];
  *green += rayco->rgba[1];
  *blue += rayco->rgba[2];
}

void		init_alias(t_rt *rt, t_ray *ray)
{
  if (!ray || !rt)
    return;
  ray->k = 1e6;
  ray->color->color = 0;
  init_tab(ray->eye, 0, 3);
  init_tab(ray->p1, 0, 3);
  init_tab(ray->v, 0, 3);
}

void		calc_color_alias(t_rt *img, t_ray *ray, t_obj *tmp)
{
  t_obj		*obj_result;

  init_alias(img, ray);
  obj_result = NULL;
  while (img && ray && tmp && tmp->color)
    {
      assign_ray(img, ray, tmp);
      obj_result = cast_ray(ray, tmp, obj_result);
      tmp = tmp->next;
    }
  if (obj_result != NULL && obj_result->color)
    {
      assign_ray(img, ray, obj_result);
      obj_result->color->color = perlin_color(img, ray, obj_result);
      lighting(ray, obj_result, img->spot);
      shadows(img, ray, obj_result);
    }
}

int		cast_a_ray_alias(t_rt *img, int x, int y)
{
  t_ray		ray;
  t_color	color;
  t_obj		*tmp;
  int		colour[3];

  colour[0] = 0;
  colour[1] = 0;
  colour[2] = 0;
  ray.color = &color;
  init_ray(img, &ray, x, y);
  while (img && ray.x < x + 1)
    {
      ray.y = (double)y;
      while (ray.y < y + 1)
  	{
	  tmp = img->objs;
	  calc_color_alias(img, &ray, tmp);
	  calc_final_alias(ray.color, &colour[2], &colour[0], &colour[1]);
    	  ray.y += 0.125;
    	}
      ray.x += 0.125;
    }
  return (transform_pixel(colour[0], colour[1], colour[2]));
}
