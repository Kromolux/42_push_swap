/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:25:36 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/29 21:07:27 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_whitespace(const char *str);
static int	check_sign(const char *str, int *i_str);
static long	ft_atoi(const char *nptr);

int	ft_argv_is_number_only(char **argv)
{
	int		i_argc;
	int		i_argv;
	char	c;

	i_argc = 1;
	while (argv[i_argc])
	{
		i_argv = 0;
		c = argv[i_argc][i_argv];
		while (c)
		{
			if ((c < '0' || c > '9') && (c != '+' && c != '-'))
				return (0);
			i_argv++;
			c = argv[i_argc][i_argv];
		}
		i_argc++;
	}
	return (1);
}

int	ft_check_int_size(char *argv, int *value)
{
	long	tmp;

	tmp = ft_atoi(argv);
	if (tmp > INT_MAX || tmp < INT_MIN)
		return (0);
	*value = tmp;
	return (1);
}

static long	ft_atoi(const char *nptr)
{
	long	output;
	int		sign;
	int		i;

	output = 0;
	i = check_whitespace(nptr);
	sign = check_sign(nptr, &i);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		output *= 10;
		output += nptr[i] - '0';
		i++;
	}
	if (i > 11)
		output = LONG_MAX;
	return (output * sign);
}

static int	check_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	return (i);
}

static int	check_sign(const char *str, int *i_str)
{
	int	sign;
	int	i;

	i = *i_str;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	*i_str = i;
	return (sign);
}
