SRC = Source/main.c \
		Source/utils1.c \
		Source/utils2.c \
		Source/utils3.c \
		Source/utils4.c \
		Source/utils5.c \
		Source/utils6.c \
		Source/utils7.c \
		Source/utils8.c \
		Source/utils9.c \
		
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
	$(CC) $(FLAG) $(OBJ) $(LIB) $(MLX) -o $(NAME)

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
