/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:51:30 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/22 22:42:06 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack_x *stack)
{
	t_list	*new_head;
	t_list	*old_foot;
	t_list	*rotated_object;

	rotated_object = stack->head;
	old_foot = stack->foot;
	new_head = rotated_object->next;
	old_foot->next = rotated_object;
	new_head->previous = NULL;
	rotated_object->next = NULL;
	rotated_object->previous = old_foot;
	stack->head = new_head;
	stack->foot = rotated_object;
}

void	ft_rotate_ra(t_stacks *stacks)
{
	ft_rotate((*stacks).a);
	write(1, "ra\n", 3);
}

void	ft_rotate_rb(t_stacks *stacks)
{
	ft_rotate((*stacks).b);
	write(1, "rb\n", 3);
}

void	ft_reverse_rotate(t_stack_x *stack)
{
	t_list	*new_foot;
	t_list	*old_head;
	t_list	*reversed_object;

	old_head = stack->head;
	reversed_object = stack->foot;
	new_foot = reversed_object->previous;
	old_head->previous = reversed_object;
	reversed_object->previous = NULL;
	reversed_object->next = old_head;
	new_foot->next = NULL;
	stack->head = reversed_object;
	stack->foot = new_foot;
}

void	ft_reverse_rotate_rra(t_stacks *stacks)
{
	ft_reverse_rotate((*stacks).a);
	write(1, "rra\n", 4);
}

void	ft_reverse_rotate_rrb(t_stacks *stacks)
{
	ft_reverse_rotate((*stacks).b);
	write(1, "rrb\n", 4);
}
