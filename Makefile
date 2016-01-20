# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/16 15:02:08 by zhasni            #+#    #+#              #
#    Updated: 2015/03/20 09:17:22 by zhasni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= 	get_next_line.c \
				tools1.c \
				tools2.c \
				sh1.c \
				cd.c \
				setenv.c \
				error.c \
				build.c \
				ft_tolowerstr.c \
				main.c

NAME		= 	ft_minishell1
CC			= 	gcc
CFLAGS		= 	-Werror -Wextra -Wall -g
OBJ			= 	$(SRC:.c=.o)
RM			= 	rm -rf
INCLUDES	=	libft/includes
LIBFT		=	libft/
HEADERS		=	-I./. -Ilibft/includes
LIB			=	libft.a

all: $(LIB) $(NAME)
	@echo "\033[0mCrew ready to sail Cap'tain!~~";
	@echo "                   ZZZZZZ ";
	@echo "                  ZZ****ZZZZ ";
	@echo "                 ZZ********ZZ ";
	@echo "          ZZZZ  ZZ**********ZZ ";
	@echo "        ZZZ***ZZZ***********ZZ ";
	@echo "       ZZ*******************ZZ ";
	@echo "      ZZ********************ZZ ";
	@echo "     ZZ*********************ZZ ";
	@echo "     ZZ*********************ZZ ";
	@echo "     ZZ*****ZZZZZZZ*********ZZ ";
	@echo "      ZZ***ZZ******ZZ******ZZZ ";
	@echo "       ZZ*ZZ********ZZ**ZZZ***ZZZZ ";
	@echo "        ZZZ**********ZZZ*********ZZ ZZZZZZZ ";
	@echo "         ZZ***********ZZ**********ZZ******ZZ ";
	@echo "      ZZZZZ************ZZ******************ZZ ";
	@echo "   ZZZZ****************ZZ*******************ZZ ";
	@echo "  ZZ*******************ZZ********************ZZ ";
	@echo " ZZ********************ZZ********************ZZ ";
	@echo " ZZ********************ZZ********************ZZ ";
	@echo " ZZ********************ZZ*******************ZZ ";
	@echo " ZZ********************ZZ******************ZZ ";
	@echo "  ZZ******************ZZZ*****************ZZ ";
	@echo "   ZZ****************ZZ ZZ***************ZZ ";
	@echo "    ZZZ*************ZZ   ZZ*************ZZ ";
	@echo "       ZZZ*******ZZZ      ZZ********ZZZZZ ";
	@echo "         ZZZZZZZZ++         ZZZ**ZZZZ          ZZZZZZZ ";
	@echo "                  ++          ZZZ             ZZ     ZZ ";
	@echo "                    ++          ++        ZZZZZ        Z ";
	@echo "                     ++           ++    ZZ             Z ";
	@echo "                       +++++       ++ ZZ               Z ";
	@echo "                            +++++ ZZZZ                 Z ";
	@echo "                               ZZZZZ                 ZZ ";
	@echo "                              ZZ                      Z+ ";
	@echo "                              ZZ                ZZ    Z + ";
	@echo "                               ZZ                     Z  +ZZZZZ ";
	@echo "                                ZZ       ZZ           Z  Z+    Z ";
	@echo "                                 ZZ           ZZZ     Z ZZ +   Z ";
	@echo "                                  ZZZZ         Z     ZZZ    +  Z+ ";
	@echo "                                     ZZ             Z        ++++ ";
	@echo "                                      ZZ           Z          Z ";
	@echo "                                       ZZZZZ        Z        Z ";
	@echo "                                      Z     Z        Z     ZZ ";
	@echo "                                     Z      Z         Z  ZZ ";
	@echo "                                    ZZ      Z          ZZ ";
	@echo "                                    ZZ      Z          Z ";
	@echo "                                    ZZZ      Z         Z ";
	@echo "                                     ZZ       Z        ZZZ ";
	@echo "                                      ZZ       Z       Z ZZ ";
	@echo "                                      ZZ       ZZ  X   Z  ZZ ";
	@echo "                                      ZZZZ     ZZ     ZZ   ZZZZZZZ ";
	@echo "                                      ZZ  ZZZZZZ     ZZ          ZZ ";
	@echo "                                      ZZ           ZZZ           ZZ ";
	@echo "                                       ZZ        ZZZZZ           ZZ ";
	@echo "                                       ZZ      ZZ    ZZZ        ZZ ";
	@echo "                                       ZZ      Z        ZZZ    ZZ ";
	@echo "                                      ZZZ      Z         ZZZZZZZ ";
	@echo "                                     ZZZZ      Z ";
	@echo "                                     ZZZ       ZZ ";
	@echo "                                      ZZ        Z ";
	@echo "                                      ZZ       ZZ ";
	@echo "                                        ZZ    ZZ ";
	@echo "                                          ZZZZZ ";

$(LIB):
	@echo "\033[0;34mTrying to board libft.a...";
	@make -C $(LIBFT)

$(NAME): $(OBJ)
	@echo "\033[0;31mSte\033[0;32mali\033[0;33mng a \033[0;34mnew\033[0;35m Ship \033[0m...";
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

	@echo "\033[0;32mShip stolen.";

.c.o:
	@echo "\033[1;35mLooting $<";
	@$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@ -L libft/ -lft

clean:
	@echo "\033[0;36mCleaning Rhum from Cargo...";
	@make clean -C $(LIBFT)
	@$(RM) $(OBJ)
	@echo "\033[0;36mFound some fine bottles!";
fclean: clean
	@echo "\033[1;33mCleaning Gold Pieces from rich spoiled daddy's girl...";
	@make fclean -C $(LIBFT)
	@$(RM) $(NAME)
	@echo "Swimming in gold...";
re: fclean all

.PHONY: all clean fclean re

