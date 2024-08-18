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

void	set_str(int fd, t_md *md)
{
	char	buf[5];
	int		read_return;
	int		index;

	read_return = 5;
	md->str = malloc(sizeof(char) * 1);
	if (md->str == NULL)
		return ;
	md->str[0] = '\0';
	while (read_return == 5)
	{
		read_return = read(fd, buf, 5);
		buf[read_return] = '\0';
		md->str = join_s(md->str, buf);
	}
	index = 0;
	while (1)
	{
		if (md->str[index] == '\n' || md->str[index] == '\0')
			md->row_size++;
		if (md->str[index] == '\0')
			break ;
		index++;
	}
	md->col_size = index / md->row_size;
}

void	set_c_map(t_md *md)
{
	int	r;
	int	c;
	int	index;

	r = 0;
	index = 0;
	md->cm = malloc(sizeof(char *) * md->row_size);
	if (md->cm == NULL)
		return ;
	while (r < md->row_size)
	{
		md->cm[r] = malloc(sizeof(char) * md->col_size);
		if (md->cm[r] == NULL)
		{
			while (r-- >= 0)
				free(md->cm[r]);
			free(md->cm);
			return ;
		}
		r++;
	}
	r = 0;
	index = 0;
	fill_c_map(r, index, md);
}

void	fill_c_map(int r, int index, t_md *md)
{
	int	c;

	while (r < md->row_size)
	{
		c = 0;
		while (c < md->col_size)
			md->cm[r][c++] = md->str[index++];
		index++;
		r++;
	}
}

void	set_v_map(t_md *md)
{
	int	r;
	int	c;
	int	index;

	r = 0;
	index = 0;
	md->vm = malloc(sizeof(char *) * md->row_size);
	if (md->vm == NULL)
		return ;
	while (r < md->row_size)
	{
		md->vm[r] = malloc(sizeof(char) * md->col_size);
		if (md->vm[r] == NULL)
		{
			while (r-- >= 0)
				free(md->vm[r]);
			free(md->vm);
			return ;
		}
		r++;
	}
	r = 0;
	index = 0;
	fill_v_map(r, index, md);
}

void	fill_v_map(int r, int index, t_md *md)
{
	int	c;

	while (r < md->row_size)
	{
		c = 0;
		while (c < md->col_size)
			md->vm[r][c++] = md->str[index++];
		index++;
		r++;
	}
}
