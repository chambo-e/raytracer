/*
** strlen_tab.c for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Wed Apr 23 19:04:05 2014 chambon emmanuel
** Last update Wed Apr 23 19:04:31 2014 chambon emmanuel
*/

int		strlen_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
