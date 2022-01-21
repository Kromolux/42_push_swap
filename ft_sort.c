/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:39:06 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/20 22:17:41 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_print_stack(t_list **head);
int	ft_sort_2(t_list *head)
{
	head = ft_swap(&head, "sa\n");
	return (0);
}

int	ft_sort_3(t_list *head, t_list *foot)
{
	int	min;
	int	max;

	ft_get_min_and_max(&head, &min, &max);
	ft_print_stack(&head);
	while (!ft_is_stack_sorted(&head))
	{
		if (head->value == max)
			ft_rotate(&head, &foot, "ra\n");
		else if (foot->value == max)
			ft_swap(&head, "sa\n");
		else if (head->value == min || foot->value == min)
			ft_reverse_rotate(&head, &foot, "rra\n");
		ft_print_stack(&head);
	}
	return (0);
}

void	ft_print_stack(t_list **head)
{
	int	i;

	i = 0;
	while (*head)
	{
		printf("[%i]=>[%p] previous=[%p] value=[%i] next=[%p]\n", i, *head, (*head)->previous, (*head)->value, (*head)->next);
		*head = (*head)->next;
		i++;
	}
}
