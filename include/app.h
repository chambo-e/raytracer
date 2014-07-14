/*
** app.h for rt in /home/chambo-e/rtracer
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Wed Jun 11 20:33:19 2014 chambon emmanuel
** Last update Sun Jul 13 22:40:48 2014 chambon emmanuel
*/

#ifndef APP_H_
# define APP_H_

# include "struct.h"

# define PORT_APP	"7879"
# define OBJ_MODEL	"OBJ;%d;%lf;%lf;%lf;%lf;%lf;%lf;%d;%d;%d;%lf;%lf;%lf;%lf;%d"
# define O_MODEL	"B;%d;%lf;%lf;%lf;%lf;%lf;%lf;%d;%d;%d;%lf;%lf;%lf;%lf;%d;"
# define SPOT_MODEL	"SPOT;%lf;%lf;%lf;%d;%d;%d"
# define S_MODEL	"P;%lf;%lf;%lf;%d;%d;%d;"

void			mlx_app(t_rt *);

int			render;
int			redraw;
int			parse_received(char *, t_rt *);
void			gyroscope(t_opt *, double, double, double);
void			add_obj_app(char *, t_obj *, int);
void			add_spot_app(char *, t_spot *, int);
int			init_socket_app();
void			reset_obj(char *, t_rt *);
void			reset_spot(char *, t_rt *);
int			get_socket_app(char, char *);

#endif /* !APP_H_ */
