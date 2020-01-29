# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 20:18:18 by jsilance          #+#    #+#              #
#    Updated: 2020/01/21 21:07:47 by jsilance         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

SRC = 	arg_treat.c arg_typer.c flag_number.c flags_treat.c ft_printf.c \
	arg_process.c \

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: ${NAME}

libft:
	@clear && echo "Making libft..."
	@make -C libft
	@echo "Libft complete!"

$(NAME): libft ${OBJ}
	@clear && echo "Making archive..."
	@ar rc ${NAME} ${OBJ} libftprintf.a
	@ranlib ${NAME}
	@echo "Archive complete!"

%.o: %.c
	@clear && echo "Compilation of $? ..."
	@${CC} ${CFLAGS} -c -I${HEADER} -o $@ $?
	@echo "Compilation complete!"

clean:
	@clear && echo "Cleaning..."
	@/bin/rm -f ${OBJ} ${OBJ_BONUS}
	@make -C libft clean
	@echo "Cleaning complete!"

fclean:	clean
	@/bin/rm -f $(NAME)
	@make -C libft fclean
	@echo "Force cleaning complete!"

re:	fclean all
	
.PHONY: all clean fclan re test libft
