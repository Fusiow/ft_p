NAME		= libft.a
CFLAGS		= -Wall -Wextra -Werror -I include

FILES		=	ft_memset.c		\
				ft_bzero.c			\
				ft_memcpy.c		\
				ft_memccpy.c		\
				ft_memmove.c		\
				ft_memchr.c		\
				ft_memcmp.c		\
				\
				ft_strlen.c		\
				ft_strdup.c		\
				ft_strcpy.c		\
				ft_strncpy.c		\
				ft_strcat.c		\
				ft_strncat.c		\
				ft_strlcat.c		\
				ft_strchr.c		\
				ft_strrchr.c		\
				ft_strstr.c		\
				ft_strnstr.c		\
				ft_strcmp.c		\
				ft_strncmp.c		\
				\
				ft_atoi.c			\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				\
				ft_memalloc.c		\
				ft_memdel.c		\
				ft_strnew.c		\
				ft_strdel.c		\
				ft_strclr.c		\
				ft_striter.c		\
				ft_striteri.c		\
				ft_strmap.c		\
				ft_strmapi.c		\
				ft_strequ.c		\
				ft_strnequ.c		\
				ft_strsub.c		\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_strtrimall.c	\
				ft_strsplit.c		\
				ft_itoa.c			\
				\
				ft_putchar.c		\
				ft_putstr.c		\
				ft_putendl.c		\
				ft_putnbr.c		\
				ft_putchar_fd.c	\
				ft_putstr_fd.c		\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c		\
				\
				ft_lstnew.c		\
				ft_lstdelone.c		\
				ft_lstdel.c		\
				ft_lstadd.c		\
				ft_lstappend.c		\
				ft_lstiter.c		\
				ft_lstmap.c		\

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
	@ar -cr $(NAME) $(OBJ)
	@if [ -a $(NAME) ] ; \
	then \
		printf "\e[42G$(GREEN)✓$(NO_COLOR)\n" ; \
	fi;

obj/%.o: src/%.c include
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
