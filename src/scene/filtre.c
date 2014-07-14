/*
** filtre.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/paasch_j/MUL_2013_rtracer
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun Jun  8 20:11:48 2014 chambon emmanuel
** Last update Sun Jun  8 21:43:47 2014 chambon emmanuel
*/

#include "rt.h"

void		negative(t_rt *rt)
{
  int		i;

  i = 0;
  while (i < (rt->winsize_x * rt->winsize_y * 4))
    {
      rt->img->data[i] = 255 - rt->img->data[i];
      i++;
    }
}

void		black_and_white(t_rt *rt)
{
  int		i;
  int		gris;

  i = 0;
  while (i < (rt->winsize_x * rt->winsize_y * 4))
    {
      gris = rt->img->data[i] + rt->img->data[i + 1] + rt->img->data[i + 2];
      gris = gris / 3;
      rt->img->data[i++] = gris;
      rt->img->data[i++] = gris;
      rt->img->data[i++] = gris;
      i = i + 1;
    }
}

void		sepia(t_rt *rt, int i)
{
  while (i < (rt->winsize_x * rt->winsize_y * 4))
    {
      rt->img->data[i] = rt->img->data[i] * 0.393 + rt->img->data[i + 1]
	* 0.769 + rt->img->data[i + 2] * 0.189;
      if ((unsigned char)rt->img->data[i] > 254)
	rt->img->data[i] = (unsigned char)255;
      i++;
      rt->img->data[i] = rt->img->data[i - 1] * 0.349 + rt->img->data[i]
	* 0.686 + rt->img->data[i + 1] * 0.168;
      if ((unsigned char)rt->img->data[i] > 254)
        rt->img->data[i] = (unsigned char)255;
      i++;
      rt->img->data[i] = rt->img->data[i - 2] * 0.272 + rt->img->data[i - 1]
	* 0.534 + rt->img->data[i] * 0.131;
      if ((unsigned char)rt->img->data[i] > 254)
        rt->img->data[i] = (unsigned char)255;
      i++;
      i++;
    }
}

void		filter(t_rt *rt)
{
  if (rt->eye->filter == 3)
    negative(rt);
  else if (rt->eye->filter == 2)
    black_and_white(rt);
  else if (rt->eye->filter == 1)
    sepia(rt, 0);
}
