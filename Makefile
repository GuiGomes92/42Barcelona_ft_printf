# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 15:17:34 by gbraga-g          #+#    #+#              #
#    Updated: 2022/05/28 16:48:29 by gbraga-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM      =   rm -f
OBJS	=	$(SRCS:%.c=%.o)
%.o: %.c
		${CC} ${CFLAGS} -I./ -c $< -o $@

all: ${NAME}
${NAME}:${OBJS} ft_printf.h
	ar -crs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:			fclean all

.PHONY: fclean, all, clean, re
