/*
** mlx_destroy_window.c for MinilibX in
**
** Made by Charlie Root
** Login   <ol@epitech.net>
**
** Started on  Tue Mar 12 10:25:15 2002 Charlie Root
** Last update Thu May 15 12:42:32 2014 chambon emmanuel
*/


#include	"mlx_int.h"

void	destroy_img(t_img *img)
{
  if (img)
    {
      XDestroyImage(img->image);
      free(img);
    }
}

int	mlx_destroy_window(t_xvar *xvar,t_win_list *win, t_img *img)
{
  t_win_list	*w;
  t_win_list	*prev;
  t_win_list	first;

  if (!(xvar) || !(win) || !(img))
    exit(EXIT_FAILURE);
  first.next = xvar->win_list;
  prev = &first;
  w = prev->next;
  while (w)
    {
      if (w==win)
	prev->next = w->next;
      else
	prev = w;
      w = w->next;
    }
  destroy_img(img);
  xvar->win_list = first.next;
  XDestroyWindow(xvar->display,win->window);
  XFreeGC(xvar->display,win->gc);
  XCloseDisplay(xvar->display);
  free(win);
  free(xvar);
}
