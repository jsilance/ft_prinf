# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 20:18:18 by jsilance          #+#    #+#              #
#    Updated: 2020/01/28 02:19:57 by jsilance         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../libftprintf.a

HEADER = libft.h

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c \
ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
ft_lstiter_bonus.c ft_lstmap_bonus.c ft_laststr_indexof_bonus.c \
ft_firststr_indexof_bonus.c ft_lstlast_bonus.c ft_charstock_bonus.c \
ft_strstock_bonus.c ft_strnstock_bonus.c ft_itoa_base.c ft_uitoa.c \
ft_memstock.c \

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: ${NAME}

$(NAME): ${OBJ} ${OBJ_BONUS}
	@ar rc ${NAME} ${OBJ} ${OBJ_BONUS}
	@ranlib ${NAME}

%.o: %.c
	@clear && echo "Compilation of $? ..."
	@${CC} ${CFLAGS} -c -I${HEADER} -o $@ $?
	@echo "Compilation complete!"

clean:
	@/bin/rm -f ${OBJ} ${OBJ_BONUS}

fclean:	clean
	@/bin/rm -f $(NAME) 

re:	fclean all

.PHONY: all clean fclan re
