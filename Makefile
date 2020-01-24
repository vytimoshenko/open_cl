# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 19:45:56 by hlorrine          #+#    #+#              #
#    Updated: 2020/01/24 17:28:26 by mperseus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	open_cl

HDR		= 	open_cl.h

SRC		= 	open_cl_main.c		\
			open_cl_init.c		\
			open_cl_get_info.c	\
			open_cl_run.c		\
			open_cl_err_1.c		\
			open_cl_err_2.c
		
OBJ		= 	$(SRC:.c=.o)

LIB		=	make -C libft

ADD_ERR =	-Wall -Wextra -Werror
ADD_OPT =	-Ofast
ADD_LIB =	-L./libft -lft
ADD_FRM =	-framework OpenCL

all:		$(NAME)

$(NAME):	$(OBJ)
			$(LIB)
			gcc -o $(NAME) $(OBJ) $(ADD_ERR) $(ADD_OPT) $(ADD_LIB) $(ADD_FRM)

%.o: %.c
			gcc -I $(HDR) $< -c -o $@ $(ADD_ERR) $(ADD_OPT)

clean:
			@/bin/rm -f $(OBJ)

fclean: 	clean
			@/bin/rm -f $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re