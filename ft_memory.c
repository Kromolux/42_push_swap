/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:20:28 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/27 16:27:54 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*ft_init_stacks(void)
{
	t_stacks *stacks;

	stacks = malloc(sizeof(t_stacks));
	stacks->a = malloc(sizeof(t_stack_x));
	stacks->a->head = NULL;
	stacks->a->foot = NULL;
	stacks->b = malloc(sizeof(t_stack_x));
	stacks->b->head = NULL;
	stacks->b->foot = NULL;
	return (stacks);
}

void	ft_free_stacks(t_stacks *stacks)
{
	ft_free_stack(stacks->a);
	ft_free_stack(stacks->b);
	free(stacks);	
}

void	ft_free_stack(t_stack_x *stack)
{
	t_list	*object;
	
	while (stack->head)
	{
		object = stack->head;
		stack->head = stack->head->next;
		free(object);
	}
	stack->head = NULL;
	stack->foot = NULL;
}

int	ft_free_stacks_and_return_error(t_stacks *stacks)
{
	ft_free_stacks(stacks);
	return (ft_error());
}
