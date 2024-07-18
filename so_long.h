#ifndef SO_LONG_H
# define SO_LONG_H
// # define NAME_TO_STRING(x) #x
# define WALL '1'
# define EMPTY '0'
# define PERSON 'E'
# define COLLECT 'C'
# define EXIT 'E'

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

typedef struct s_cordi
{
	int	row;
	int	col;
}	t_cordi;

typedef struct s_tile
{
	void	*rock;
	void	*grass;
	void	*person;
	void	*chest;
	void	*door;
	int		***tile_location;
}	t_tile;

typedef struct s_char_map
{
	char	**map_cordi;
	size_t	row_size;
	size_t	col_size;
}	t_char_map;

typedef struct s_tile_map
{
	void	***tile_map;
	size_t	row_size;
	size_t	col_size;
}	t_tile_map;

void		so_long(int fd);

void		init_win_data(t_win_data *win_data);

void		deal_map(t_win_data *win_data);
void	***set_tile_map(t_win_data *win_data, t_tile *tile_data, t_char_map *char_map);
void		draw_tile_map(t_win_data *win_data, t_tile *tile_data, void	***map);

t_tile	*init_tiles(t_win_data *win_data);
int			***set_tile_location(void);
void		*open_xpm(t_win_data *win_data, void *single_tile, char *tile_name);

size_t	ft_strlen(char *s);
char		*template_literal(char *line, char *word, int location);
char	*join_s_till_c(char *s1, char *s2, char c);
char	*join_s(char *st_s, char *buf);

t_char_map *validate_map(void);
bool	is_square(char *map_str);
bool	is_wall(char *map_str);
int		is_there(char *map_str, char c);
t_char_map	*set_map_str_to_arr(char *map_str);


bool	backtracking(t_char_map *char_map);
t_cordi	*get_cordi(t_char_map *char_map, char c);
bool	is_possible(t_char_map *char_map, t_cordi *person)


#endif /* SO_LONG_H */