/*
** output_ppm.c for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/conf_file
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Thu May 15 23:51:13 2014 chambon emmanuel
** Last update Sun May 18 17:19:05 2014 chambon emmanuel
*/

#include "rt.h"

int		save_ppm(t_rt *rt)
{
  int		y;
  int		x;
  FILE		*file;
  unsigned char	col[3];

  if (!(file = open_FILE(rt)))
    return (-1);
  fprintf(file, "P6\n%d %d\n255\n", WINX, WINY);
  y = 0;
  while (y < WINY)
    {
      x = 0;
      while (x < WINX)
        {
          bzero(col, 3);
          col[0] = rt->img->data[(y * WINX * 4) + (x * 4) + 2];
          col[1] = rt->img->data[(y * WINX * 4) + (x * 4) + 1];
          col[2] = rt->img->data[(y * WINX * 4) + (x * 4)];
          fwrite(col, 1, 3, file);
          x++;
        }
      y++;
    }
  fclose(file);
  return (0);
}
