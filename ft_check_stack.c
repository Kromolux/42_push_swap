/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:32:58 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/20 22:16:48 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_stack_sorted(t_list **head)
{
	while ((*head)->next)
	{
		if ((*head)->value > (*head)->next->value)
			return (0);
		*head = (*head)->next;
	}
	printf("stack is already sorted\n");
	return (1);
}

void	ft_get_min_and_max(t_list **head, int *min, int *max)
{
	*min = (*head)->value;
	*max = (*head)->value;
	while ((*head)->next)
	{
		if (*min > (*head)->next->value)
			*min = (*head)->next->value;
		else if (*max < (*head)->next->value)
			*max = (*head)->next->value;
		*head = (*head)->next;
	}
	printf("min=[%i] max=[%i]\n", *min, *max);
}
