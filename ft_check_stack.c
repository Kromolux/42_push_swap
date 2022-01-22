/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:32:58 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/22 22:12:45 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_numbers_in_stack(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int	ft_stack_a_is_sorted(t_list *head)
{
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	printf("stack a is sorted\n");
	//printf("stack a\n");
	//ft_print_stack(head);
	return (1);
}
int		ft_stack_a_has_only_high_areas(t_list *head)
{
	while (head)
	{
		if(head->area == (char) 0 || head->area == (char) -1)
			return (0);
		head = head->next;
	}
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
	printf("stack b is sorted\n");
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
		printf("min=[%i] max=[%i]\n", *min, *max);
	}
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
		if (head->area == (char) -1 && min->value > head->value)
			min = head;
		if (head->area == (char) -1 && max->value < head->value)
			max = head;
		while (head->next)
		{
			//printf("compare min=[%p]=[%i] with head=[%i] area=[%i]\n", min, min->value, head->next->value, head->next->area);
			//printf("compare max=[%p]=[%i] with head=[%i] area=[%i]\n", max, max->value, head->next->value, head->next->area);
			if (head->next->area == (char) -1 && min->value > head->next->value)
				min = head->next;
			if (head->next->area == (char) -1 && max->value < head->next->value)
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
	//printf("stack a = \n");
	//ft_print_stack(head);
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
	//printf("rotations=[%i] foot=[%p]\n", rotations, foot);
	//printf("reverse_rotations=[%i] foot->value=[%i] != number[%i]\n", reverse_rotations, foot->value, number);
	while (foot->value != number)
	{
		//printf("reverse_rotations=[%i] foot->value=[%i] != number[%i]\n", reverse_rotations, foot->value, number);
		reverse_rotations++;
		foot = foot->previous;
	}
	//printf("rotations=[%i] reversere_rotations=[%i]\n", rotations, reverse_rotations);
	if (rotations <= reverse_rotations)
		return (1);
	else
		return (0);
}
