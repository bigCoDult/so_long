#ifndef SO_LONG_H
# define SO_LONG_H
# define NAME_TO_STRING(x) #x

# include <stdio.h>
#	include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
#	include "./minilibx-linux/mlx.h"


typedef struct s_win_data
{
	char		*title;
	size_t	size_x;
	size_t	size_y;
	void		*mlx_ptr;
	void		*win_ptr;
}	t_win_data;

typedef struct s_tile
{
	void	*door;
	void	*chest;
	void	*grass;
	void	*rock;
	int		***tile_location;
}	t_tile;

void		so_long(int fd);

void		init_win_data(t_win_data *win_data);

void		deal_map(t_win_data *win_data);
void		***set_map(t_win_data *win_data, t_tile *tile_data);
void		draw_map(t_win_data *win_data, t_tile *tile_data, void	***map);

t_tile	*init_tile(t_win_data *win_data);
int			***set_tile_location(void);
void		*open_xpm(t_win_data *win_data, void *single_tile, char *tile_name);

size_t	ft_strlen(char *s);
char		*template_literal(char *line, char *word, int location);
char	*join_s_till_c(char *s1, char *s2, char c);
char	*join_s(char *st_s, char *buf);

bool	validate_map(void);
bool is_square(char *map_str);
bool is_wall(char *map_str);
bool	is_possible(char *map_str);

#endif /* SO_LONG_H */