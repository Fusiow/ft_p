CC			=
CFLAGS		=
LDFLAGS		=

FILES		=

SRC			= $(addprefix $(FILES), src/)
OBJ			= $(FILES:%.c=obj/%.o)

# Colors
NO_COLOR	= \x1b[0m
GREEN		= \x1b[32;01m
RED			= \x1b[31;01m
YELLOW		= \x1b[33m
GRAY		= \x1b[37;01m

.PHONY: all re clean fclean

all:
	@make -C serveur_dir
	@make -C client_dir

client:
	@make -C client_dir

serveur:
	@make -C serveur_dir

clean:
	@make clean -C serveur_dir
	@make clean -C client_dir

fclean:
	@make fclean -C serveur_dir
	@make fclean -C client_dir

re: fclean all

