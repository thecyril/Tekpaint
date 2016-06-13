/*
** struc.h for struc in /home/puccio_c/rendu/PSU_2015_my_printf
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Tue Nov 10 13:05:09 2015 cyril puccio
** Last update Mon Feb 29 16:32:38 2016 cyril puccio
*/

#include <lapin.h>
#include <lapin_enum.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <stdarg.h>

#ifndef		_STRUCT_H
# define	_STRUCT_H

#define SCREEN_W	1024
#define	SCREEN_H	768
#define DARK_GREY       0XFF7a7a7a

typedef struct		s_var
{
  bool			f;
  int			sx;
  int			sy;
  int			cx;
  int			cy;
  t_bunny_window        *win;
  t_bunny_pixelarray    *pix;
  t_bunny_position      start;
  t_bunny_ini		*ini;
  t_color		color;
  int			Wscreen;
  double       		sz;
  unsigned int		couleur;
}			t_var;

typedef struct		s_varloop
{
  const	bool	*touche;
  const	bool	*click;
  double	sz;
}			t_varloop;

void    my_putchar(char c);

void    my_put_nbr(int  nb);

int     my_putstr(char *str);

int     my_strlen(char *str);

int     my_strcmp(char *s1, char *s2);

int     my_str_ispprintable(char *str);

int     my_ls(char *dir);

char    *my_strlowcase(char *str);

void    my_putnbr_base(int nb, char *base);

void    my_printf(char *str, ...);

void    structure(char *str, va_list ap);

void    put_str(va_list list);

void    put_nbr(va_list list);

void    put_char(va_list list);

void    put_base8(va_list list);

void    put_base16(va_list list);

void    put_basemaj16(va_list list);

void    put_base2(va_list);

void    put_unbr(va_list);

void    put_phex(va_list);

int	my_getnbr(const char *str);

double  my_atof(const char *str);

t_bunny_response        mainloop(t_var *var);

t_bunny_response	key(t_bunny_event_state      state,
			    t_bunny_keysym           button,
			    void                     *data);

t_bunny_response	click(t_bunny_event_state    etat,
                                 t_bunny_mousebutton    clic,
                                 void                   *data);

void			click_main_loop(t_var *var,
					t_varloop loop,
					const t_bunny_position *pos);

void   			trace_circle(t_var *var, int r, int x, int y);

void			fill_struct(t_var *var);

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color);

void                    constekpixel(t_bunny_pixelarray		*pix,
				     const t_bunny_position	*pos,
				     t_color			*color);

void                    select_color(t_var *var);

void                    fill_screen(t_var *var, int w, int h);

void                    pencil(t_var *var, int w, int h);

#endif	/* _STRUCT_ */
