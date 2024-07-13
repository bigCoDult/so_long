/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:18:39 by sanbaek           #+#    #+#             */
/*   Updated: 2024/06/23 14:18:40 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_etc
{
	bool	is_there_newline;
	ssize_t	rtn_read;
	char	*buf;
	char	*st_s;
	char	*one_s;
	size_t	i_buf;
	size_t	i_st_s;
	size_t	i_one_s;
}	t_etc;

char	*get_next_line(int fd);
size_t	deal_buf(t_etc *etc, int fd);
void	init_etc(t_etc *etc);
void	free_etc(t_etc *etc);
void	is_newline(t_etc *etc);
size_t	set_buf(t_etc *etc, int fd);
char	*set_one_s(t_etc *etc);
char	*join_s(t_etc *etc);
char	*join_s_till_c(char *s1, char *s2, char c);
size_t	ft_strlen(char *s);

#endif /* GET_NEXT_LINE_H */
