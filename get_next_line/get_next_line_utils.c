/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:18:33 by sanbaek           #+#    #+#             */
/*   Updated: 2024/06/23 14:18:34 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	set_buf(t_etc *etc, int fd)
{
	etc->is_there_newline = false;
	while (etc->is_there_newline == false)
	{
		etc->rtn_read = read(fd, etc->buf, BUFFER_SIZE);
		if (etc->rtn_read == 0)
			return (0);
		if (etc->rtn_read == -1)
			return (0);
		etc->buf[etc->rtn_read] = '\0';
		if (join_s(etc) == NULL)
			return (0);
		is_newline(etc);
	}
	return (1);
}

char	*set_one_s(t_etc *etc)
{
	etc->i_one_s = 0;
	while (etc->st_s[etc->i_st_s + etc->i_one_s] != '\0'
		&& etc->st_s[etc->i_st_s + etc->i_one_s++] != '\n')
		;
	etc->one_s = (char *)malloc((etc->i_one_s + 1) * sizeof(char));
	if (etc->one_s == NULL)
	{
		free_etc(etc);
		etc = NULL;
		return (NULL);
	}
	etc->i_one_s = 0;
	while (etc->st_s[etc->i_st_s] != '\0' && etc->st_s[etc->i_st_s] != '\n')
		etc->one_s[etc->i_one_s++] = etc->st_s[etc->i_st_s++];
	if (etc->st_s[etc->i_st_s] == '\n')
	{
		etc->one_s[etc->i_one_s++] = '\n';
		etc->i_st_s++;
	}
	etc->one_s[etc->i_one_s] = '\0';
	return (etc->one_s);
}

char	*join_s(t_etc *etc)
{
	char	*new_static_line;

	new_static_line = join_s_till_c(etc->st_s, etc->buf, '\0');
	if (new_static_line == NULL)
	{
		free_etc(etc);
		etc = NULL;
		return (NULL);
	}
	free(etc->st_s);
	etc->st_s = new_static_line;
	return (etc->st_s);
}

char	*join_s_till_c(char *s1, char *s2, char c)
{
	char	*out_s;
	size_t	i_in_s1;
	size_t	i_in_s2;
	size_t	i_out;

	i_in_s1 = 0;
	i_in_s2 = 0;
	i_out = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	out_s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (out_s == NULL)
		return (NULL);
	while (s1 && s1[i_in_s1] != c)
		out_s[i_out++] = s1[i_in_s1++];
	while (s2 && s2[i_in_s2] != c)
		out_s[i_out++] = s2[i_in_s2++];
	out_s[i_out] = '\0';
	return (out_s);
}

void	is_newline(t_etc *etc)
{
	etc->i_buf = 0;
	while (etc->buf[etc->i_buf] != '\0')
	{
		if (etc->buf[etc->i_buf] == '\n')
		{
			etc->is_there_newline = true;
			break ;
		}
		etc->i_buf++;
	}
}
