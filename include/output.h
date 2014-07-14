/*
** output.h for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/conf_file
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Thu May 15 22:06:19 2014 chambon emmanuel
** Last update Fri Jul  4 23:32:16 2014 chambon emmanuel
*/

#ifndef OUTPUT_H_
# define OUTPUT_H_

FILE			*open_FILE(t_rt *);

/*
**	BMP
*/
# define DEF_PPI_X	3780
# define DEF_PPI_Y	3780
# define BI_RGB		0

int			save_bmp(t_rt *);

typedef struct		s_bmp_header
{
  char			magic[2];
  int			size_tot;
  uint16_t		spec1;
  uint16_t		spec2;
  int			offset;
}			t_bmp_header;

typedef struct		s_dib_header
{
  int			header_size;
  int			width;
  int			height;
  uint16_t		depth;
  uint16_t		planes;
  int			compress;
  int			img_size;
  int			ppi_x;
  int			ppi_y;
  int			palette_wide;
  int			imp_color;
}			t_dib_header;

typedef struct		s_bmp_file
{
  t_bmp_header		header;
  t_dib_header		dib;
}			t_bmp_file;

/*
**	PPM
*/

int			save_ppm(t_rt *);

#endif /* !OUTPUT_H_ */
