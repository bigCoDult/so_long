/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:55:12 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/17 12:11:16 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	validate_map(t_m_d *m_d)
{
	if (!is_proper_chars(m_d))
		printf("[not proper char]\n");
	if (!is_square(m_d))
	{
		printf("[not box]\n");
		return (false);
	}
	if (!is_w(m_d))
		printf("[not wall box]\n");
	if (is_square(m_d) && is_w(m_d) && is_proper_chars(m_d))
		return (true);
	return (false);
}

bool	is_square(t_m_d *m_d)
{
	int	i;
	int	fst_l;
	int	now;

	i = 0;
	fst_l = 0;
	now = 0;
	while (m_d->str[fst_l] != '\n' && m_d->str[fst_l] != '\0')
		fst_l++;
	i = fst_l + 1;
	while (m_d->str[i] != '\0')
	{
		now = i;
		while (m_d->str[now] != '\n' && m_d->str[now] != '\0')
			now++;
		if (now - i != fst_l)
			return (false);
		i += fst_l;
		if (m_d->str[i] == '\n')
			i++;
	}
	return (true);
}

bool	is_w(t_m_d *m_d)
{
	int	i;
	int	fst_l;
	int	now;

	i = 0;
	fst_l = 0;
	now = 0;
	while (m_d->str[fst_l] != '\n' && m_d->str[fst_l] != '\0')
		fst_l++;
	while (i < fst_l)
	{
		if (m_d->str[i] != W)
		{
			printf("not horizental WALL\n");
			return (false);
		}
		i++;
	}
	int col_size = i / fst_l;
	while (m_d->str[i] != '\0')
	{
		i++;
		//문제라인
		if (m_d->str[i] != W || m_d->str[i + fst_l - 1] != W)
			return (false);
		//문제라인
		i += fst_l;
	}
	while(m_d->str[i] != '\0')
		i++;
	printf("i: %d\n", i);
	i -= fst_l;
	printf("i: %d\n", i);
	// while (m_d->str[i] != '\0')
	while (fst_l--)
	{
		if (m_d->str[i] != W)
		{
			printf("not horizental WALL\n");
			return (false);
		}
		i++;
	}
	printf("i: %d\n", i);
	if (m_d->str[i] != '\0')
	{
		printf("not null\n");
		return (false);
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
