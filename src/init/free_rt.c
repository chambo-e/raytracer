/*
** free_rt.c for RT in /home/chambo_e/Dropbox/epitech/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Mon Apr 21 22:16:02 2014 chambon emmanuel
** Last update Sat Jul  5 23:45:53 2014 chambon emmanuel
*/

#include "rt.h"

void		free_client(t_client *client)
{
  t_client	*tmp;

  while (client)
    {
      tmp = client;
      client = client->next;
      if (tmp->servinfo)
	freeaddrinfo(tmp->servinfo);
      if (tmp->hostname)
	free(tmp->hostname);
      if (tmp->service)
	free(tmp->service);
      free(tmp);
    }
}

void		free_spot(t_spot *spot)
{
  t_spot	*tmp;

  while (spot)
    {
      tmp = spot;
      spot = spot->next;
      if (tmp->color)
	free(tmp->color);
      free(tmp);
    }
}

void		free_objs(t_obj *objs)
{
  t_obj		*tmp;

  while (objs)
    {
      tmp = objs;
      objs = objs->next;
      if (tmp->color)
	free(tmp->color);
      free(tmp);
    }
  set_fct_ptr(NULL, 1);
}

void		free_rt(t_rt *rt)
{
  if (rt)
    {
      if (rt->N2D.vals)
	free(rt->N2D.vals);
      if (rt->eye)
	free(rt->eye);
      if (rt->objs)
	free_objs(rt->objs);
      if (rt->spot)
	free_spot(rt->spot);
      if (rt->img)
	free(rt->img);
      if (rt->save)
	free(rt->save);
      if (rt->client)
	free_client(rt->client);
      free(rt);
    }
}
