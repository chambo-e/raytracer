/*
** equation_array.c for raytracer in /home/paasch_j/Dropbox/raytracer/paasch_j/raytracer
**
** Made by johan paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Tue May 27 18:01:46 2014 johan paasche
** Last update Sun Jun  8 06:30:46 2014 johan paasche
*/

#include "rt.h"

double		(**init_fonction_array(int size))()
{
  int		i;
  double	(**fonction_array)();

  if (!(fonction_array = my_xmalloc(sizeof(*fonction_array) * (size + 1))))
    return (NULL);
  i = 0;
  while (i <= size)
    fonction_array[i++] = NULL;
  return (fonction_array);
}

double		(**set_equation_array())()
{
  double	(**equation_array)();

  if ((equation_array = init_fonction_array(7)) == NULL)
    return (NULL);
  equation_array[0] = NULL;
  equation_array[1] = &plane_equation;
  equation_array[2] = &sphere_equation;
  equation_array[3] = &cone_equation;
  equation_array[4] = &cylinder_equation;
  equation_array[5] = &tore_equation;
  equation_array[6] = &cube_equation;
  return (equation_array);
}

double		(**set_normale_array())()
{
  double	(**normale_array)();

  if ((normale_array = init_fonction_array(7)) == NULL)
    return (NULL);
  normale_array[0] = NULL;
  normale_array[1] = &plane_normale;
  normale_array[2] = &sphere_normale;
  normale_array[3] = &cone_normale;
  normale_array[4] = &cylinder_normale;
  normale_array[5] = &tore_normale;
  normale_array[6] = &cube_normale;
  return (normale_array);
}
