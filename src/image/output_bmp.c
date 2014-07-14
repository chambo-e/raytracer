/*
** output_bpm.c for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/conf_file
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Thu May 15 23:53:58 2014 chambon emmanuel
** Last update Sun Jun  1 22:23:20 2014 chambon emmanuel
*/

#include "rt.h"

t_bmp_file	*init_bmp(t_rt *rt)
{
  t_bmp_file	*file;

  if (!(file = my_xmalloc(sizeof(t_bmp_file))))
    return (NULL);
  bzero(file, sizeof(t_bmp_file));
  file->header.magic[0] = 'B';
  file->header.magic[1] = 'M';
  file->dib.header_size = 40;
  file->dib.width = WINX;
  file->dib.height = WINY;
  file->dib.planes = 1;
  file->dib.depth = 32;
  file->dib.ppi_x = DEF_PPI_X;
  file->dib.ppi_y = DEF_PPI_Y;
  file->dib.compress = BI_RGB;
  file->dib.palette_wide = 0;
  file->dib.imp_color = 0;
  file->dib.img_size = WINY * (WINX * 4);
  file->header.offset = 54;
  file->header.size_tot = file->dib.img_size + file->header.offset;
  return (file);
}

void		write_dib(t_dib_header dib, FILE *file)
{
  fwrite(&(dib.header_size), sizeof(int), 1, file);
  fwrite(&(dib.width), sizeof(int), 1, file);
  fwrite(&(dib.height), sizeof(int), 1, file);
  fwrite(&(dib.planes), sizeof(uint16_t), 1, file);
  fwrite(&(dib.depth), sizeof(uint16_t), 1, file);
  fwrite(&(dib.compress), sizeof(int), 1, file);
  fwrite(&(dib.img_size), sizeof(int), 1, file);
  fwrite(&(dib.ppi_x), sizeof(int), 1, file);
  fwrite(&(dib.ppi_y), sizeof(int), 1, file);
  fwrite(&(dib.palette_wide), sizeof(int), 1, file);
  fwrite(&(dib.imp_color), sizeof(int), 1, file);
}

void		write_pix(FILE *file, t_rt *rt)
{
  int		y;
  int		x;
  unsigned char	col[4];

  y = WINY - 1;
  while (y > 0)
    {
      x = 0;
      while (x < WINX)
        {
          bzero(col, 4);
          col[0] = rt->img->data[(y * WINX * 4) + (x * 4)];
          col[1] = rt->img->data[(y * WINX * 4) + (x * 4) + 1];
          col[2] = rt->img->data[(y * WINX * 4) + (x * 4) + 2];
          col[3] = rt->img->data[(y * WINX * 4) + (x * 4) + 3];
          fwrite(col, 1, 4, file);
          x++;
        }
      y--;
    }
}

void		write_file(t_bmp_file *data, FILE *file, t_rt *rt)
{
  fwrite(data->header.magic, sizeof(data->header.magic), 1, file);
  fwrite(&(data->header.size_tot), sizeof(int), 1, file);
  fwrite(&(data->header.spec1), sizeof(uint16_t), 1, file);
  fwrite(&(data->header.spec2), sizeof(uint16_t), 1, file);
  fwrite(&(data->header.offset), sizeof(int), 1, file);
  write_dib(data->dib, file);
  write_pix(file, rt);
}

int		save_bmp(t_rt *rt)
{
  t_bmp_file	*data;
  FILE		*file;

  if (!(data = init_bmp(rt)) || (!(file = open_FILE(rt))))
    return (-1);
  write_file(data, file, rt);
  fclose(file);
  free(data);
  return (0);
}
