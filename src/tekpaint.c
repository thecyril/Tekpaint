/*
** tekpaint.c for tekpaint in /home/puccio_c/rendu/Infographie/gfx_tekpaint/src
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Mon Jan 25 10:26:24 2016 cyril puccio
** Last update Thu Jan 28 14:13:54 2016 cyril puccio
*/

#include "struct.h"

void			fill_struct(t_var *var)
{
  var->Wscreen = SCREEN_W;
  var->pix = bunny_new_pixelarray(SCREEN_W, SCREEN_H);
  var->start.x = 0;
  var->start.y = 0;
  var->sx = 0;
  var->sy = 0;
  var->couleur = BLACK;
  var->sz = 5;
  var->f = 1;
}

void   			trace_circle(t_var *var, int r, int x, int y)
{
  t_bunny_position	pos;
  double		angle;
  t_color               color;
  double		rr;

  rr = 0;
  angle = 0;
  color.full = var->couleur;
  if (var->f == 0)
    rr = r;
  while (rr <= r)
    {
      angle = 0;
      while (angle < 360)
	{
	  pos.x = x + rr * cos(angle * M_PI / 180);
	  pos.y = y + rr * sin(angle * M_PI / 180);
	  tekpixel(var->pix, &pos, &color);
	  angle += 0.5;
	}
      rr += 0.5;
    }
}

t_bunny_response                mainloop(t_var *var)
{
  t_varloop			loop;
  const t_bunny_position	*pos;

  loop.touche = bunny_get_keyboard();
  loop.click = bunny_get_mouse_button();
  pos = bunny_get_mouse_position();
  loop.sz = var->sz;
  var->cx = pos->x - loop.sz;
  var->cy = pos->y - loop.sz;
  if (loop.touche[BKS_F] == 1 && var->f == 1)
    var->f = 0;
  else if (loop.touche[BKS_F] == 1 && var->f == 0)
    var->f = 1;
  click_main_loop(var, loop, pos);
  select_color(var);
  if (loop.touche[BKS_PAGEUP] == 1)
    var->sz += 0.2;
  if (loop.touche[BKS_PAGEDOWN] == 1 && loop.sz >= 0)
    var->sz -= 0.2;
  bunny_blit(&var->win->buffer, &var->pix->clipable, &var->start);
  bunny_display(var->win);
  if (loop.touche[BKS_ESCAPE] == 1)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

int			paint()
{
  t_var                 var;

  var.win = bunny_start(SCREEN_W, SCREEN_H, false, "tekpaint");
  if (var.win == 0)
    return (-1);
  fill_struct(&var);
  if (var.pix == NULL)
    return (-1);
  fill_screen(&var, SCREEN_W, SCREEN_H);
  bunny_display(var.win);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_click_response(click);
  bunny_set_key_response(key);
  bunny_loop(var.win, 140, &var);
  bunny_stop(var.win);
  bunny_delete_clipable(&var.pix->clipable);
  return (0);
}

int			main()
{
  paint();
  return (0);
}
