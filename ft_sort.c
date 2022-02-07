/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:39:06 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/31 09:09:16 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3_a(t_stacks *stacks)
{
	t_sort_stack	sort_stack;

	sort_stack.min = 0;
	sort_stack.max = 0;
	sort_stack.stack = stacks->a;
	sort_stack.swap = &ft_sa;
	sort_stack.rotate = &ft_ra;
	sort_stack.reverse = &ft_rra;
	ft_sort_3(stacks, &sort_stack);
}

int	ft_sort_3(t_stacks *stacks, t_sort_stack *sort_stack)
{
	ft_get_min_and_max(sort_stack->stack->head,
		&sort_stack->min, &sort_stack->max);
	while (!ft_stack_is_sorted(sort_stack->stack))
	{
		if (sort_stack->stack->head->value == sort_stack->max)
			sort_stack->rotate(stacks);
		else if (sort_stack->stack->foot->value == sort_stack->max)
			sort_stack->swap(stacks);
		else if (sort_stack->stack->head->value == sort_stack->min
			|| sort_stack->stack->foot->value == sort_stack->min)
			sort_stack->reverse(stacks);
	}
	return (0);
}

// 18 for 500
// 12 for 100
int	ft_sort_algorythm(t_stacks *stacks, int argc)
{
	int	divider;

	if (argc < 10)
		divider = 4;
	else if (argc <= 50)
		divider = 6;
	else if (argc <= 200)
		divider = 12;
	else if (argc <= 300)
		divider = 14;
	else if (argc <= 400)
		divider = 16;
	else if (argc <= 600)
		divider = 18;
	else
		divider = 20;
	ft_set_areas(stacks, divider);
	ft_index_stack(stacks);
	ft_move_middle_area_to_b(stacks, divider);
	ft_move_everything_back_to_stack_a_before(stacks);
	return (0);
}

void	ft_move_middle_area_to_b(t_stacks *stacks, int divider)
{
	int		area_top;
	int		area_bottom;

	area_top = (int) divider / 2;
	area_bottom = area_top -1;
	while (ft_numbers_in_stack(stacks->a) > 0)
	{
		if (stacks->a->head->area == (char) area_top
			|| stacks->a->head->area == (char) area_bottom)
		{
			if (stacks->b->head
				&& stacks->b->head->area <= stacks->b->foot->area)
				ft_rb(stacks);
			ft_pb(stacks);
			area_top += ft_check_remaining_area(stacks, area_top);
			area_bottom -= ft_check_remaining_area(stacks, area_bottom);
		}
		else if (ft_numbers_in_stack(stacks->b) > 1
			&& stacks->b->head->area == area_bottom)
			ft_rr(stacks);
		else
			ft_ra(stacks);
	}
}

void	ft_move_everything_back_to_stack_a_before(t_stacks *stacks)
{
	int	before_max;
	int	max;

	max = ft_get_higest_index_in_stack(stacks->b);
	before_max = max - 1;
	while (ft_numbers_in_stack(stacks->b) > 0)
	{
		if (stacks->b->head->index == max
			|| stacks->b->head->index == before_max)
		{
			ft_pa(stacks);
			if (ft_check_for_double_swap(stacks))
				ft_ss(stacks);
			else if (stacks->a->head && stacks->a->head->next
				&& stacks->a->head->index > stacks->a->head->next->index)
				ft_sa(stacks);
			max = ft_get_higest_index_in_stack(stacks->b);
			before_max = max - 1;
		}
		else if (ft_rotate_is_shortest_index(stacks->b, max) == 1)
			ft_rb(stacks);
		else
			ft_rrb(stacks);
	}
}
