/*
** send_opt.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Fri May 30 20:38:12 2014 chambon emmanuel
** Last update Thu Jun  5 22:18:51 2014 emmanuel chambon
*/

#include "rt.h"

char			*concat_opt_struct(t_opt *eye)
{
  char			*res;
  char			*ret;
  char			*eye_rot;
  char			*eye_pos;

  if (!(res = my_xmalloc((6 * sizeof(double)) + (3 * sizeof(char)) + 111))
      || !(ret = my_xmalloc(13)))
    return (NULL);
  bzero(res, (6 * sizeof(double)) + (3 * sizeof(char)) + 111);
  bzero(ret, 13);
  res[0] = 'E';
  res[1] = 'Y';
  res[2] = ';';
  if (!(eye_pos = get_double_som(0, NULL, NULL, eye))
      || !(eye_rot = get_double_som(1, NULL, NULL, eye)))
    return (NULL);
  strcat(res, eye_pos);
  strcat(res, eye_rot);
  sprintf(ret, "%d;%d*", eye->aa, eye->filter);
  strcat(res, ret);
  free(eye_pos);
  free(eye_rot);
  free(ret);
  return (res);
}
