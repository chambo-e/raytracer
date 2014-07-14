/*
** handle_key.c for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/conf_file
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Wed May 14 23:14:30 2014 chambon emmanuel
** Last update Thu May 15 16:19:21 2014 chambon emmanuel
*/

#include "rt.h"

int		handle_key(int key, t_rt *rt)
{
  if (key == ESCAPE_KEY)
    break_loop(rt);
  return (0);
}
