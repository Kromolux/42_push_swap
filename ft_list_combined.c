/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_combined.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:29:04 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/08 19:41:17 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_first_argv_handling(char **argv, t_stack_x *stack);
static int	ft_rest_argv_handling(int argc, char **argv, t_stack_x *stack);
static int	ft_create_first_element(char *s, t_stack_x *stack);
static int	ft_add_element_to_stack(char *s, t_stack_x *stack);

int	ft_create_stack_and_check_int_size(int argc, char **argv,
	t_stack_x *stack)
{
	if (!ft_first_argv_handling(argv, stack))
		return (0);
	if (!ft_rest_argv_handling(argc, argv, stack))
		return (0);
	return (1);
}

static int	ft_first_argv_handling(char **argv, t_stack_x *stack)
{
	int		ii;
	char	**args;

	if (ft_words_in_str(argv[1], ' ') > 1)
	{
		args = ft_split(argv[1], ' ');
		if (!ft_create_first_element(args[0], stack))
			return (0);
		ii = 1;
		while (args[ii])
		{
			if (!ft_add_element_to_stack(args[ii], stack))
				return (0);
			ii++;
		}
		ft_free_array(args);
	}
	else if (!ft_create_first_element(argv[1], stack))
		return (0);
	return (1);
}

static int	ft_rest_argv_handling(int argc, char **argv, t_stack_x *stack)
{
	int		i;
	int		ii;
	char	**args;

	i = 2;
	while (i < argc)
	{
		if (ft_words_in_str(argv[i], ' ') > 1)
		{
			args = ft_split(argv[i], ' ');
			ii = 0;
			while (args[ii])
			{
				if (!ft_add_element_to_stack(args[ii], stack))
					return (0);
				ii++;
			}
			free(args);
		}
		else if (!ft_add_element_to_stack(argv[i], stack))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_create_first_element(char *s, t_stack_x *stack)
{
	int	value;

	if (!ft_check_int_size(s, &value))
		return (0);
	stack->head = ft_create_new_list_element(value);
	stack->foot = stack->head;
	return (1);
}

static int	ft_add_element_to_stack(char *s, t_stack_x *stack)
{
	int	value;

	if (!ft_check_int_size(s, &value)
		|| !ft_number_is_unique(value, stack))
		return (0);
	ft_add_element_last(&(stack->foot), ft_create_new_list_element(value));
	return (1);
}
