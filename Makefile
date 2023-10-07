#PROJECT NAME
NAME			=	cub3d

#FLAGS AND MLX INCLUDE
ifeq ($(shell uname), Darwin)
	CFLAGS			=	-Wall -Werror -Wextra -g3
	INCLUDE			=	-DEBUG=1 -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
	
else
	CFLAGS			=	-Wall -Werror -ldl -Wextra -g3
	INCLUDE			=	-DEBUG=1 -Iinclude -lglfw -L"usr/lib/x86_64-linux-gnu/"
endif

#SHORT NAMES
RM				=	rm -fr

# DIR SOURCES
SRCSFD = src/

# FOLDER'S NAMES
CUB3DFD = cub3d/
GNLFD = get_next_line/

# SOURCES
CUB3D_SRC = main.c hooks.c ray_caster.c paint.c map.c file_utils.c
GNLFD_SRC = get_next_line.c get_next_line_utils.c

#OBJECTS
OBJSFD = objs/
CUB3D_OBJS = $(addprefix $(OBJSFD)$(CUB3DFD), $(CUB3D_SRC:.c=.o))
GNL_OBJS = $(addprefix $(OBJSFD)$(GNLFD), $(GNLFD_SRC:.c=.o))

#HEADERS
HDRSFD = includes/
HDR = cub3d.h
HDRS = $(addprefix $(HDRSFD), $(HDR))

HDR_INC = -I./includes

#MLX PROGRAM
MLX = ./MLX42/libmlx42.a

#MLX DIR
MLX_DIR = ./MLX42

# COLORS
RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m

all: $(NAME)

${MLX}:
		@make -C $(MLX_DIR)

$(OBJSFD):
		@mkdir $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(OBJSFD)$(CUB3DFD): $(OBJSFD)
		@mkdir $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(OBJSFD)$(GNLFD): $(OBJSFD)
		@mkdir $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(OBJSFD)$(CUB3DFD)%.o: $(SRCSFD)$(CUB3DFD)%.c $(HDRS)
		@gcc $(CFLAGS) $(HDR_INC) -o $@ -c $<

$(OBJSFD)$(GNLFD)%.o: $(SRCSFD)$(GNLFD)%.c
		@gcc $(CFLAGS) -o $@ -c $<

${NAME}: ${MLX} $(OBJSFD)$(CUB3DFD) $(OBJSFD)$(GNLFD) ${GNL_OBJS} $(CUB3D_OBJS) $(HDRS)
		@gcc $(CFLAGS) $(CUB3D_OBJS) ${GNL_OBJS} $(MLX) -o $@ $(INCLUDE)
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ executable"

re:		fclean all

clean:
		@$(RM) $(OBJSFD)
		@echo "\t[ $(RED)✗$(NONE) ] $(OBJSFD) directory"
		@${MAKE} -s -C $(MLX_DIR) clean

fclean:		clean
			@$(RM) $(NAME) $(NAME).dSYM
			@echo "\t[ $(RED)✗$(NONE) ] $(NAME) executable"
			@${MAKE} -s -C $(MLX_DIR) fclean

.PHONY: 	all re clean fclean
