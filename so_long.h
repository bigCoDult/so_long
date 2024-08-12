#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL '1'
# define EMPTY '0'
# define PERSON 'P'
# define COLLECT 'C'
# define EXIT 'E'
# define TILE_LEN 20
#	define KEY_W     119
#	define KEY_S     115
#	define KEY_A     97
#	define KEY_D     100
#	define KEY_LEFT  65361
#	define KEY_UP    65362
#	define KEY_RIGHT 65363
#	define KEY_DOWN  65364
#	define KEY_DOWN  65364
#	define KEY_ESC   65307
#	define KEY_SPACE 32
#	define CLICK_X 17

# include <stdio.h>
#	include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
#	include "./minilibx-linux/mlx.h"

typedef struct s_win_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*title;
	size_t	size_y;
	size_t	size_x;
}	t_win_data;

typedef struct s_tile_data
{
	void	*rock;
	void	*grass;
	void	*person;
	void	*chest;
	void	*door;
	int		***tile_location;
}	t_tile_data;

typedef struct s_map_data
{
	void		***tile_map;
	char		**char_amp;
	char		*map_str;
	size_t	row_size;
	size_t	col_size;
}	t_map_data;

typedef struct s_cordi
{
	int	row;
	int	col;
}	t_cordi;

typedef struct s_total_data
{
	t_win_data	*win_data;
	t_tile_data	*tile_data;
	t_map_data	*map_data;
	}	t_total_data;


void	so_long(int fd);
void	init_win_data(t_total_data *total_data);
void	deal_map(t_total_data	*total_data);
void	draw_tile_map(t_total_data	*total_data);
void	*set_tile_map(t_total_data	*total_data);
void	*set_tile_location(t_total_data	*total_data);
void	*set_map_str(int fd, t_total_data *total_data);
// void	*open_xpm(t_win_data *win_data, void *single_tile, char *tile_name);
size_t	ft_strlen(char *s);
char	*template_literal(char *line, char *word, int location);
char	*join_s_till_c(char *s1, char *s2, char c);
char	*join_s(char *st_s, char *buf);
// bool	validate_map(t_total_data *total_data);
bool	is_square(t_map_data *map_data);
bool	is_wall(t_map_data *map_data);
bool	is_proper_chars(t_map_data *map_data);

// bool	is_square(t_total_data *total_data);
// bool	is_wall(t_map_data *map_data);
// int					is_there(char *map_str, char c);
// bool				is_possible(t_char_map *char_map, t_cordi *person);
// bool				backtracking(t_char_map *char_map);
// t_cordi			*get_cordi(t_char_map *char_map, char c);

#endif /* SO_LONG_H */