/*
** parse_received.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/MUL_2013_rtracer/src
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Fri Jun 13 17:28:39 2014 chambon emmanuel
** Last update Mon Jul 14 16:21:52 2014 chambon emmanuel
*/

#include "rt.h"

/* Change the state of the AA */

void		set_aa(char *line, t_rt *rt)
{
  while (render == 1);				/* wait for the image to be fully rendered */
  rt->eye->aa = atoi(&line[3]);
  redraw = 1;					/* explicit enough  */
}

/* Functions to handle the gyroscope are still there. Maybe it will be done one day */

int		set_gyro(char *line, t_rt *rt)
{
  double	x;
  double	y;
  double	z;

  while (render == 1);
  if (sscanf(line, "GYRO;%lf;%lf;%lf", &x, &y, &z) < 3)
    return (-1);
  gyroscope(rt->eye, x, y, z);
  redraw = 1;
  return (0);
}

/* Generic function to send data to the app */

void		send_data_app(char *s, int sock)
{
  if (!s)
    return ;
  if (send(sock, s, strlen(s), 0) == -1)
    {
      perror("send");
      return ;
    }
}

/* Handle the response to send to the app */

void		send_info_app(char type, t_rt *rt, char *demand)
{
  int		sock;

  if ((sock = get_socket_app(type, demand)) == -1)
    return ;
  if (type == 0)
    {
      if (rt->eye->aa == 1)
	send_data_app("ASKAA=OK", sock);
      else
	send_data_app("ASKAA=NO", sock);
    }
  if (type == 1)
    send_data_app(concat_obj_struct(rt->objs), sock);
  if (type == 2)
    send_data_app(concat_spot_struct(rt->spot), sock);
  close(sock);
}

/* Parse data received from the app according to the flags */

int		parse_received(char *line, t_rt *rt)
{
  char		**rec;
  int		i;

  if (!(rec = my_str_to_wordtab(line, '*')))				/* Each instruction received from the app */
    return (-1);								/* are separated with a "*" */
  i = 0;
  while (rec[i])
    {
      if (strlen(rec[i]) > 4 && !strncmp(rec[i], "OBJ;", 4))		/* New object received */
	add_obj_app(rec[i], rt->objs, 0);
      else if (strlen(rec[i]) > 5 && !strncmp(rec[i], "SPOT;", 5))	/* New spot received */
	add_spot_app(rec[i], rt->spot, 0);
      else if (strlen(rec[i]) > 3 && !strncmp(rec[i], "AA;", 2))	/* Anti-aliasing change state */
	set_aa(rec[i], rt);
      else if (strlen(rec[i]) > 5 && !strncmp(rec[i], "GYRO;", 4))	/* Gyroscope instruction */
	set_gyro(rec[i], rt);						/* Not yet fully integrated. Maybe one day */
      else if (strlen(rec[i]) > 5 && !strncmp(rec[i], "ASKAA", 5))	/* App asked the state of AA */
      	send_info_app(0, rt, rec[i]);
      else if (strlen(rec[i]) > 5 && !strncmp(rec[i], "ASKOBJ", 6))	/* App asked list of objects */
      	send_info_app(1, rt, rec[i]);
      else if (strlen(rec[i]) > 5 && !strncmp(rec[i], "ASKSPOT", 7))	/* App asked list of spots */
      	send_info_app(2, rt, rec[i]);
      else if (strlen(rec[i]) > 3 && !strncmp(rec[i], "OB;", 3))	/* New list of objects received */
      	reset_obj(rec[i], rt);
      else if (strlen(rec[i]) > 3 && !strncmp(rec[i], "SP;", 3))	/* New list of spot received */
      	reset_spot(rec[i], rt);
      i++;
    }
  free_tab(rec);
  return (0);
}
