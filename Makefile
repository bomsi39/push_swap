# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 19:06:57 by dfranke           #+#    #+#              #
#    Updated: 2022/01/22 01:28:46 by dfranke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS:= push_swap
FILE_PS:= ft_push_swap

NAME_CH:= checker
FILE_CH:= ft_checker

FILES:= \
		parse \
		fill_stack \
		free_terminate \
		sx_rx_rrx \
		push \
		managers \
		utils \
		sort_3_10 \
		sort_500 \
		index_a \
		print_stack

#-------libft--------
LIBFT_DIR:=./libft/

CC:=gcc -g
SOURCES_DIR:=srcs/
HEADER_DIR:=includes/
OBJECTS_DIR:=objs/
IFLAGS:=-I $(HEADER_DIR) -I $(LIBFT_DIR)includes
LFLAGS:=-L $(LIBFT_DIR) -lft
CFLAGS:=-Wall -Werror -Wextra $(IFLAGS)

#------Paths---------
SOURCES:=$(addprefix $(SOURCES_DIR),$(addsuffix .c,$(FILES)))
SOURCES_PS:=$(addprefix $(SOURCES_DIR),$(addsuffix .c,$(FILE_PS)))
SOURCES_CH:=$(addprefix $(SOURCES_DIR),$(addsuffix .c,$(FILE_CH)))

OBJECTS:=$(addprefix $(OBJECTS_DIR),$(addsuffix .o,$(FILES)))
OBJECTS_PS:=$(addprefix $(OBJECTS_DIR),$(addsuffix .o,$(FILE_PS)))
OBJECTS_CH:=$(addprefix $(OBJECTS_DIR),$(addsuffix .o,$(FILE_CH)))
#====================

#------Colors--------
BLACK:="\033[1;30m"
RED:="\033[1;31m"
BGREEN:="\033[1;32m"
GREEN:="\033[0;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
#====================
CACHE:=.cache_exists

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(OBJECTS) $(OBJECTS_PS)
	@cd $(LIBFT_DIR) && $(MAKE)
	@echo $(PURPLE) " -> Compiling $@" $(RED)
	@$(CC) $(CFLAGS) $(LFLAGS) $(SOURCES) $(SOURCES_PS) -o $@
	@echo $(BGREEN) " -> OK" $(EOC)

$(NAME_CH): $(OBJECTS) $(OBJECTS_CH)
	@echo $(PURPLE) " -> Compiling $@" $(RED)
	@$(CC) $(CFLAGS) $(LFLAGS) $(SOURCES) $(SOURCES_DIR)$(FILE_CH).c -o $@
	@echo $(BGREEN) " -> OK" $(EOC)

$(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c | $(CACHE)
	@echo $(CYAN) " -> Compiling $< into $@" $(EOC)
	@$(CC) $(CFLAGS) -c $< -o $@

%.c:
	@echo $(RED)"Missing file : $@" $(EOC)

$(CACHE):
	@mkdir -p $(OBJECTS_DIR)
	@touch $(CACHE)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -f $(CACHE)
	@rm -rf $(OBJECTS_DIR)
	@echo $(GREEN) "-> $(NAME_PS) cache cleaned"
	@echo $(GREEN) "-> $(NAME_CH) cache cleaned"

fclean: clean
	@rm -f $(NAME_PS)
	@rm -f $(NAME_CH)
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@echo $(BRED) " -> $(NAME_PS) deleted"
	@echo $(BRED) " -> $(NAME_CH) deleted"

re:
	@$(MAKE) fclean
	@$(MAKE) all

print: 
	@echo "$(CC) $(CFLAGS) $(LFLAGS) $(SOURCES) $(SOURCES_PS) -o $@"

.PHONY: all clean fclean re

norm:
	@norminette -R CheckForbiddenSourceHeader $(SOURCES) $(SOURCES_PS) $(SOURCES_CH) $(HEADER_DIR)