/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:18:05 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/30 19:49:54 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assign_area(t_stacks *stacks, int divider, t_list *min, t_list *max);
t_list	*ft_get_next_number(t_list *head, t_list *min);

void	ft_set_areas(t_stacks *stacks, int divider)
{
	t_list	*head;
	t_list	*min;
	t_list	*max;

	head = stacks->a->head;
	max = head;
	min = max;
	while (head->next)
	{
		if (max->value < head->value)
			max = head;
		head = head->next;
	}
	ft_assign_area(stacks, divider, min, max);
	head = stacks->a->head;
	while (head)
	{
		if (head->area == -1)
			head->area = divider - 1;
		head = head->next;
	}
}

void	ft_assign_area(t_stacks *stacks, int divider, t_list *min, t_list *max)
{
	int		area;
	int		number;
	int		numbers_in_area;
	t_list	*head;

	area = 0;
	numbers_in_area = ft_numbers_in_stack(stacks->a) / divider;
	while (area < divider)
	{
		number = 0;
		while (number < numbers_in_area)
		{
			head = stacks->a->head;
			min = max;
			min = ft_get_next_number(head, min);
			min->area = area;
			number++;
		}
		area++;
	}
}

t_list	*ft_get_next_number(t_list *head, t_list *min)
{
	if (head->area == -1 && min->value > head->value)
		min = head;
	while (head->next)
	{
		if (head->next->area == -1 && min->value > head->next->value)
			min = head->next;
		head = head->next;
	}
	return (min);
}

int	ft_index_stack(t_stacks *stacks)
{
	int		i;
	t_list	*min;
	int		numbers_in_stack;

	i = 0;
	numbers_in_stack = ft_numbers_in_stack(stacks->a);
	while (i < numbers_in_stack)
	{
		min = ft_get_next_min(stacks->a->head);
		min->index = i;
		i++;
	}
	return (0);
}
