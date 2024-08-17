/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:51:06 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/16 13:51:06 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	fd;

	fd = open("map.ber", O_RDONLY);
	so_long(fd);
	close(fd);
	return (0);
}

void	so_long(int fd)
{
	t_tot	*tot;

	tot = malloc(sizeof(t_tot));
	if (tot == NULL)
		return ;
	tot->w_d = malloc(sizeof(t_w_d));
	if (tot->w_d == NULL)
		return ;
	tot->m_d = malloc(sizeof(t_m_d));
	if (tot->m_d == NULL)
		return ;
	tot->m_d->row_size = 0;
	tot->m_d->col_size = 0;
	set_str(fd, tot->m_d);
	init_w_d(tot);
	if (deal_map(tot))
		key_hook(tot);
	mlx_loop(tot->w_d->m_p);
	end_game(tot);
}

void	init_w_d(t_tot *tot)
{
	tot->w_d->title = "so_long";
	tot->w_d->size_x = tot->m_d->col_size * 20;
	tot->w_d->size_y = tot->m_d->row_size * 20;
	tot->w_d->m_p = mlx_init();
	tot->w_d->w_p = mlx_new_window(\
	tot->w_d->m_p, tot->w_d->size_x, tot->w_d->size_y, tot->w_d->title);
	return ;
}

t_cor	get_cor(t_m_d *m_d, char c)
{
	t_cor	person;

	person = (t_cor){0, 0};
	person.r = 0;
	person.c = 0;
	while (person.r < m_d->row_size)
	{
		person.c = 0;
		while (person.c < m_d->col_size)
		{
			if (m_d->c_map[person.r][person.c] == c)
				return (person);
			person.c++;
		}
		person.r++;
	}
	return ((t_cor){-1, -1});
}

void	draw_map(t_tot	*tot)
{
	int		index;
	t_cor	cor;

	index = 0;
	cor = (t_cor){0, 0};
	while (cor.r < tot->m_d->row_size)
	{
		cor.c = 0;
		while (cor.c < tot->m_d->col_size)
		{
			if (tot->m_d->c_map[cor.r][cor.c] == W)
				// mlx_put_image_to_window (tot->w_d->m_p, tot->w_d->w_p, tot->t_d->rock, T_L * cor.c++, T_L * cor.r);
				p_im(tot->w_d->m_p, tot->w_d->w_p, tot->t_d->rock, T_L * cor.c++, T_L * cor.r);
			else if (tot->m_d->c_map[cor.r][cor.c] == Z)
				mlx_put_image_to_window (tot->w_d->m_p, tot->w_d->w_p, \
				tot->t_d->grass, T_L * cor.c++, T_L * cor.r);
			else if (tot->m_d->c_map[cor.r][cor.c] == P)
				mlx_put_image_to_window (tot->w_d->m_p, tot->w_d->w_p, \
				tot->t_d->person, T_L * cor.c++, T_L * cor.r);
			else if (tot->m_d->c_map[cor.r][cor.c] == C)
				mlx_put_image_to_window (tot->w_d->m_p, tot->w_d->w_p, \
				tot->t_d->chest, T_L * cor.c++, T_L * cor.r);
			else if (tot->m_d->c_map[cor.r][cor.c] == E)
				mlx_put_image_to_window (tot->w_d->m_p, tot->w_d->w_p, \
				tot->t_d->door, T_L * cor.c++, T_L * cor.r);
		}
		cor.r++;
	}
}
void p_im(void *mlx, void *win, void *img, int x, int y)
{
	mlx_put_image_to_window(mlx, win, img, x, y);
}

void	*init_tiles(t_tot	*tot)
{
	tot->t_d = malloc(sizeof(t_t_d));
	if (tot->t_d == NULL)
		return (NULL);
	tot->t_d->rock = open_xpm(tot->w_d, NULL, "rock");
	tot->t_d->grass = open_xpm(tot->w_d, NULL, "grass");
	tot->t_d->person = open_xpm(tot->w_d, NULL, "person");
	tot->t_d->chest = open_xpm(tot->w_d, NULL, "chest");
	tot->t_d->door = open_xpm(tot->w_d, NULL, "door");
	return (NULL);
}

int	deal_map(t_tot	*tot)
{
	t_cor	person;

	if (!validate_map(tot->m_d))
	{
		mlx_loop_end(tot->w_d->m_p);
		return (0);
	}
	set_c_map(tot->m_d);
	set_v_map(tot->m_d);
	person = get_cor(tot->m_d, P);
	tot->m_d->possible = is_possible(tot->m_d, person);
	if (!tot->m_d->possible)
	{
		printf("[impossible map]\n");
		mlx_loop_end(tot->w_d->m_p);
		return (0);
	}
	init_tiles(tot);
	return (1);
}
