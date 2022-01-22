/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:20:53 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/22 22:09:46 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack_x *stack_from, t_stack_x *stack_to)
{
	t_list	*old_head_to;
	t_list	*new_head_from;
	t_list	*pushed_object;
	
	pushed_object = stack_from->head;
	old_head_to = stack_to->head;
	new_head_from = pushed_object->next;
	if (new_head_from)
		(new_head_from)->previous = NULL;
	else
		stack_from->foot = NULL;
	if (old_head_to)
		(old_head_to)->previous = pushed_object;
	else
		stack_to->foot = pushed_object;
	(pushed_object)->next = old_head_to;
	stack_from->head = new_head_from;
	stack_to->head = pushed_object;
}

void	ft_push_pb(t_stacks *stacks)
{
	ft_push(stacks->a, stacks->b);
	write(1, "pb\n", 3);
}

void	ft_push_pa(t_stacks *stacks)
{
	ft_push(stacks->b, stacks->a);
	write(1, "pa\n", 3);
}
