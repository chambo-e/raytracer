/*
** break_loop.c for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/conf_file
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Thu May 15 16:18:46 2014 chambon emmanuel
** Last update Sun Jul  6 22:01:16 2014 chambon emmanuel
*/

#include "rt.h"

FILE		*open_FILE(t_rt *rt)
{
  FILE		*file;

  return (file = fopen(rt->save, "wb"));
}

void		save_file(t_rt *rt)
{
  printf("Please wait while we generate the output file : %s\n", rt->save);
  if (strlen(rt->save) > 4
      && !(strncmp(&rt->save[strlen(rt->save) - 4], ".ppm", 4)))
    save_ppm(rt);
  if (strlen(rt->save) > 4
      && !(strncmp(&rt->save[strlen(rt->save) - 4], ".bmp", 4)))
    save_bmp(rt);
}

void		break_loop(t_rt *rt)
{
  if (rt->save)
    save_file(rt);
  mlx_destroy_window(rt->img->mlx, rt->img->win, rt->img->img);
  free_rt(rt);
  exit(EXIT_SUCCESS);
}
