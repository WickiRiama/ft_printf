# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriant <mriant@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 11:10:18 by mriant            #+#    #+#              #
#    Updated: 2022/01/18 14:37:42 by mriant           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
	ft_printnbr.c \
	ft_printstr.c

OBJS = ${SRCS:%.c=%.o}

DEPS = $(SRCS:.c=.d)

INC_DIR = ./includes

LIBFT_DIR = ./libft

CC = gcc

FLAGS = -MMD -Wall -Wextra -Werror

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
	rm -rf ${DEPS}

fclean: clean
	make fclean -C libft
	rm -rf ${NAME}

re: fclean all

-include ${DEPS}

.PHONY: all clean fclean re test