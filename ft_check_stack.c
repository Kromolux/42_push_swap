/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:32:58 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/27 19:04:13 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_numbers_in_stack(t_stack_x *stack)
{
	t_list	*head;
	int	i;

	i = 0;
	head = stack->head;
	while (head)
	{
		i++;
		head = head->next;
	}
	//printf("numbers in stack =[%i]\n", i);
	return (i);
}

int	ft_stack_is_sorted(t_stack_x *stack)
{
	t_list	*head;
	head = stack->head;
	//printf("head=[%p]\n", head);
	while (head->next)
	{
		//printf("head->value[%i] > head->next->value[%i]\n", head->value, head->next->value);
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	//printf("stack a is sorted\n");
	//printf("stack a\n");
	//ft_print_stack(head);
	return (1);
}
int		ft_stack_a_has_only_high_areas(t_list *head)
{
	while (head)
	{
		if(head->area == (char) 0)
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
	//printf("stack b is sorted\n");
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
		//printf("min=[%i] max=[%i]\n", *min, *max);
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
			if (min && head->next->index == -1 && min->value > head->next->value)
				min = head->next;
			head = head->next;
		}
	}
	return (min);
}

void	ft_set_5_areas(t_stacks *stacks)
{
	t_list	*head;
	t_list	*min;
	t_list	*max;
	int		i;
	int		ii;
	int		numbers_in_area;
	int		divider;

	divider = 6;
	i = 0;
	head = stacks->a->head;
	max = head;
	numbers_in_area = ft_numbers_in_stack(stacks->a) / divider;
	//printf("numbers_in_area=[%i]\n", numbers_in_area);
	while (head->next)
	{
		if (max->value < head->value)
			max = head;
		head = head->next;
	}
	while (i < divider)
	{
		ii = 0;
		while (ii < numbers_in_area)
		{
			head = stacks->a->head;
			min = max;
			if (head->area == -1 && min->value > head->value)
				min = head;
			while (head->next)
			{
				if (head->next->area == -1 && min->value > head->next->value)
					min = head->next;
				head = head->next;
			}
			//printf("min->area[%p]=[%i]\n", min, i);
			min->area = i;
			ii++;
		}
		i++;
	}
	head = stacks->a->head;
	while (head)
	{
		if (head->area == -1)
			head->area = divider - 1;
		head = head->next;
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

void	ft_set_area_high(t_list *head)
{
	while (head)
	{
		if (head->area == -1)
			head->area = 1;
		head = head->next;
	}
}

void	ft_reset_area(t_list *head)
{
	while (head)
	{
		head->area = (char) -1;
		head = head->next;
	}
}

int	ft_rotate_is_shortest(t_stack_x *stack, int number)
{
	t_list	*head;
	t_list	*foot;
	int		rotations;
	int		reverse_rotations;

	head = stack->head;
	foot = stack->foot;
	//printf("ft_rotate_is_shortest number=[%i]\n", number);
	rotations = 0;
	reverse_rotations = 1;
	while (head->area != number)
	{
		rotations++;
		head = head->next;
	}
	//printf("rotations=[%i] foot=[%p]\n", rotations, foot);
	//printf("reverse_rotations=[%i] foot->value=[%i] != number[%i]\n", reverse_rotations, foot->value, number);
	while (foot->area != number)
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

int	ft_rotate_is_shortest_value(t_stack_x *stack, int number)
{
	t_list	*head;
	t_list	*foot;
	int		rotations;
	int		reverse_rotations;

	head = stack->head;
	foot = stack->foot;
	//printf("head=[%p] foot=[%p]\n", head, foot);
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

int	ft_check_ascending_and_descenting(t_stacks *stacks)
{
	int	ascending;
	int	descending;
	t_list	*head;
	t_list	*first;
	t_list	*second;

	first = NULL;
	second = NULL;
	head = stacks->a->head;
	ascending = 0;
	descending = 0;
	while (head->next)
	{
		if (head->area == 0)
			first = head;
		if (head->next->area == 0)
			second = head->next;
		if (first && second)
		{
			if (first->value < second->value)
				ascending++;
			else
				descending++;
		}
		head = head->next;
	}
	//printf("ascending=[%i] descending[%i]\n", ascending, descending);
	if (ascending > descending)
		return (1);
	else
		return (0);
}

int	ft_check_remaining_area(t_stacks *stacks, int area)
{
	t_list	*head;
	//printf("checks for remaining\n");
	head = stacks->a->head;
	while (head)
	{
		//printf("head->area=[%i] == area=[%i]\n", head->area, area);
		if (head->area == area)
			return (0);
		head = head->next;
	}
	return (1);
}

int	ft_index_stack(t_stacks *stacks)
{
	int		i;
	t_list	*min;
	int		numbers_in_stack;

	i = 0;
	numbers_in_stack = ft_numbers_in_stack(stacks->a);
	//printf("numbers in stack = [%i]\n", numbers_in_stack);
	while (i < numbers_in_stack)
	{
		min = ft_get_next_min(stacks->a->head);
		//printf("%p\n", &min);
		//printf("min=[%i] index=[%i] max=[%i] index[%i]\n", min->value, min->index, max->value, max->index);
		min->index = i;
		i++;
		//printf("min=[%i] index=[%i]\n", min->value, min->index);
	}
	return (0);
}
