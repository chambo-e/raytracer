/*
** perlin_init.c for rt in /home/tran_0/Dropbox/raytracer/tran_0/raytracer/srcs
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sat Jun  7 01:39:28 2014 david tran
** Last update Sun Jun  8 22:29:47 2014 david tran
*/

#include "client_rt.h"

t_perlin	pertext[] =
  {
    {&get_pixel},
    {&get_pixel_wood},
    {&get_pixel_marbr},
    {&get_pixel_sky},
  };

int	init_func_perlin(t_rt_client *rt)
{
  rt->N2D.len_max = (int) ceil((WINX + WINY) * pow(2, OCTAVES - 1) / PAS);
  rt->N2D.high_max = (int) ceil((WINX + WINY) * pow(2, OCTAVES - 1) / PAS);
  if (!(rt->N2D.vals = malloc(sizeof(double) * (rt->N2D.high_max
						* rt->N2D.len_max + 3))))
    return (-1);
  if (initBruit2D(&rt->N2D))
    return (-1);
  return (0);
}

int		perlin_color(t_rt_client *rt, t_ray *ray, t_obj *obj)
{
  ray->color->color = obj->color->color;
  if (rt->eye->texture == 0 && obj->texture == 0)
    return (ray->color->color);
  if (obj && obj->texture != 0)
    return (pertext[obj->texture - 1].pixel(rt, ray));
  else if (rt->eye->texture != 0)
    return (pertext[rt->eye->texture - 1].pixel(rt, ray));
  return (ray->color->color);
}
