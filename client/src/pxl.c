/*
** pxl.c for rt in /home/tran_0/Dropbox/raytracer/chambo_e/link_folder/client/src
**
** Made by david tran
** Login   <tran_0@epitech.net>
**
** Started on  Sat Jun  7 22:16:03 2014 david tran
** Last update Sun Jun  8 14:17:42 2014 johan paasche
*/

#include "client_rt.h"

void		pxl(t_rt_client *rt, int j, colour color)
{
  t_color	fragm;
  int		i;

  i = 0;
  fragm.color = color;
  if (rt->imend == 0)
    {
      while (i < 4)
	{
	  rt->data[j * 4 + i] = fragm.rgba[i];
	  i++;
	}
    }
}
