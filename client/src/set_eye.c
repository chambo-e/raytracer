/*
** set_eye.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder/client
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sat May 31 07:01:28 2014 chambon emmanuel
** Last update Sun Jun  8 11:15:49 2014 david tran
*/

#include "client_rt.h"

int			set_eye(char *line, t_rt_client *rt)
{
  if (!(rt->eye = my_xmalloc(sizeof(t_opt))))
    return (-1);
  if (sscanf(line, EYE_FORMAT,
             &rt->eye->eye_pos[0], &rt->eye->eye_pos[1],
             &rt->eye->eye_pos[2], &rt->eye->eye_rot[0],
             &rt->eye->eye_rot[1], &rt->eye->eye_rot[2],
             (int *)&rt->eye->aa, (int *)&rt->eye->filter) != 8)
    return (-1);
  return (0);
}
