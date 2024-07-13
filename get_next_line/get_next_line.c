/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:18:25 by sanbaek           #+#    #+#             */
/*   Updated: 2024/06/23 14:18:26 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_etc	*etc;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (etc == NULL)
	{
		etc = (t_etc *)malloc(sizeof(t_etc));
		if (etc == NULL)
			return (NULL);
		init_etc(etc);
	}
	if (deal_buf(etc, fd) == 0)
		return (NULL);
	return (set_one_s(etc));
}

size_t	deal_buf(t_etc *etc, int fd)
{
	etc->buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (etc->buf == NULL)
	{
		free_etc(etc);
		etc = NULL;
		return (0);
	}
	if (set_buf(etc, fd) == 0 && etc->st_s[etc->i_st_s] == '\0')
	{
		free_etc(etc);
		etc = NULL;
		return (0);
	}
	free(etc->buf);
	etc->buf = NULL;
	return (1);
}

void	init_etc(t_etc *etc)
{
	etc->st_s = (char *)malloc(sizeof(char));
	if (etc->st_s == NULL)
		return ;
	etc->st_s[0] = '\0';
	etc->is_there_newline = false;
	etc->one_s = NULL;
	etc->i_st_s = 0;
	etc->i_one_s = 0;
	etc->i_buf = 0;
	return ;
}

void	free_etc(t_etc *etc)
{
	if (etc->st_s != NULL)
	{
		free(etc->st_s);
		etc->st_s = NULL;
	}
	if (etc->buf != NULL)
	{
		free(etc->buf);
		etc->buf = NULL;
	}
	free(etc);
}

size_t	ft_strlen(char *s)
{
	size_t	length;

	length = 0;
	while (s && s[length] != '\0')
		length++;
	return (length);
}
