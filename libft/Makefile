NAME		= libft.a
CFLAGS		= -Wall -Wextra -Werror -I include

FILES		=	memset.c		\
				bzero.c			\
				memcpy.c		\
				memccpy.c		\
				memmove.c		\
				memchr.c		\
				memcmp.c		\
				\
				strlen.c		\
				strdup.c		\
				strcpy.c		\
				strncpy.c		\
				strcat.c		\
				strncat.c		\
				strlcat.c		\
				strchr.c		\
				strrchr.c		\
				strstr.c		\
				strnstr.c		\
				strcmp.c		\
				strncmp.c		\
				\
				atoi.c			\
				isalpha.c		\
				isdigit.c		\
				isalnum.c		\
				isascii.c		\
				isprint.c		\
				toupper.c		\
				tolower.c		\
				\
				memalloc.c		\
				memdel.c		\
				strnew.c		\
				strdel.c		\
				strclr.c		\
				striter.c		\
				striteri.c		\
				strmap.c		\
				strmapi.c		\
				strequ.c		\
				strnequ.c		\
				strsub.c		\
				strjoin.c		\
				strtrim.c		\
				strtrimall.c	\
				strsplit.c		\
				itoa.c			\
				\
				putchar.c		\
				putstr.c		\
				putendl.c		\
				putnbr.c		\
				putchar_fd.c	\
				putstr_fd.c		\
				putendl_fd.c	\
				putnbr_fd.c		\
				\
				lstnew.c		\
				lstdelone.c		\
				lstdel.c		\
				lstadd.c		\
				lstappend.c		\
				lstiter.c		\
				lstmap.c		\

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
