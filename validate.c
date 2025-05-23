/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:55:12 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/18 17:07:51 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_md *md)
{
	if (!is_proper_chars(md))
		ft_printf("[not proper char]\n");
	if (!is_square(md))
	{
		ft_printf("[not box]\n");
		return (0);
	}
	if (!is_wall(md))
		ft_printf("[not wall box]\n");
	if (is_square(md) && is_wall(md) && is_proper_chars(md))
		return (1);
	return (0);
}

int	is_square(t_md *md)
{
	int	i;
	int	fst_l;
	int	now;

	i = 0;
	fst_l = 0;
	now = 0;
	while (md->str[fst_l] != '\n' && md->str[fst_l] != '\0')
		fst_l++;
	i = fst_l + 1;
	while (md->str[i] != '\0')
	{
		now = i;
		while (md->str[now] != '\n' && md->str[now] != '\0')
			now++;
		if (now - i != fst_l)
			return (0);
		i += fst_l;
		if (md->str[i] == '\n')
			i++;
	}
	return (1);
}

int	is_wall(t_md *md)
{
	int	i;
	int	fst_l;

	i = 0;
	fst_l = 0;
	while (md->str[fst_l] != '\n' && md->str[fst_l] != '\0')
		fst_l++;
	while (i < fst_l)
	{
		if (md->str[i] != W)
			return (0);
		i++;
	}
	return (is_llaw(md, i, fst_l));
}

int	is_proper_chars(t_md *md)
{
	int	i;
	int	count_he;
	int	count_exit;

	i = 0;
	count_he = 0;
	count_exit = 0;
	md->c_c = 0;
	while (md->str[i] != '\0')
	{
		if (md->str[i] == P)
			count_he++;
		else if (md->str[i] == E)
			count_exit++;
		else if (md->str[i] == C)
			md->c_c++;
		else if (md->str[i] == W || md->str[i] == Z || md->str[i] == '\n')
			;
		else
			return (0);
		i++;
	}
	if (count_he != 1 || count_exit != 1 || md->c_c < 1)
		return (0);
	return (1);
}

int	is_possible(t_md *md, t_c he)
{
	if (he.r < 0 || he.r > md->row_size || he.c < 0 || he.c > md->col_size)
		return (0);
	if (md->c_c == 0)
	{
		if (md->vm[he.r][he.c] == W || md->vm[he.r][he.c] == '/')
			return (0);
		if (md->vm[he.r][he.c] == E)
			return (1);
		md->vm[he.r][he.c] = '/';
	}
	else
	{
		if (md->vm[he.r][he.c] == W || md->vm[he.r][he.c] == '\\')
			return (0);
		if (md->vm[he.r][he.c] == C)
			md->c_c--;
		if (md->vm[he.r][he.c] != E)
			md->vm[he.r][he.c] = '\\';
	}
	if (is_possible(md, (t_c){he.r + 1, he.c}) \
		|| is_possible(md, (t_c){he.r - 1, he.c}) \
		|| is_possible(md, (t_c){he.r, he.c + 1}) \
		|| is_possible(md, (t_c){he.r, he.c - 1}))
		return (1);
	return (0);
}
