/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:55:12 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/16 16:42:42 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	validate_map(t_m_d *m_d)
{
	if (!is_square(m_d))
	{
		// free(m_d->str);
		return (false);
	}
	if (!is_w(m_d))
	{
		// free(m_d->str);
		// while (m_d->row_size--)
		// 	free(m_d->vali_map[m_d->row_size]);
		// free(m_d->vali_map);
		return (false);
	}
	if (!is_proper_chars(m_d))
	{
		// free(m_d->str);
		return (false);
	}
	return (true);
}

bool	is_square(t_m_d *m_d)
{
	int	i;
	int	f_line;
	int	now;

	i = 0;
	f_line = 0;
	now = 0;
	while (m_d->str[f_line] != '\n' && m_d->str[f_line] != '\0')
		f_line++;
	i = f_line + 1;
	while (m_d->str[i] != '\0')
	{
		now = i;
		while (m_d->str[now] != '\n' && m_d->str[now] != '\0')
			now++;
		if (now - i != f_line)
			return (false);
		i += f_line;
		if (m_d->str[i] == '\n')
			i++;
	}
	return (true);
}

bool	is_w(t_m_d *m_d)
{
	int	i;
	int	f_line;
	int	now;

	i = 0;
	f_line = 0;
	now = 0;
	while (m_d->str[f_line] != '\n' && m_d->str[f_line] != '\0')
		f_line++;
	while (i < f_line)
	{
		if (m_d->str[i] != W)
			return (false);
		i++;
	}
	while (m_d->str[i] != '\0')
	{
		i++;
		if (m_d->str[i] != W || m_d->str[i + f_line - 1] != W)
			return (false);
		i += f_line;
	}
	i -= f_line;
	while (m_d->str[i] != '\0')
	{
		if (m_d->str[i] != W)
			return (false);
		i++;
	}
	return (true);
}

bool	is_proper_chars(t_m_d *m_d)
{
	int	i;
	int	count_he;
	int	count_exit;

	i = 0;
	count_he = 0;
	count_exit = 0;
	m_d->c_c = 0;
	while (m_d->str[i] != '\0')
	{
		if (m_d->str[i] == P)
			count_he++;
		else if (m_d->str[i] == E)
			count_exit++;
		else if (m_d->str[i] == C)
			m_d->c_c++;
		else if (m_d->str[i] == W || m_d->str[i] == Z || m_d->str[i] == '\n')
			;
		else
			return (false);
		i++;
	}
	if (count_he != 1 || count_exit != 1 || m_d->c_c < 1)
		return (false);
	return (true);
}

bool	is_possible(t_m_d *m_d, t_cor he)
{
	if (he.r < 0 || he.r > m_d->row_size || he.c < 0 || he.c > m_d->col_size)
		return (false);
	if (m_d->c_c == 0)
	{
		if (m_d->vali_map[he.r][he.c] == W || m_d->vali_map[he.r][he.c] == '/')
			return (false);
		if (m_d->vali_map[he.r][he.c] == E)
			return (true);
		m_d->vali_map[he.r][he.c] = '/';
	}
	else
	{
		if (m_d->vali_map[he.r][he.c] == W || m_d->vali_map[he.r][he.c] == '\\')
			return (false);
		if (m_d->vali_map[he.r][he.c] == C)
			m_d->c_c--;
		if (m_d->vali_map[he.r][he.c] != E)
			m_d->vali_map[he.r][he.c] = '\\';
	}
	if (is_possible(m_d, (t_cor){he.r + 1, he.c}) \
		|| is_possible(m_d, (t_cor){he.r - 1, he.c}) \
		|| is_possible(m_d, (t_cor){he.r, he.c + 1}) \
		|| is_possible(m_d, (t_cor){he.r, he.c - 1}))
		return (true);
	return (false);
}
