SRC = Source/main.c \
		Source/read_init.c \
		Source/save_conf.c \
		Source/set_colorpath.c \
		Source/read_map.c \
		Source/split_space.c \
		Source/map_check.c \
		Source/start_game.c \
		Source/ft_keypress.c \
		Source/redraw.c \
		Source/raycasting.c \
		
NAME = cub3D

OBJ = $(SRC:.c=.o)

INC = ./Include

LIB_D =  ./libft

LIB = $(LIB_D)/libft.a

FLAG = -Wall -Wextra -Werror -g3

MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

CC = cc 

all : $(NAME) 

# $(NAME) : $(OBJ) | $(LIB) 
# 	$(CC) $(FLAG) $(OBJ) -L$(LIB_D) $(MLX) -o $(NAME)

$(NAME) : $(OBJ) | $(LIB) 
	@make -C mlx_linux
	$(CC) $(FLAG) $(OBJ) $(LIB) $(MLX) -o $(NAME)

%.o : %.c
	$(CC) $(FLAG) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIB) :
	@make -C $(LIB_D) 

clean :
	rm -f $(OBJ)
	@make -C libft clean

fclean:
	rm -f $(OBJ) $(NAME)
	@make -C libft fclean

re : fclean all

.PHONY: all clean fclean re
