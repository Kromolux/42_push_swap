/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:25:36 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/04 08:57:24 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sign_check(char *argv);

int	ft_argv_is_number_only(char **argv)
{
	int		i_argc;

	i_argc = 1;
	while (argv[i_argc])
	{
		if (!ft_sign_check(argv[i_argc]))
			return (0);
		i_argc++;
	}
	return (1);
}

static int	ft_sign_check(char *argv)
{
	int		i;
	int		i_arg;

	i = 0;
	i_arg = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
		{
			while (argv[i] == ' ')
				i++;
			i_arg = 0;
		}
		if (argv[i] < '0' || argv[i] > '9')
		{
			if (i_arg > 0 || (argv[i] != '+' && argv[i] != '-')
				|| argv[i + 1] < '0' || argv[i + 1] > '9')
				return (0);
		}
		i_arg++;
		i++;
	}
	return (1);
}
