/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:32:58 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/21 22:32:14 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_a_is_sorted(t_list *head)
{
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	//printf("stack a is sorted\n");
	return (1);
}

int	ft_stack_b_is_sorted_descending(t_list *head)
{
	if (head)
	{
		while (head->next)
		{
			if (head->value < head->next->value)
				return (0);
			head = head->next;
		}
	}
	//printf("stack b is sorted\n");
	return (1);
}

void	ft_get_min_and_max(t_list *head, int *min, int *max)
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
	//printf("min=[%i] max=[%i]\n", *min, *max);
}

void	ft_identify_area(t_list *head, int iterations)
{
	t_list	*min;
	t_list	*max;
	t_list	*tmp;

	min = head;
	max = head;
	while (iterations > 0)
	{
		tmp = head;
		while (head->next)
		{
			//printf("compare min=[%p]=[%i] with head=[%i] area=[%i]\n", min, min->value, head->next->value, head->next->area);
			//printf("compare max=[%p]=[%i] with head=[%i] area=[%i]\n", max, max->value, head->next->value, head->next->area);
			if (min->value > head->next->value && head->next->area == (char) -1)
				min = head->next;
			if (max->value < head->next->value && head->next->area == (char) -1)
				max = head->next;
			head = head->next;
		}
		head = tmp;
		min->area = (char) 0;
		//printf("min=[%p]=[%i]\n", min, min->value);
		max->area = (char) 1;
		//printf("max=[%p]=[%i]\n", max, max->value);
		tmp = min;
		//printf("tmp=[%p]\n", tmp);
		min = max;
		//printf("min=[%p]\n", min);
		max = tmp;
		//printf("max=[%p]\n", max);
		//printf("min=[%p]=[%i]\n", min, min->value);
		//printf("max=[%p]=[%i]\n", max, max->value);
		iterations--;
	}
}

int	ft_rotate_is_shortest(t_list *head, t_list *foot, int number)
{
	int	rotations;
	int	reverse_rotations;
	//printf("ft_rotate_is_shortest number=[%i]\n", number);
	rotations = 0;
	reverse_rotations = 1;
	while (head->value != number)
	{
		rotations++;
		head = head->next;
	}
	while (foot->value != number)
	{
		reverse_rotations++;
		foot = foot->previous;
	}
	//printf("rotations=[%i] reversere_rotations=[%i]\n", rotations, reverse_rotations);
	if (rotations <= reverse_rotations)
		return (1);
	else
		return (0);
}
