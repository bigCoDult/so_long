#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL '1'
# define EMPTY '0'
# define PERSON 'E'
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

# include <stdio.h>
#	include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
#	include "./minilibx-linux/mlx.h"


typedef struct s_total_data
{
	t_win_data	*win_data;
	t_tile_data	*tile_data;
	t_char_map	*char_map;
	t_tile_map	*tile_map;
}	t_total_data;

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

typedef struct s_char_map
{
	char	**map_cordi;
	size_t	row_size;
	size_t	col_size;
}	t_char_map;

typedef struct s_tile_map
{
	void	***map_cordi;
	size_t	row_size;
	size_t	col_size;
}	t_tile_map;

typedef struct s_cordi
{
	int	row;
	int	col;
}	t_cordi;


void				so_long(int fd);
void				init_win_data(t_total_data *total_data);
void				deal_map(t_total_data	*total_data);
void 				draw_tile_map(t_total_data	*total_data);
void				*set_tile_map(t_total_data	*total_data);
void				*set_tile_location(t_total_data	*total_data);
t_char_map	*set_map_str_to_arr(char *map_str);
void				*open_xpm(t_win_data *win_data, void *single_tile, char *tile_name);
size_t			ft_strlen(char *s);
char				*template_literal(char *line, char *word, int location);
char				*join_s_till_c(char *s1, char *s2, char c);
char				*join_s(char *st_s, char *buf);
bool				validate_map(total_data);
bool				is_square(char *map_str);
bool				is_wall(char *map_str);
int					is_there(char *map_str, char c);
bool				is_possible(t_char_map *char_map, t_cordi *person);
bool				backtracking(t_char_map *char_map);
t_cordi			*get_cordi(t_char_map *char_map, char c);

#endif /* SO_LONG_H */