/*
** loop.c for loop in /home/barthe_y/gfx_tekpaint
** 
** Made by yoann barthelemi
** Login   <barthe_y@epitech.net>
** 
** Started on  Tue Jan 26 22:27:54 2016 yoann barthelemi
** Last update Tue Jan 26 23:22:00 2016 yoann barthelemi
*/

#include "struct.h"

void				click_main_loop(t_var *var, t_varloop loop, const t_bunny_position *pos)
{
  if (loop.click[BMB_LEFT] == 1 && pos->x > 0 && pos->y > 0)
    pencil(var, pos->x + loop.sz, pos->y + loop.sz);
  if (loop.click[BMB_RIGHT] == 1 && pos->x > 0 && pos->y > 0)
    trace_circle(var, 10 + loop.sz, pos->x, pos->y);
}
