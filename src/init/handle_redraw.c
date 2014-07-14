/*
** handle_redraw.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/MUL_2013_rtracer
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Thu Jun 19 14:23:48 2014 chambon emmanuel
** Last update Thu Jun 19 14:25:21 2014 chambon emmanuel
*/

#include "rt.h"

void		render_image(t_rt *rt)
{
  render = 1;
  draw_image(rt);
  render = 0;
}

int		redraw_callback(t_rt *rt)
{
  if (redraw == 1)
    {
      render_image(rt);
      redraw = 0;
    }
  return (0);
}
