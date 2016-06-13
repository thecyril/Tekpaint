/*
** fonc.c for fonc in /home/puccio_c/rendu/Infographie/gfx_tekpaint/src
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Tue Jan 26 21:41:43 2016 cyril puccio
** Last update Tue Jan 26 22:41:32 2016 yoann barthelemi
*/

#include "struct.h"

t_bunny_response           click(t_bunny_event_state    etat,
                                 t_bunny_mousebutton    clic,
                                 void                   *data)
{
  (void)etat;
  (void)clic;
  (void)data;
  return (GO_ON);
}

t_bunny_response           key(t_bunny_event_state      state,
                               t_bunny_keysym           button,
                               void                     *data)
{
  (void)state; (void)button; (void)data;
  return (GO_ON);
}

void                    select_color(t_var *var)
{
  const bool            *touche;

  touche = bunny_get_keyboard();
  if (touche[BKS_A] == 1)
    var->couleur = BLACK;
  if (touche[BKS_Z] == 1)
    var->couleur = RED;
  if (touche[BKS_E] == 1)
    var->couleur = BLUE;
  if (touche[BKS_R] == 1)
    var->couleur = YELLOW;
  if (touche[BKS_T] == 1)
    var->couleur = GREEN;
  if (touche[BKS_Y] == 1)
    var->couleur = PURPLE;
  if (touche[BKS_U] == 1)
    var->couleur = TEAL;
  if (touche[BKS_I] == 1)
    var->couleur = PINK;
  if (touche[BKS_G] == 1)
    var->couleur = WHITE;
}

void                    fill_screen(t_var *var, int w, int h)
{
  t_bunny_position      pos;
  t_color               color;

  color.full = WHITE;
  pos.x = var->sx;
  pos.y = var->sy;
  while (pos.x != w)
    {
      tekpixel(var->pix, &pos, &color);
      pos.y++;
      if (pos.y == h)
        {
          pos.x++;
          pos.y = var->sx;
        }
    }
}

void                    pencil(t_var *var, int w, int h)
{
  t_bunny_position      pos;
  t_color               color;

  color.full = var->couleur;
  pos.x = var->cx;
  pos.y = var->cy;
  while (pos.y != h)
    {
      tekpixel(var->pix, &pos, &color);
      if (pos.x == w)
        {
          pos.y++;
          pos.x = var->cx - 1;
        }
      pos.x++;
    }
}
