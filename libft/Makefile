# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 17:46:05 by gbraga-g          #+#    #+#              #
#    Updated: 2022/05/28 18:01:56 by gbraga-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

loli    =   ${addprefix zdsr,$(NAME)}

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
ft_memmove.c ft_strlcpy.c ft_toupper.c ft_tolower.c ft_memcmp.c \
ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
ft_calloc.c ft_strdup.c ft_strnstr.c ft_atoi.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c \
ft_strtrim.c ft_striteri.c ft_strmapi.c ft_itoa.c ft_split.c

SRCS_BONUS =  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstiter.c ft_lstclear.c ft_lstmap.c

OBJS        =   $(SRCS:%.c=%.o)
OBJS_BONUS =   $(SRCS_BONUS:%.c=%.o)
CC      =   gcc
CFLAGS  =   -Wall -Wextra -Werror
RM      =   rm -f
%.o: %.c
		@${CC} ${CFLAGS} -I./ -c $< -o $@
all: ${NAME}
${NAME}:${OBJS} libft.h
		@ar -crs ${NAME} ${OBJS}
bonus:${NAME} ${OBJS_BONUS}
		@ar -crs ${NAME} ${OBJS_BONUS}
		@touch $@
#Regla para borrar todos los objetos y directorios
clean:
		${RM} ${OBJS}
#Regla para borrar todo lo que ha sido creado or el makefile
fclean: clean
		${RM} ${NAME}
		${RM} bonus
#Regla  para rehacer todo
re:     fclean all
.PHONY: fclean, all, clean, re
