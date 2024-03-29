# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 15:17:34 by gbraga-g          #+#    #+#              #
#    Updated: 2022/06/23 17:58:40 by gbraga-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

INCLUDE	=	include
LIBFT   =   libft
SRC_DIR =   src/
OBJ_DIR	=	obj/
CC      =   gcc
CFLAGS  =   -g -Wall -Wextra -Werror -MMD -I
RM      =   rm -f
AR		=	ar rcs

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC_FILES	=	ft_printf ft_printf_utils ft_put_hex ft_put_ptr ft_put_unsigned

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS		=	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
OBJF		=	.cache_exists

all:	makelibs 
		@${MAKE} ${NAME}

makelibs:
			@$(MAKE) -C $(LIBFT)

-include ${DEPS}
${NAME}:${OBJ} ${INCLUDE}/libft.h ${INCLUDE}/ft_printf.h ${LIBFT}/libft.h
	cp libft/libft.a .
	mv libft.a ${NAME}
	@${AR} ${NAME} ${OBJ}
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

${OBJF}:
	@mkdir -p ${OBJ_DIR}

clean:
	@$(RM) -rf $(OBJ_DIR)
	@make clean -C $(LIBFT)
	@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean:	clean
	@$(RM) -f $(NAME)
	@$(RM) -f $(LIBFT)/libft.a
	@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
	@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:	fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

norm:
	@norminette ${SRC} ${INCLUDE} ${LIBFT} | grep -v Norme -B1 || true;

.PHONY: fclean, all, clean, re
