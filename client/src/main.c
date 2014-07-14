/*
** main.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder/client
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Thu May 29 17:36:12 2014 chambon emmanuel
** Last update Sun Jun  8 16:58:13 2014 chambon emmanuel
*/

#include "client_rt.h"

int				main(void)
{
  int				sock;

  if ((sock = init_client()) == -1)
    return (-1);
  if (listen(sock, 1) == -1)
    return (-1);
  if (handle_client(sock, 0) == -1)
    return (-1);
  return (0);
}
