/*
** server.h for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 15:24:58 2014 chambon emmanuel
** Last update Sun Jun  8 02:45:02 2014 david tran
*/

#ifndef SERVER_H_
# define SERVER_H_

# include "struct.h"

# define MAX            16384
# define PORT		"7878"

int			activate_client(t_client *, t_rt *);
char			*get_double_som(int, t_spot *, t_obj *, t_opt *);
char			*concat_opt_struct(t_opt *);
char			*concat_spot_struct(t_spot *);
char			*concat_obj_struct(t_obj *);
int			send_info(t_arg_thread *, int);
void			*get_in_addr(struct sockaddr *);
int			get_nb_client(t_client *);

#endif /* !SERVER_H_ */
