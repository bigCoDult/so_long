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

void	*set_str(int fd, t_m_d *m_d)
{
	int		read_return;
	char	buf[5];
	int		index;

	m_d->str = malloc(sizeof(char) * 1);
	if (m_d->str == NULL)
		return (NULL);
	m_d->str[0] = '\0';
	while (1)
	{
		read_return = read(fd, buf, 5);
		buf[read_return] = '\0';
		m_d->str = join_s(m_d->str, buf);
		if (read_return < 5)
			break ;
	}
	index = 0;
	m_d->row_size = 0;
	m_d->col_size = 0;
	while (1)
	{
		if (m_d->str[index] == '\n' || m_d->str[index] == '\0')
			m_d->row_size++;
		if (m_d->str[index] == '\0')
			break ;
		index++;
	}
	m_d->col_size = index / m_d->row_size;
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
	set_vali_map(tot->m_d);
	person = get_cor(tot->m_d, P);
	tot->m_d->possible = is_possible(tot->m_d, person);
	if (!tot->m_d->possible)
	{
		printf("[impossible]\n");
		mlx_loop_end(tot->w_d->m_p);
		return (0);
	}
	init_tiles(tot);
	return (1);
}

void	*set_c_map(t_m_d *m_d)
{
	int	r;
	int	c;
	int	index;

	r = 0;
	c = 0;
	index = 0;
	m_d->c_map = malloc(sizeof(char *) * m_d->row_size);
	if (m_d->c_map == NULL)
		return (NULL);
	while (r < m_d->row_size)
	{
		m_d->c_map[r] = malloc(sizeof(char) * m_d->col_size);
		if (m_d->c_map[r] == NULL)
		{
			while (r-- >= 0)
				free(m_d->c_map[r]);
			free(m_d->c_map);
			return (NULL);
		}
		r++;
	}
	r = 0;
	index = 0;
	while (r < m_d->row_size)
	{
		c = 0;
		while (c < m_d->col_size)
		{
			m_d->c_map[r][c] = m_d->str[index];
			index++;
			c++;
		}
		index++;
		r++;
	}
	return (NULL);
}

void	*set_vali_map(t_m_d *m_d)
{
	int	r;
	int	c;
	int	index;

	r = 0;
	c = 0;
	index = 0;
	m_d->vali_map = malloc(sizeof(char *) * m_d->row_size);
	if (m_d->vali_map == NULL)
		return (NULL);
	while (r < m_d->row_size)
	{
		m_d->vali_map[r] = malloc(sizeof(char) * m_d->col_size);
		if (m_d->vali_map[r] == NULL)
		{
			while (r-- >= 0)
				free(m_d->vali_map[r]);
			free(m_d->vali_map);
			return (NULL);
		}
		r++;
	}
	r = 0;
	index = 0;
	while (r < m_d->row_size)
	{
		c = 0;
		while (c < m_d->col_size)
		{
			m_d->vali_map[r][c] = m_d->str[index];
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
