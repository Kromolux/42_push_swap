/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:32:58 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/30 19:12:08 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_numbers_in_stack(t_stack_x *stack)
{
	t_list	*head;
	int		i;

	i = 0;
	head = stack->head;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int	ft_stack_is_sorted(t_stack_x *stack)
{
	t_list	*head;

	if (!stack->head || !stack->head->next)
		return (0);
	head = stack->head;
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_get_min_and_max(t_list *head, int *min, int *max)
{
	if (head)
	{
		*min = head->value;
		*max = head->value;
		while (head->next)
		{
			if (*min > head->next->value)
				*min = head->next->value;
			if (*max < head->next->value)
				*max = head->next->value;
			head = head->next;
		}
	}
}

t_list	*ft_get_next_min(t_list *head)
{
	t_list	*min;

	min = NULL;
	if (head)
	{
		while (head->next)
		{
			if (!min && head->index == -1)
				min = head;
			if (min && head->next->index == -1
				&& min->value > head->next->value)
				min = head->next;
			head = head->next;
		}
	}
	if (!min)
		min = head;
	return (min);
}

int	ft_check_remaining_area(t_stacks *stacks, int area)
{
	t_list	*head;

	head = stacks->a->head;
	while (head)
	{
		if (head->area == area)
			return (0);
		head = head->next;
	}
	return (1);
}
