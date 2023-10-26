CC = cc
LIB = -L./minilibx-linux
VPATH = ./srcs
FLAGS = -g -Werror -Wextra -Wall
NAME = fdf
SRC = read_file.c parse_data.c clean_buffers.c \
draw_map.c window_manager.c
OBJ = ./obj/
OBJS = $(SRC:%.c=${OBJ}%.o)
HDS = -I./minilibx-linux -I./includes
LIBS_FLAG = -lmlx_Linux -lXext -Lmlx_linux -Imlx_linux -lX11 -lz -L./utils/libft -lft -lm
LFT_PATH = ./utils/libft
MAIN = srcs/main.c

TMAIN_SIZES	=	srcs/test_main.c

all: make_lft $(NAME)
	@printf "\033[0;1;32m%s\033[0m\n" "Compiled successfully"

$(NAME): $(OBJS)
	@$(CC) $^ -I./includes $(MAIN) $(LIB) $(LIBS_FLAG) -o $(NAME) $(FLAGS)

${OBJ}%.o: %.c
	@mkdir -p ./obj
	$(CC) -c $< -o $@ $(HDS) $(FLAGS)

make_lft:
	make -C $(LFT_PATH)/src

clean:
	rm -rf $(OBJ)
	make clean -C $(LFT_PATH)/src

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LFT_PATH)/src

re: fclean all

.PHONY: clean fclean
