# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriant <mriant@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 11:10:18 by mriant            #+#    #+#              #
#    Updated: 2022/01/18 13:59:00 by mriant           ###   ########.fr        #
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

${NAME}: ${OBJS} ${LIBFT_DIR}/libft.a
	cp ${LIBFT_DIR}/libft.a ./${NAME}
	ar -rcs ${NAME} ${OBJS}

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@ -I ${INC_DIR}

${LIBFT_DIR}/libft.a:
	make -C ${LIBFT_DIR}

test: ${NAME}
	${CC} ${FLAGS} main.c -I ${INC_DIR} -L. -lftprintf && ./a.out

clean:
	make clean -C libft
	rm -rf ${OBJS}

fclean: clean
	make fclean -C libft
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re test