/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 22:21:15 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/17 22:21:15 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define W '1'
# define Z '0'
# define P 'P'
# define C 'C'
# define E 'E'
# define T 20
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define CLICK_X 17

# include <X11/X.h>
# include <X11/keysym.h>

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "./minilibx-linux/mlx.h"
# include <stdbool.h>

typedef struct s_wd
{
	void	*mp;
	void	*wp;
	char	*title;
	int		size_y;
	int		size_x;
}	t_wd;

typedef struct s_t_d
{
	void	*r;
	void	*g;
	void	*p;
	void	*h;
	void	*d;
}	t_t_d;

typedef struct s_cor
{
	int	r;
	int	c;
}	t_c;

typedef struct s_m_d
{
	char	**cm;
	char	**vm;
	char	*str;
	int		row_size;
	int		col_size;
	int		c_c;
	int		possible;
	t_c	exit;
	int		step;
}	t_m_d;

typedef struct s_tt
{
	t_wd	*wd;
	t_t_d	*td;
	t_m_d	*m_d;
}	t_tt;

void	so_long(int fd);
void	init_wd(t_tt *tt);
void	pi(void *mlx, void *win, void *img, t_c c);
void	set_str(int fd, t_m_d *m_d);
int		deal_map(t_tt	*tt);
void	set_c_map(t_m_d *m_d);
void	fill_c_map(int r, int index, t_m_d *m_d);
void	set_v_map(t_m_d *m_d);
void	fill_v_map(int r, int index, t_m_d *m_d);
void	*init_tiles(t_tt	*tt);
void	draw_map(t_tt	*tt);
int		ft_strlen(char *s);
char	*template_literal(char *line, char *word, int location);
char	*join_s_till_c(char *s1, char *s2, char c);
char	*join_s(char *st_s, char *buf);
void	*open_xpm(t_wd *wd, void *single_tile, char *tile_name);
bool	validate_map(t_m_d *m_d);
bool	is_square(t_m_d *m_d);
bool	is_w(t_m_d *m_d);
bool	is_proper_chars(t_m_d *m_d);
t_c	get_cor(t_m_d *m_d, char c);
bool	is_possible(t_m_d *m_d, t_c person);
void	key_hook(t_tt *tt);
int		move_person(int key, void *param);
int		close_window(void *param);
int		move_way(int key, t_c person, t_tt *tt);
void	destroy_tiles(t_tt *tt);
int		end_game(t_tt *tt);
t_c	get_way(int key, t_c person, t_c way, t_tt *tt);

#endif /* SO_LONG_H */