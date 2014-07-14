/*
** main.c for RT in /home/chambo_e/Dropbox/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Fri Apr 18 17:06:05 2014 chambon emmanuel
** Last update Fri Jul  4 23:29:35 2014 chambon emmanuel
*/

#include "rt.h"

int		check_save_file(char *file, t_rt *rt)
{
  if ((!(strncmp(file, "--output=", 9))
      && ((!(strncmp(&file[strlen(file) - 4], ".bmp", 4)))
	  || !(strncmp(&file[strlen(file) - 4], ".ppm", 4)))))
    {
      if (!(rt->save = strdup(&file[9])))
	return (-1);
      return (0);
    }
  else
    print_error(WRONG_FILE);
  return (-1);
}

int		check_save_opt(char **av, t_rt *core)
{
  int		i;

  i = 0;
  while (av[i])
    {
      if (!(strncmp(av[i], "--output=", 9)))
	{
	  if (check_save_file(av[i], core) == -1)
	    return (-1);
	}
      else if (!(strcmp(av[i], "--cluster-only")))
	core->cluster = 0;
      else
	return (print_usage("./raytracer"));
      i++;
    }
  return (0);
}

int		mbis(int ac, char **av)
{
  t_rt		*core;

  render = 0;
  redraw = 0;
  if (!(core = my_xmalloc(sizeof(t_rt))))
    return (-1);
  core->cluster = 1;
  core->save = NULL;
  if (ac >= 3 && (check_save_opt(&av[2], core)))
    {
      free(core);
      return (-1);
    }
  if (init_struct(core, av[1]) == -1
      || mlx_node(core) == -1)
    return (1);
  free_rt(core);
  return (0);
}

int		main(int ac, char **av)
{
  if (ac < 2 || ac > 4)
    return (print_usage(av[0]));
  else
    return (mbis(ac, av));
  return (0);
}
