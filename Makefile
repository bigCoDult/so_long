NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O0
RM = rm -fr
MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lX11 -lXext -lXrandr
INC = -I$(MLX_DIR) -I$(LIBFT_DIR)
SRC = \
			draw.c \
			end.c \
			hook.c \
			init.c \
			so_long.c \
			util.c \
			validate.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
