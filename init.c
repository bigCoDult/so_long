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

void	set_str(int fd, t_m_d *m_d)
{
	char	buf[5];
	int		read_return;
	int		index;

	read_return = 5;
	m_d->str = malloc(sizeof(char) * 1);
	if (m_d->str == NULL)
		return ;
	m_d->str[0] = '\0';
	while (read_return == 5)
	{
		read_return = read(fd, buf, 5);
		buf[read_return] = '\0';
		m_d->str = join_s(m_d->str, buf);
	}
	index = 0;
	while (1)
	{
		if (m_d->str[index] == '\n' || m_d->str[index] == '\0')
			m_d->row_size++;
		if (m_d->str[index] == '\0')
			break ;
		index++;
	}
	m_d->col_size = index / m_d->row_size;
}

void	set_c_map(t_m_d *m_d)
{
	int	r;
	int	c;
	int	index;

	r = 0;
	index = 0;
	m_d->c_map = malloc(sizeof(char *) * m_d->row_size);
	if (m_d->c_map == NULL)
		return ;
	while (r < m_d->row_size)
	{
		m_d->c_map[r] = malloc(sizeof(char) * m_d->col_size);
		if (m_d->c_map[r] == NULL)
		{
			while (r-- >= 0)
				free(m_d->c_map[r]);
			free(m_d->c_map);
			return ;
		}
		r++;
	}
	r = 0;
	index = 0;
	fill_c_map(r, index, m_d);
}

void	fill_c_map(int r, int index, t_m_d *m_d)
{
	int	c;

	while (r < m_d->row_size)
	{
		c = 0;
		while (c < m_d->col_size)
			m_d->c_map[r][c++] = m_d->str[index++];
		index++;
		r++;
	}
}

void	set_v_map(t_m_d *m_d)
{
	int	r;
	int	c;
	int	index;

	r = 0;
	index = 0;
	m_d->vali_map = malloc(sizeof(char *) * m_d->row_size);
	if (m_d->vali_map == NULL)
		return ;
	while (r < m_d->row_size)
	{
		m_d->vali_map[r] = malloc(sizeof(char) * m_d->col_size);
		if (m_d->vali_map[r] == NULL)
		{
			while (r-- >= 0)
				free(m_d->vali_map[r]);
			free(m_d->vali_map);
			return ;
		}
		r++;
	}
	r = 0;
	index = 0;
	fill_v_map(r, index, m_d);
}

void	fill_v_map(int r, int index, t_m_d *m_d)
{
	int	c;

	while (r < m_d->row_size)
	{
		c = 0;
		while (c < m_d->col_size)
			m_d->vali_map[r][c++] = m_d->str[index++];
		index++;
		r++;
	}
}
