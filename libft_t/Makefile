# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/25 18:24:09 by dfranke           #+#    #+#              #
#    Updated: 2022/01/21 17:07:08 by dfranke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= libft.a
FILES:= \
		ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memccpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_strlen \
		ft_strlcpy \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strnstr \
		ft_strncmp \
		ft_atol \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_lstnew \
		ft_lstadd_front \
		ft_lstsize \
		ft_lstlast \
		ft_lstadd_back \
		ft_lstdelone \
		ft_lstclear \
		ft_lstiter \
		ft_lstmap \
		get_next_line \
		ft_isspace \
		ft_isstrnum \
		ft_isstrint \
		ft_strcmp

CC:=gcc
LINKER:=ar rc
SOURCES_DIR:=srcs/
HEADER_DIR:=includes/
OBJECTS_DIR:=objs/
IFLAGS:=-I $(HEADER_DIR)
CFLAGS:=-Wall -Werror -Wextra $(IFLAGS)

#------Paths---------
SOURCES:=$(addprefix $(SOURCES_DIR),$(addsuffix .c,$(FILES)))
OBJECTS:=$(addprefix $(OBJECTS_DIR),$(addsuffix .o,$(FILES)))
#====================


#------Colors--------
BLACK:="\033[1;30m"
RED:="\033[0;31m"
BRED:="\033[1;31m"
GREEN:="\033[0;32m"
PURPLE:="\033[0;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
#====================
CACHE:=.cache_exists

all:	$(NAME)

$(NAME): $(OBJECTS)
	@echo $(PURPLE) "\n  -> Compiling $@" $(RED)
	@$(LINKER) $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo $(GREEN) " -> OK" $(END)
	
$(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c | $(CACHE)
	@echo ".\c"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(CACHE):
	@mkdir -p $(OBJECTS_DIR)
	@touch $(CACHE)

fclean: clean
	@rm -f $(NAME)
	@echo $(BRED) "-> $(NAME) deleted"

clean:
	@rm -f $(CACHE)
	@rm -rf $(OBJECTS_DIR)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY:		all clean fclean re