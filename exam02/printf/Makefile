# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namohamm <namohamm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 21:42:04 by namohamm          #+#    #+#              #
#    Updated: 2022/03/02 18:18:26 by namohamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER	= ft_printf.h

OBJS = ${SRCS:.c=.o}

RM		= rm -f

GCCF = gcc -Wall -Wextra -Werror

LIB = ar -rcs

SRCS =	ft_printf.c ft_int_len.c ft_int_putchar.c ft_int_putnbr.c\
		ft_int_putstr.c ft_put_unsigned.c ft_putptr.c ft_put_hex.c\

all:	${NAME}

.c.o:
		${GCCF} -c $< -o ${<:.c=.o} -I $(HEADER)

$(NAME): ${OBJS}
		@${LIB} ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all