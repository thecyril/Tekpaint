##
## Makefile for Makefile in /home/barthe_y/gfx_tekpaint
## 
## Made by yoann barthelemi
## Login   <barthe_y@epitech.net>
## 
## Started on  Tue Jan 26 23:16:50 2016 yoann barthelemi
## Last update Tue Jan 26 23:16:50 2016 yoann barthelemi
##

NAME    =       tekpaint

FLAGS   =	-I/home/${USER}/.froot/lib                      \
		-I/home/${USER}/.froot/include

CFLAGS  =       -I include -W -Wall -Werror -ansi -pedantic

LAPIN   =       -L/home/${USER}/.froot/lib/ -llapin     \
		-L/usr/local/lib                        \
		-L/home/${USER}/.froot/include          \
		-lsfml-audio                            \
		-lsfml-graphics                         \
		-lsfml-window                           \
		-lsfml-system                           \
		-lstdc++                                \
		-ldl                                    \
		-lm

SRC     =       src/tekpaint.c				\
		src/fonc.c				\
		src/loop.c

OBJ     =       $(SRC:.c=.o)

LIB     =       libmy.a

all     :       $(NAME)

$(NAME) :       $(LIB) $(OBJ)
		gcc $(SRC) $(LAPIN) $(CFLAGS) $(FLAGS) -o $(NAME) -L. -lmy

$(LIB) :
		make -C ./lib/my

clean   :
	 	rm -f $(OBJ)
		make clean -C ./lib/my

fclean  :
		rm -f $(OBJ)
		rm -f $(NAME)
		rm -f $(LIB)
		make fclean -C ./lib/my

re      :       fclean all

.PHONY  :       all clean fclean re
