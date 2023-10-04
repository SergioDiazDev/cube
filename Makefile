NAME			=	cub3d
ifeq ($(shell uname), Darwin)
	CFLAGS			=	-Wall -Werror -Wextra -g3
	INCLUDE			=	-DEBUG=1 -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
	
else
	CFLAGS			=	-Wall -Werror -ldl -Wextra -g3
	INCLUDE			=	-DEBUG=1 -Iinclude -lglfw -L"usr/lib/x86_64-linux-gnu/"
endif
RM				=	rm -fr
DIR_MAKE_MLX	=	./MLX42
DIR_SRC			=	./src/
SRC				= 	$(DIR_SRC)main.c $(DIR_SRC)hooks.c $(DIR_SRC)rayCaster.c $(DIR_SRC)paint.c
# COLORS
GREEN = `tput setaf 2`
RED = `tput setaf 1`
RESET = `tput sgr0`

$(TRUE).SILENT:

OBJ				=	$(SRC:.c=.o)

all: make_mlx $(NAME)

make_mlx:
			@$(MAKE) -C $(DIR_MAKE_MLX)

$(NAME):	$(OBJ)
			@gcc $(CFLAGS) $(SRC) -o $(NAME) $(DIR_MAKE_MLX)/libmlx42.a $(INCLUDE)
			@echo "$(GREEN)CREATE $(NAME)$(RESET)"

re:		fclean all

clean:
		@$(MAKE) -s clean -C $(DIR_MAKE_MLX)
		@$(RM) $(OBJ)
		@echo "$(RED)REMOVE OBJECTS $(NAME)$(RESET)\n"

fclean:		clean
			@$(MAKE) -s fclean -C $(DIR_MAKE_MLX)
			@$(RM) $(NAME) $(NAME).dSYM
			@echo "$(RED)DELETE $(NAME)$(RESET)\n"

.PHONY: 	all make_mlx re clean fclean
