/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:09:42 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/16 14:09:42 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*set_str(int fd, t_m_d *map_d)
{
	int		read_return;
	char	buf[5];
	int		index;

	map_d->str = malloc(sizeof(char) * 1);
	if (map_d->str == NULL)
		return (NULL);
	map_d->str[0] = '\0';
	while (1)
	{
		read_return = read(fd, buf, 5);
		buf[read_return] = '\0';
		map_d->str = join_s(map_d->str, buf);
		if (read_return < 5)
			break ;
	}
	index = 0;
	map_d->row_size = 0;
	map_d->col_size = 0;
	while (1)
	{
		if (map_d->str[index] == '\n' || map_d->str[index] == '\0')
			map_d->row_size++;
		if (map_d->str[index] == '\0')
			break ;
		index++;
	}
	map_d->col_size = index / map_d->row_size;
	return (NULL);
}

int	deal_map(t_tot	*tot)
{
	t_cor	person;

	if (!validate_map(tot->map_d))
	{
		mlx_loop_end(tot->w_d->m_p);
		return (0);
	}
	init_tiles(tot);
	set_vali_map(tot->map_d);
	set_c_map(tot->map_d);
	person = get_cor(tot->map_d, P);
	if (!is_possible(tot->map_d, person))
		return (0);
	return (1);
}

void	*set_c_map(t_m_d *map_d)
{
	int	r;
	int	c;
	int	index;

	r = 0;
	c = 0;
	index = 0;
	map_d->c_map = malloc(sizeof(char *) * map_d->row_size);
	if (map_d->c_map == NULL)
		return (NULL);
	while (r < map_d->row_size)
	{
		map_d->c_map[r] = malloc(sizeof(char) * map_d->col_size);
		if (map_d->c_map[r] == NULL)
		{
			while (r-- >= 0)
				free(map_d->c_map[r]);
			free(map_d->c_map);
			return (NULL);
		}
		r++;
	}
	r = 0;
	index = 0;
	while (r < map_d->row_size)
	{
		c = 0;
		while (c < map_d->col_size)
		{
			map_d->c_map[r][c] = map_d->str[index];
			index++;
			c++;
		}
		index++;
		r++;
	}
	return (NULL);
}

void	*set_vali_map(t_m_d *map_d)
{
	int	r;
	int	c;
	int	index;

	r = 0;
	c = 0;
	index = 0;
	map_d->vali_map = malloc(sizeof(char *) * map_d->row_size);
	if (map_d->vali_map == NULL)
		return (NULL);
	while (r < map_d->row_size)
	{
		map_d->vali_map[r] = malloc(sizeof(char) * map_d->col_size);
		if (map_d->vali_map[r] == NULL)
		{
			while (r-- >= 0)
				free(map_d->vali_map[r]);
			free(map_d->vali_map);
			return (NULL);
		}
		r++;
	}
	r = 0;
	index = 0;
	while (r < map_d->row_size)
	{
		c = 0;
		while (c < map_d->col_size)
		{
			map_d->vali_map[r][c] = map_d->str[index];
			index++;
			c++;
		}
		index++;
		r++;
	}
	return (NULL);
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
