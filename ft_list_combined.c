/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_combined.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:29:04 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/30 17:14:07 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_create_stack_and_check_int_size(int argc, char **argv,
	t_stack_x *stack)
{
	int	value;
	int	i;

	i = 2;
	value = 0;
	if (!ft_check_int_size(argv[1], &value))
		return (0);
	stack->head = ft_create_new_list_element(value);
	stack->foot = stack->head;
	while (i < argc)
	{
		if (!ft_check_int_size(argv[i], &value))
			return (0);
		ft_add_element_last(&(stack->foot), ft_create_new_list_element(value));
		i++;
	}
	return (1);
}
