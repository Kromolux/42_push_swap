/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:51:30 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/24 20:35:03 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack_x *stack);

void	ft_rr(t_stacks *stacks)
{
	ft_rotate(stacks->a);
	ft_rotate(stacks->b);
	write(1, "rr\n", 3);
}

void	ft_ra(t_stacks *stacks)
{
	if (stacks->a->head != stacks->a->foot)
	{
		ft_rotate(stacks->a);
		write(1, "ra\n", 3);
	}
}

void	ft_rb(t_stacks *stacks)
{
	if (stacks->b->head != stacks->b->foot)
	{
		ft_rotate(stacks->b);
		write(1, "rb\n", 3);
	}
}

static void	ft_rotate(t_stack_x *stack)
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
