/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:55:12 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/16 13:38:10 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	validate_map(t_map_d *map_d)
{
	if (is_square(map_d) && is_wall(map_d) && is_proper_chars(map_d))
		return (true);
	return (false);
}

bool	is_square(t_map_d *map_d)
{
	int	in;
	int	f_l;
	int	now;

	in = 0;
	f_l = 0;
	now = 0;
	while (map_d->map_str[f_l] != '\n' && map_d->map_str[f_l] != '\0')
		f_l++;
	in = f_l + 1;
	while (map_d->map_str[in] != '\0')
	{
		now = in;
		while (map_d->map_str[now] != '\n' && map_d->map_str[now] != '\0')
			now++;
		if (now - in != f_l)
			return (false);
		in += f_l;
		if (map_d->map_str[in] == '\n')
			in++;
	}
	return (true);
}

bool	is_wall(t_map_d *map_d)
{
	int	in;
	int	f_l;
	int	now;

	in = 0;
	f_l = 0;
	now = 0;
	while (map_d->map_str[f_l] != '\n' && map_d->map_str[f_l] != '\0')
		f_l++;
	while (in < f_l)
	{
		if (map_d->map_str[in] != WALL)
			return (false);
		in++;
	}
	while (map_d->map_str[in] != '\0')
	{
		in++;
		if (map_d->map_str[in] != WALL || map_d->map_str[in + f_l - 1] != WALL)
			return (false);
		in += f_l;
	}
	in -= f_l;
	while (map_d->map_str[in] != '\0')
	{
		if (map_d->map_str[in] != WALL)
			return (false);
		in++;
	}
	return (true);
}

bool	is_proper_chars(t_map_d *map_d)
{
	int in;
	int	count_person;
	int	count_exit;

	in = 0;
	count_person = 0;
	count_exit = 0;
	map_d->c_c = 0;
	while (map_d->map_str[in] != '\0')
	{
		if (map_d->map_str[in] == PERSON)
			count_person++;
		else if (map_d->map_str[in] == EXIT)
			count_exit++;
		else if (map_d->map_str[in] == COLLECT)
			map_d->c_c++;
		else if (map_d->map_str[in] == WALL || map_d->map_str[in] == EMPTY || map_d->map_str[in] == '\n')
			;
		else
			return (false);
		in++;
	}
	if (count_person != 1 || count_exit != 1 || map_d->c_c < 1)
		return (false);
	return (true);
}

bool	is_possible(t_map_d *map_d, t_cor person)
{
	if (person.r < 0 || person.r > map_d->row_size || person.c < 0 || person.c > map_d->col_size)
		return (false);
	if (map_d->c_c == 0)
	{
		if (map_d->vali_map[person.r][person.c] == WALL || map_d->vali_map[person.r][person.c] == '/')
			return (false);
		if (map_d->vali_map[person.r][person.c] == EXIT)
			return (true);
		map_d->vali_map[person.r][person.c] = '/';
	}
	else
	{
		if (map_d->vali_map[person.r][person.c] == WALL || map_d->vali_map[person.r][person.c] == '\\')
			return (false);
		if (map_d->vali_map[person.r][person.c] == COLLECT)
			map_d->c_c--;
		if (map_d->vali_map[person.r][person.c] != EXIT)
			map_d->vali_map[person.r][person.c] = '\\';
	}

	if (is_possible(map_d, (t_cor){person.r + 1, person.c}) \
		|| is_possible(map_d, (t_cor){person.r - 1, person.c}) \
		|| is_possible(map_d, (t_cor){person.r, person.c + 1}) \
		|| is_possible(map_d, (t_cor){person.r, person.c - 1}))
		return (true);
	return (false);
}
