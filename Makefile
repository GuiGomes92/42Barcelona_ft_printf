# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 15:17:34 by gbraga-g          #+#    #+#              #
#    Updated: 2022/05/28 18:05:58 by gbraga-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	a.out

SRCS	=	ft_printf.c
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM      =   rm -f
LIBFT 	= 	libft
HEADER	=	libftprintf.h
OBJS	=	$(SRCS:%.c=%.o)
%.o: %.c
		${CC} ${CFLAGS} -I./ -c $< -o $@

all: ${NAME}
${NAME}:${OBJS} ${HEADER}
	make -C ${LIBFT}
	@${CC} ${OBJS} ${LIBFT}/${LIBFT}.a -o ${NAME}
#	editar linea de arriba al entregar sin CC ni flags
#	ar -crs ${NAME} ${OBJS}
#	quitar comentario al entregar

clean:
	${RM} ${OBJS}
	${RM} ${LIBFT}/%.o

fclean:	clean
	${RM} ${NAME}

re:			fclean all

.PHONY: fclean, all, clean, re
