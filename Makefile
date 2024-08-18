NAME = so_long.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O0
LDFLAGS = -L/usr/local/lib -lmlx -lX11 -lXext -lXrandr
AR = ar
ARFLAGS = rcs
RM = rm -f
INC = -I.
SRC = \
			so_long.c \
			util.c \
			init.c \
			validate.c \
			hook.c \
			draw.c \
			end.c \
			ft_printf.c \
			ft_pututils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
