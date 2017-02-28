# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkharif <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/28 10:51:30 by rkharif           #+#    #+#              #
#*   Updated: 2017/02/28 10:51:32 by rkharif          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME		= client
CC			= clang
CFLAGS		= -Wall -Wextra -Werror -I include -I ../libft/include
LDFLAGS		= -L../libft -lft

FILES		= main.c command.c command2.c command3.c client.c

SRC			= $(addprefix $(FILES), src/)
OBJ			= $(FILES:%.c=obj/%.o)

# Colors
NO_COLOR	= \x1b[0m
GREEN		= \x1b[32;01m
RED			= \x1b[31;01m
YELLOW		= \x1b[33m
GRAY		= \x1b[37;01m

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(GRAY)Creating $(RED)$(NAME)$(NO_COLOR)"
	@$(CC) $(LDFLAGS) $(OBJ) -o $(NAME)
	@if [ -a $(NAME) ] ; \
	then \
		printf "\e[42G$(GREEN)✓$(NO_COLOR)\n" ; \
	fi;

obj/%.o: src/%.c include
	@if ! [ -a ../libft/libft.a ] ; \
	then \
		printf "$(GRAY)Compiling $(RED)libft$(NO_COLOR)\n" ; \
		make -C ../libft ; \
	fi;

	@mkdir -p obj
	@printf "$(YELLOW)$< $(NO_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@if [ -a $@ ] ; \
	then \
		printf "\e[42G$(GREEN)✓$(NO_COLOR)\n" ; \
	fi;

clean:
	@printf "$(GRAY)Removing objects$(NO_COLOR)"
	@rm -rf obj
	@printf "\e[42G$(GREEN)✓$(NO_COLOR)\n"

fclean: clean
	@printf "$(GRAY)Removing $(RED)$(NAME)$(NO_COLOR)"
	@rm -f $(NAME)
	@printf "\e[42G$(GREEN)✓$(NO_COLOR)\n"

re: fclean all
