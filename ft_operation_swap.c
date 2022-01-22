/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:00:01 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/22 22:46:35 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack_x *stack)
{
	t_list	*old_first;
	t_list	*old_second;
	t_list	*new_first;
	t_list	*new_second;

	old_first = stack->head;
	old_second = (*head)->next;
	new_first = old_second;
	new_second = old_first;
	new_second->next = old_second->next;
	new_first->previous = NULL;
	new_first->next = old_first;
	new_second->previous = new_first;
	if (new_second->next)
		new_second->next->previous = new_second;
	*head = new_first;
}

void	ft_swap_sa(t_stacks *stacks)
{
	
	write(1, "sa\n", 3);
}

void	ft_swap_sb(t_stacks *stacks)
{
	
		write(1, "sb\n", 3);
}
