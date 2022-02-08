/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:02:38 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/08 17:15:28 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	ft_checker(t_stacks *stacks, char *input);
static int	ft_strcmp(const char *s1, const char *s2);
static int	ft_check_operations(char *args, t_stacks *stacks);

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		*input;

	stacks = ft_init_stacks();
	if (argc == 1)
		return (0);
	if (!ft_argv_is_number_only(argv))
		return (ft_error());
	if (!ft_create_stack_and_check_int_size(argc, argv, stacks->a))
		return (ft_free_stacks_and_return_error(stacks));
	input = ft_read_input();
	if (ft_checker(stacks, input) == 1)
	{
		if (ft_stack_is_sorted(stacks->a)
			&& ft_numbers_in_stack(stacks->b) == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	ft_free_stacks(stacks);
	return (0);
}

static int	ft_checker(t_stacks *stacks, char *input)
{
	char	**args;
	int		output;
	size_t	i;

	if (input)
		args = ft_split(input, '\n');
	else
		args = NULL;
	free(input);
	i = 0;
	output = 1;
	if (args)
	{
		close(STDOUT_FILENO);
		while (args[i] && output != -1)
		{
			output = ft_check_operations(args[i], stacks);
			i++;
		}
		freopen("/dev/tty", "w", stdout);
		ft_free_array(args);
	}
	return (output);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] < s2[i])
			return ((unsigned char) s1[i] - s2[i]);
		else if (s1[i] > s2[i])
			return ((unsigned char) s1[i] - s2[i]);
		else if (s1[i] == '\0' || s2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

static int	ft_check_operations(char *args, t_stacks *stacks)
{
	if (ft_strcmp(args, "sa") == 0)
		ft_sa(stacks);
	else if (ft_strcmp(args, "sb") == 0)
		ft_sb(stacks);
	else if (ft_strcmp(args, "ss") == 0)
		ft_ss(stacks);
	else if (ft_strcmp(args, "pb") == 0)
		ft_pb(stacks);
	else if (ft_strcmp(args, "pa") == 0)
		ft_pa(stacks);
	else if (ft_strcmp(args, "ra") == 0)
		ft_ra(stacks);
	else if (ft_strcmp(args, "rb") == 0)
		ft_rb(stacks);
	else if (ft_strcmp(args, "rr") == 0)
		ft_rr(stacks);
	else if (ft_strcmp(args, "rra") == 0)
		ft_rra(stacks);
	else if (ft_strcmp(args, "rrb") == 0)
		ft_rrb(stacks);
	else if (ft_strcmp(args, "rrr") == 0)
		ft_rrr(stacks);
	else
		return (ft_error());
	return (1);
}
