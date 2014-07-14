/*
** send_response.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/paasch_j/MUL_2013_rtracer/client
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun Jun  8 17:09:41 2014 chambon emmanuel
** Last update Sun Jun  8 17:10:39 2014 chambon emmanuel
*/

#include "client_rt.h"

void		send_data(char *data, t_rt_client *rt, int socket_server)
{
  int		length;
  int		bytesSent;

  length = (rt->end - rt->beg) * 4;
  while (length > 0)
    {
      bytesSent = send(socket_server, (void *)data, length, 0);
      if (bytesSent == -1)
        {
          perror("send");
          return ;
        }
      data += bytesSent;
      length -= bytesSent;
    }
  close(socket_server);
}
