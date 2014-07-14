/*
** draw_image.c for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/conf_file
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Wed May 14 21:43:47 2014 chambon emmanuel
** Last update Sun Jun  8 23:23:21 2014 chambon emmanuel
*/

#include "rt.h"

void            pxl(t_rt *rt, int x, int y, colour color)
{
  int           position;
  t_color       fragm;
  int           i;

  i = 0;
  position = x * rt->img->bpp / 8 + y * rt->img->size;
  fragm.color = color;
  if (rt->img->end == 0)
    {
      while (i < (rt->img->bpp / 8))
        {
          rt->img->data[position + i] = fragm.rgba[i];
          ++i;
        }
    }
}

void                    correct_img(t_rt *rt)
{
  t_color               color;
  int                   x;
  int                   y;
  int                   pix;

#pragma omp parallel for schedule (dynamic) private(x, y) private (color)
  for (pix = 0; pix < rt->end; pix++)
    {
      if (rt->img->data[(pix * 4) + 3] == -1)
        {
          x = pix % WINX;
          y = pix / WINX;
	  if (rt->eye->aa)
	    color.color = cast_a_ray_alias(rt, x, y);
	  else
	    color.color = get_the_scene(rt, x, y);
          pxl(rt, x, y, color.color);
          if (omp_get_thread_num() == 0)
            mlx_put_image_to_window(rt->img->mlx, rt->img->win, rt->img->img,
                                    0, 0);
        }
    }
}

void                    draw_aliasing(t_rt *rt)
{
  t_color               color;
  int                   x;
  int                   y;
  int                   pix;

#pragma omp parallel for schedule (dynamic) private(x, y) private (color)
  for (pix = rt->beg; pix < rt->end; pix++)
    {
      x = pix % WINX;
      y = pix / WINX;
      color.color = cast_a_ray_alias(rt, x, y);
      pxl(rt, x, y, color.color);
      if (omp_get_thread_num() == 0)
        mlx_put_image_to_window(rt->img->mlx, rt->img->win, rt->img->img,
                                0, 0);
    }
}

int			draw_image(t_rt *rt)
{
  t_color		color;
  int			x;
  int			y;
  int			pix;

  if (activate_client(rt->client, rt) == -1)
    return (-1);
#pragma omp parallel for schedule (dynamic) private(x, y) private (color)
  for (pix = rt->beg; pix < rt->end; pix++)
    {
      x = pix % WINX;
      y = pix / WINX;
      color.color = get_the_scene(rt, x, y);
      pxl(rt, x, y, color.color);
      if (omp_get_thread_num() == 0)
	mlx_put_image_to_window(rt->img->mlx, rt->img->win, rt->img->img,
				0, 0);
    }
  if (check_calculated(rt->img->data, rt) == -1)
    correct_img(rt);
  if (rt->eye->aa == 1)
    draw_aliasing(rt);
  if (rt->eye->filter)
    filter(rt);
  return (0);
}
