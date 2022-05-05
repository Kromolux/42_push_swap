/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:25:40 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/08 18:37:20 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_index_in_stack(t_stack_x *stack, int index);

int	ft_rotate_is_shortest_index(t_stack_x *stack, int number)
{
	t_list	*head;
	t_list	*foot;
	int		rotations;
	int		reverse_rotations;

	if (!ft_is_index_in_stack(stack, number))
		return (-1);
	head = stack->head;
	foot = stack->foot;
	rotations = 0;
	reverse_rotations = 1;
	while (head->next && head->index != number)
	{
		rotations++;
		head = head->next;
	}
	while (foot->previous && foot->index != number)
	{
		reverse_rotations++;
		foot = foot->previous;
	}
	if (rotations <= reverse_rotations)
		return (1);
	else
		return (0);
}

int	ft_get_higest_index_in_stack(t_stack_x *stack)
{
	int		higest;
	t_list	*list;

	if (!stack->head)
		return (-1);
	list = stack->head;
	higest = list->index;
	while (list->next)
	{
		if (list->next->index > higest)
			higest = list->next->index;
		list = list->next;
	}
	return (higest);
}

static int	ft_is_index_in_stack(t_stack_x *stack, int index)
{
	t_list	*head;

	head = stack->head;
	while (head)
	{
		if (head->index == index)
			return (1);
		head = head->next;
	}
	return (0);
}
