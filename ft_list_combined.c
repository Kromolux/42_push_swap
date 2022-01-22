/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_combined.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:29:04 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/22 21:12:42 by rkaufman         ###   ########.fr       */
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
	//printf("created head=[%p] previous=[%p] value=[%i] next=[%p]\n", stack->head, stack->head->previous, stack->head->value, stack->head->next);
	stack->foot = stack->head;
	while (i < argc)
	{
		if (!ft_check_int_size(argv[i], &value))
			return (0);
		ft_add_element_last(&(stack->foot), ft_create_new_list_element(value));
		//printf("head=[%p] previous=[%p] value=[%i] next=[%p]\n", *head, (*head)->previous, (*head)->value, (*head)->next);
		//printf("created foot=[%p] previous=[%p] value=[%i] next=[%p]\n", stack->foot, stack->foot->previous, stack->foot->value, stack->foot->next);
		i++;
	}
	return (1);
}

int	ft_delete_list_and_return_error(t_list *head)
{
	ft_delete_list(&head);
	return (ft_error());
}
