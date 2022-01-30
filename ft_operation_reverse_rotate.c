/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_reverse_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 09:47:00 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/29 21:12:30 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack_x *stack);

void	ft_rrr(t_stacks *stacks)
{
	if (stacks->a->head != stacks->a->foot
		&& stacks->b->head != stacks->b->foot)
	{
		write(1, "rrr\n", 4);
		ft_reverse_rotate(stacks->a);
		ft_reverse_rotate(stacks->b);
	}
}

void	ft_rra(t_stacks *stacks)
{
	if (stacks->a->head != stacks->a->foot)
	{
		write(1, "rra\n", 4);
		ft_reverse_rotate(stacks->a);
	}
}

void	ft_rrb(t_stacks *stacks)
{
	if (stacks->b->head != stacks->b->foot)
	{
		write(1, "rrb\n", 4);
		ft_reverse_rotate(stacks->b);
	}
}

static void	ft_reverse_rotate(t_stack_x *stack)
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
