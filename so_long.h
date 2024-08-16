#ifndef SO_LONG_H
# define SO_LONG_H
# define W '1'
# define Z '0'
# define P 'P'
# define C 'C'
# define E 'E'
# define T_L 20
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

typedef struct s_w_d
{
	void		*m_p;
	void		*w_p;
	char		*title;
	size_t	size_y;
	size_t	size_x;
}	t_w_d;

typedef struct s_t_d
{
	void	*rock;
	void	*grass;
	void	*person;
	void	*chest;
	void	*door;
}	t_t_d;


typedef struct s_cor
{
	int	r;
	int	c;
}	t_cor;

typedef struct s_m_d
{
	char		**c_map;
	char		**vali_map;
	char		*str;
	size_t	row_size;
	size_t	col_size;
	int		c_c;
	int		possible;
	t_cor	exit;
	int step;
}	t_m_d;

typedef struct s_tot
{
	t_w_d	*w_d;
	t_t_d	*t_d;
	t_m_d	*m_d;
	}	t_tot;


void	so_long(int fd);
void	init_w_d(t_tot *tot);

void	*set_str(int fd, t_m_d *m_d);
int	deal_map(t_tot	*tot);
void	*set_c_map(t_m_d *m_d);
void	*set_vali_map(t_m_d *m_d);

void	*init_tiles(t_tot	*tot);
void	draw_map(t_tot	*tot);

size_t	ft_strlen(char *s);
char	*template_literal(char *line, char *word, int location);
char	*join_s_till_c(char *s1, char *s2, char c);
char	*join_s(char *st_s, char *buf);
void	*open_xpm(t_w_d *w_d, void *single_tile, char *tile_name);

bool	validate_map(t_m_d *m_d);
bool	is_square(t_m_d *m_d);
bool	is_w(t_m_d *m_d);
bool	is_proper_chars(t_m_d *m_d);

t_cor	get_cor(t_m_d *m_d, char c);
bool	is_possible(t_m_d *m_d, t_cor person);

void	key_hook(t_tot *tot);
int move_person(int key, void *param);
int move_way(int key, t_cor person, t_tot *tot);
void	destroy_tiles(t_tot *tot);
int end_game(t_tot *tot);


#endif /* SO_LONG_H */