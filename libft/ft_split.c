/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:54:54 by sanbaek           #+#    #+#             */
/*   Updated: 2024/09/05 14:54:54 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *str, char separator)
{
	size_t	w_c;
	size_t	i;

	w_c = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == separator)
			i++;
		if (str[i] != '\0')
			w_c++;
		while (str[i] != separator && str[i] != '\0')
			i++;
	}
	return (w_c);
}

static void	set_edge_pair(char const *str, char separator, size_t *edge_pair)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		while (str[i] == separator)
			i++;
		if (str[i] != '\0')
			edge_pair[k++] = i;
		while (str[i] != separator && str[i] != '\0')
			i++;
		if (str[i] == '\0' || str[i] == separator)
			edge_pair[k++] = i;
	}
	return ;
}

static void	set_words(char *str, char **words, size_t w_c, size_t *edge_pair)
{
	size_t	w_i;
	size_t	word_len;

	w_i = 0;
	while (w_i < w_c)
	{
		word_len = edge_pair[w_i * 2 + 1] - edge_pair[w_i * 2];
		words[w_i] = (char *)ft_calloc(word_len + 1, sizeof(char));
		if (words[w_i] == NULL)
		{
			while (w_i > 0)
				free(words[--w_i]);
			free(words);
			return ;
		}
		ft_memmove(words[w_i], str + edge_pair[w_i * 2], word_len);
		words[w_i][word_len] = '\0';
		w_i++;
	}
	return ;
}

char	**ft_split(char const *str, char separator)
{
	t_sentence	sentence;

	sentence.w_c = count_word(str, separator);
	sentence.words = (char **)ft_calloc(sentence.w_c + 1, sizeof(char *));
	// 왜 +1이 아니라 +2를 해야되는지 모르겠음
	// 사실 +1도 왜 필요한지 모르겠음
	sentence.edge_pair = (size_t *)ft_calloc(sentence.w_c * 2 + 2, sizeof(size_t));
	if (sentence.words == NULL || sentence.edge_pair == NULL)
	{
		free(sentence.words);
		free(sentence.edge_pair);
		return (NULL);
	}
	set_edge_pair(str, separator, sentence.edge_pair);
	set_words((char *)str, sentence.words, sentence.w_c, sentence.edge_pair);
	free(sentence.edge_pair);
	return (sentence.words);
}
