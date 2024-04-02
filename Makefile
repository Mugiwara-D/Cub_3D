SRC = Source/main.c \
		
NAME = cub3D

OBJ = $(SRC:.c=.o)

INC = ./Include

LIB_D =  ./libft

LIB = $(LIB_D)/libft.a

FLAG = -Wall -Wextra -Werror

MLX = -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz

CC = cc 

all : $(NAME) 

$(NAME) : $(OBJ) | $(LIB) 
	$(CC) $(FLAG) $(OBJ) -L$(LIB_D) $(MLX) -o $(NAME)
	
%.o : %.c
	$(CC) $(FLAG) -I/usr/include -Iminilibx-linux -O3 -c $< -o $@

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
