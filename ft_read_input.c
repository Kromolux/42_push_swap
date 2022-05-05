/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 07:48:38 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/02 16:31:46 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char		*ft_realloc(char *dst, char *src, int free_dst, int free_src);
static size_t	ft_strlen(char *s);

char	*ft_read_input(void)
{
	char		*input;
	static char	buffer[BUFFER_SIZE];
	ssize_t		read_result;

	input = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!input)
		return (NULL);
	input[0] = '\0';
	while (1)
	{
		if (buffer[0])
			input = ft_realloc(input, buffer, 1, 0);
		read_result = read(0, (void *) buffer, BUFFER_SIZE);
		if (read_result == -1 || (read_result == 0 && input[0] == '\0'))
		{
			free(input);
			return (NULL);
		}
		buffer[read_result] = '\0';
		if (read_result == 0)
			return (input);
	}
}

static char	*ft_realloc(char *dst, char *src, int free_dst, int free_src)
{
	char	*output;
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (!dst || !src)
		return (NULL);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	output = (char *) malloc(sizeof(char) * (dst_len + src_len + 1));
	if (!output)
		return (NULL);
	i = ft_copy(output, dst, 0);
	ft_copy(&output[i], src, 0);
	if (free_dst)
		free(dst);
	if (free_src)
		free(src);
	return (output);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
