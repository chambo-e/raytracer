/*
** init_mlx.c for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/conf_file
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Wed May 14 21:48:42 2014 chambon emmanuel
** Last update Thu Jun 19 14:24:45 2014 chambon emmanuel
*/

#include "rt.h"

int		handle_expose(t_rt *rt)
{
  mlx_put_image_to_window(rt->img->mlx, rt->img->win, rt->img->img, 0, 0);
  return (0);
}

int		mlx_node(t_rt *rt)
{
  if (init_mlx(rt)== -1)
    return (-1);
  render_image(rt);
  mlx_key_hook(rt->img->win, &handle_key, rt);
  mlx_expose_hook(rt->img->win, &handle_expose, rt);
  mlx_loop_hook(rt->img->mlx, redraw_callback, rt);
  mlx_loop(rt->img->mlx);
  return (0);
}

int		set_unused_data(char *data, t_rt *rt)
{
  int		i;

  i = 0;
  while (i < (WINX * WINY))
    {
      data[i * 4] = 0;
      data[i * 4 + 1] = 0;
      data[i * 4 + 2] = 0;
      data[i * 4 + 3] = -1;
      i++;
    }
  return (0);
}

int		init_mlx(t_rt *rt)
{
  if (!(rt->img->mlx = mlx_init())
      || (!(rt->img->win =
	    mlx_new_window(rt->img->mlx, WINX, WINY, "RAYTRACER")))
      || (!(rt->img->img = mlx_new_image(rt->img->mlx, WINX, WINY)))
      || (!(rt->img->data = mlx_get_data_addr(rt->img->img, &rt->img->bpp,
					      &rt->img->size, &rt->img->end))))
    return (print_error(NO_MLX));
  memset(rt->img->data, -1, (WINX + 32) * WINY * 4 - 1);
  set_unused_data(rt->img->data, rt);
  return (0);
}
