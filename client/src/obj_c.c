/*
** obj_c.c for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sat Apr 26 15:23:41 2014 chambon emmanuel
** Last update Sun Jun  8 00:53:24 2014 david tran
*/

#include "client_rt.h"

int             set_fct_ptr(t_obj *obj, int mode)
{
  static double (**equation_array)() = NULL;
  static double (**normale_array)() = NULL;

  if (mode == 1)
    {
      if (equation_array)
	free(equation_array);
      if (normale_array)
	free(normale_array);
      return (0);
    }
  if (normale_array == NULL)
    equation_array = set_equation_array();
  if (normale_array == NULL)
    normale_array = set_normale_array();
  if (obj->type > 0)
    {
      obj->k = equation_array[(int)obj->type];
      obj->cos = normale_array[(int)obj->type];
      return (0);
    }
  return (-1);
}
