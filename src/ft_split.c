/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 18:28:46 by dahanlon          #+#    #+#             */
/*   Updated: 2026/10/17 18:29:42 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	count_words(char const *s, char c)
{
	size_t	i;
	size_t	num_words;

	i = 0;
	num_words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			num_words++;
		}
	}
	return (num_words);
}

static char	*create_word(char const *s, size_t word_len, size_t s_index)
{
	size_t	i;
	char	*word;

	word = (char *) malloc(sizeof (char) * (word_len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < word_len)
	{
		word[i] = s[s_index + i];
		i++;
	}
	word[word_len] = '\0';
	return (word);
}

static void	fill_words(const char *s, char c, char **words)
{
	size_t	word_len;
	size_t	s_index;
	size_t	id_word;
	size_t	i;

	i = 0;
	id_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			s_index = i;
			word_len = 0;
			while (s[i] != c && s[i] != '\0')
			{
				word_len++;
				i++;
			}
			words[id_word] = create_word(s, word_len, s_index);
			id_word++;
		}
	}
	words[id_word] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = (char **) malloc(sizeof (char *) * (count_words(s, c) + 1));
	if (!words)
		return (NULL);
	fill_words(s, c, words);
	return (words);
}

void	ft_free_split(char **words)
{
	int	i;

	if (!words)
		return ;
	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}
