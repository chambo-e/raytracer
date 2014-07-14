/*
** client_rt.h for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder/client
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Thu May 29 17:37:10 2014 chambon emmanuel
** Last update Sat Jul  5 21:03:51 2014 chambon emmanuel
*/

#ifndef CLIENT_RT_H_
# define CLIENT_RT_H_

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>
# include <omp.h>
# include <string.h>
# include <strings.h>
# include <stdint.h>
# include <netdb.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <pthread.h>
# include <errno.h>
# include <limits.h>

# include "struct.h"
# include "equation.h"
# include "perlin.h"
# include "goodies.h"

# define X			0
# define Y			1
# define Z			2
# define PI			3.141592653589793238
# define TWO_PI			6.283185207179586476925286766560
# define TWO_PI_3		2.0943951023931954923084
# define TWO_PI_43		4.1887902047863909846168
# define ESCAPE_KEY		65307
# define MALLOC_ERROR		"Can't perform malloc\n"
# define PORT			"7878"
# define MAX			512000
# define OBJ_FORMAT		"OB;%lf;%lf;%lf;%lf;%lf;%lf;%d;%lf;%lf;%lf;%d;%d;%d;%d;%lf;%d"
# define EYE_FORMAT		"EY;%lf;%lf;%lf;%lf;%lf;%lf;%d;%d"
# define SPOT_FORMAT		"SP;%lf;%lf;%lf;%d;%d;%d;%d;%d"
# define WINX			rt->winsize_x
# define WINY			rt->winsize_y
# define LOW			0.000001
# define AA			8

char				**my_str_to_wordtab(char *, char);
void				*my_xmalloc(size_t);
int				init_client();
int				init_struct(t_rt_client *);
int				decrypt(char [], int);
int				set_eye(char *, t_rt_client *);
int				set_spot(char *, t_spot *);
int				set_obj(char *, t_obj *);
int				handle_client(int, int);
int				free_rt_client(t_rt_client *);
t_obj				*cast_ray(t_ray *, t_obj *, t_obj *);
int				cast_a_ray_alias(t_rt_client *, int, int);
void				init_ray(t_rt_client *, t_ray *, int, int);
void				assign_ray(t_rt_client *, t_ray *, t_obj *);
void				x_rotation(t_ray *, t_obj *);
void				y_rotation(t_ray *, t_obj *);
void				z_rotation(t_ray *, t_obj *);
colour				new_color(t_color *, double);
colour				shining(t_color *, t_color *, double, double);
colour				get_the_scene(t_rt_client *, int , int);
colour				shadows(t_rt_client *, t_ray *, t_obj *);
void				pxl(t_rt_client *, int, colour);
void				send_data(char *, t_rt_client *, int);

#endif /* !CLIENT_RT_H _*/
