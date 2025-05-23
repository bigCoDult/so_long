/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:14:12 by sanbaek           #+#    #+#             */
/*   Updated: 2024/09/24 00:18:41 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*template_literal(char *line, char *word, int location)
{
	char	*str;
	int		str_i;
	int		line_i;
	int		word_i;

	str = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(word) + 1));
	if (str == NULL)
		return (NULL);
	str_i = 0;
	line_i = 0;
	word_i = 0;
	while (line_i < location)
		str[str_i++] = line[line_i++];
	while (word_i < (int)ft_strlen(word))
		str[str_i++] = word[word_i++];
	while (line[line_i] != '\0')
		str[str_i++] = line[line_i++];
	str[str_i] = '\0';
	return (str);
}

char	*join_s(char *st_s, char *buf)
{
	char	*new_line;

	new_line = join_s_till_c(st_s, buf, '\0');
	if (new_line == NULL)
		return (NULL);
	free(st_s);
	return (new_line);
}

char	*join_s_till_c(char *s1, char *s2, char c)
{
	char	*out_s;
	int		i_in_s1;
	int		i_in_s2;
	int		i_out;

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

void	*open_xpm(t_wd *wd, void *single_tile, char *tile_name)
{
	int		tile_len;
	char	*path;

	tile_len = T;
	path = template_literal("./tile/.xpm", tile_name, 7);
	single_tile = mlx_xpm_file_to_image(wd->mp, path, &tile_len, &tile_len);
	free(path);
	return (single_tile);
}

void	free_empty(t_t *t)
{
	free(t->md->str);
	free(t->md);
	free(t->wd);
	free(t);
}
