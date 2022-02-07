/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:04:45 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/02 08:12:10 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_create_substrings(char const *s, char c, char **array);
char			*ft_get_substring(char const *s, size_t start, size_t len);

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = (char **) malloc((ft_words_in_str(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	ft_create_substrings(s, c, array);
	return (array);
}

size_t	ft_words_in_str(char const *s, char c)
{
	size_t	i;
	size_t	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
				i++;
			word_count++;
		}
	}
	return (word_count);
}

static void	ft_create_substrings(char const *s, char c, char **array)
{
	size_t	i;
	size_t	start;
	size_t	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			array[word_count] = ft_get_substring(s, start, i - start);
			word_count++;
		}
	}
	array[word_count] = NULL;
}

char	*ft_get_substring(char const *s, size_t start, size_t len)
{
	char	*substring;
	size_t	s_len;
	size_t	bytes;

	if (!s)
		return (NULL);
	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start > s_len)
		bytes = 0;
	else
		bytes = s_len - start;
	substring = (char *) malloc(bytes + 1);
	if (!substring)
		return (NULL);
	if (start <= s_len)
		ft_copy(substring, (char *) &s[start], len + 1);
	else
		substring[0] = '\0';
	return (substring);
}

size_t	ft_copy(char *dst, char *src, size_t size)
{
	size_t	i;

	if (!dst || ! src)
		return (0);
	i = 0;
	if (size == 0)
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		size--;
		while (src[i] && i < size)
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (i);
}
