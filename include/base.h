/*
** base.h for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 15:11:53 2014 chambon emmanuel
** Last update Sun Jun  8 02:45:49 2014 david tran
*/

#ifndef BASE_H_
# define BASE_H_

/*
**                      BASE PROTOTYPES
*/
void			my_putchar(char);
void			my_putstr(char *);
int			print_error(char *);
void			*my_xmalloc(size_t);
char			*get_next_line(int);
char			*epur_str(char *);
char			**my_str_to_wordtab(char *, char);
void			free_rt(t_rt *);
void			free_tab(char **);
void			free_parse(t_parse *);
int			strlen_tab(char **);
char			*strdup(char *);

#endif /* !BASE_H_ */
