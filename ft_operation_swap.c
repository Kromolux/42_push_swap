/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:00:01 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/29 21:33:15 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack_x *stack);

void	ft_ss(t_stacks *stacks)
{
	if (stacks->a->head != stacks->a->foot
		&& stacks->b->head != stacks->b->foot)
	{
		write(1, "ss\n", 3);
		ft_swap(stacks->a);
		ft_swap(stacks->b);
	}
}

void	ft_sa(t_stacks *stacks)
{
	if (stacks->a->head != stacks->a->foot)
	{
		write(1, "sa\n", 3);
		ft_swap(stacks->a);
	}
}

void	ft_sb(t_stacks *stacks)
{
	if (stacks->b->head != stacks->b->foot)
	{
		write(1, "sb\n", 3);
		ft_swap(stacks->b);
	}
}

static void	ft_swap(t_stack_x *stack)
{
	t_list	*old_first;
	t_list	*old_second;
	t_list	*new_first;
	t_list	*new_second;

	old_first = stack->head;
	old_second = stack->head->next;
	new_first = old_second;
	new_second = old_first;
	new_second->next = old_second->next;
	new_first->previous = NULL;
	new_first->next = old_first;
	new_second->previous = new_first;
	if (new_second->next)
		new_second->next->previous = new_second;
	stack->head = new_first;
	if (stack->foot == old_second)
		stack->foot = new_second;
}

int	ft_check_for_double_swap(t_stacks *stacks)
{
	if (stacks->a->head && stacks->b->head && stacks->a->head->next
		&& stacks->b->head->next)
		if (stacks->a->head->index > stacks->a->head->next->index
			&& stacks->b->head->index < stacks->b->head->next->index)
			return (1);
	return (0);
}
