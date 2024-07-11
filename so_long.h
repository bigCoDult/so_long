#ifndef SO_LONG_H
# define SO_LONG_H
# define NAME_TO_STRING(x) #x

# include <stdio.h>
#	include <stdlib.h>
#	include "./minilibx-linux/mlx.h"


typedef struct s_win_data
{
	char		*title;
	size_t	size_x;
	size_t	size_y;
	void		*mlx_ptr;
	void		*win_ptr;
	size_t	map[10][10];
}	t_win_data;

typedef struct s_tile
{
	void		*door;
	void		*chest;
	void		*grass;
	void		*rock;
}	t_tile;

void 		so_long(int fd);
void		init_win_data(t_win_data *win_data);
t_tile	*init_tile(t_win_data *win_data);
void		*set_tile(t_win_data *win_data, void *box, char *str);
size_t	ft_strlen(char *s);
char		*template_literal(char *line, char *word, int location);







#endif /* SO_LONG_H */