# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriant <mriant@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 11:10:18 by mriant            #+#    #+#              #
#    Updated: 2022/01/07 14:44:39 by mriant           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
	ft_printnbr.c \
	ft_printstr.c

OBJS = ${SRCS:%.c=%.o}

INC_DIR = ./includes

LIBFT_DIR = ./libft

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

%.o: %.c libft.a
	${CC} ${FLAGS} -c $< -o $@ -I ${INC_DIR} -L ${LIBFT_DIR} -lft

libft.a:
	make -C ${LIBFT_DIR}
	cp ${LIBFT_DIR}/libft.a ./libft.a

clean:
	make clean -C libft
	rm -rf ${OBJS}

fclean: clean
	make fclean -C libft
	rm -rf ${NAME} libft.a

re: fclean all

.PHONY: all clean fclean re