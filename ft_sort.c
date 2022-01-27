/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:39:06 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/27 19:31:06 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_print_stack(t_list *head);
void	ft_print_stacks(t_stacks *stacks);
int		ft_sort_2(t_stack_x *stack)
{
	if (stack)
	printf("head");

	return (0);
}

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

void	ft_sort_3_b(t_stacks *stacks)
{
	t_sort_stack	sort_stack;

	sort_stack.min = 0;
	sort_stack.max = 0;
	sort_stack.stack = stacks->b;
	sort_stack.swap = &ft_sb;
	sort_stack.rotate = &ft_rb;
	sort_stack.reverse = &ft_rrb;
	ft_sort_3(stacks, &sort_stack);
}

int	ft_sort_3(t_stacks *stacks, t_sort_stack *sort_stack)
{
	ft_get_min_and_max(sort_stack->stack->head, sort_stack->min, sort_stack->max);
	while (!ft_stack_is_sorted(sort_stack->stack))
	{
		if (sort_stack->stack->head->value == *(sort_stack->max))
			sort_stack->rotate(stacks);
		else if (sort_stack->stack->foot->value == *(sort_stack->max))
			sort_stack->swap(stacks);
		else if (sort_stack->stack->head->value == *(sort_stack->min) || sort_stack->stack->foot->value == *(sort_stack->min))
			sort_stack->reverse(stacks);
	}
	return (0);
}

int	ft_sort_algorythm(t_stacks *stacks)
{
	int	min;
	int	max;
	int	area;

	area = 0;
	//order_is_ascending = ft_check_ascending_and_descenting(stacks);
	//ft_get_min_and_max(stacks->a->head, &min, &max);
	//ft_print_stacks(stacks);
	ft_set_5_areas(stacks);
	//ft_print_stacks(stacks);
	ft_index_stack(stacks);
	//ft_print_stacks(stacks);
	//ft_move_everything_to_stack_b(stacks);
	ft_move_middle_area_to_b(stacks);
	//ft_print_stacks(stacks);
	//return (0);
	ft_move_everything_back_to_stack_a(stacks);
	//ft_print_stacks(stacks);
	//ft_print_stacks(stacks);
	return (0);
	//ft_print_stacks(stacks);
	//printf("numbers in stack = [%i]\n", ft_numbers_in_stack(stacks->a));
	//ft_print_stacks(stacks);
	//printf("remaining_area=[%i]\n", ft_check_remaining_area(stacks, area));
	//ft_pb(stacks);
	//ft_print_stacks(stacks);
	//printf("rotate is shortest =[%i]\n", ft_rotate_is_shortest(stacks->a, area));
	//ft_pb(stacks);
	//ft_print_stacks(stacks);
	//printf("numbers in stack = [%i]\n", ft_numbers_in_stack(stacks->a));
	//ft_pb(stacks);
	//ft_ra(stacks);
	//ft_print_stacks(stacks);
	//printf("numbers in stack = [%i]\n", ft_numbers_in_stack(stacks->a));
	//ft_print_stacks(stacks);
	ft_move_everything_to_stack_b(stacks);
	//ft_print_stacks(stacks);
	ft_move_everything_back_to_stack_a(stacks);
	//ft_print_stacks(stacks);
	return (0);
	while (!ft_stack_is_sorted(stacks->a) || stacks->b->head != NULL)
	{
		//if (stacks->a->head->next && stacks->a->head->next->value == min)
		//	ft_sa(stacks);
		//if (stacks->a->head->value > stacks->a->head->next->value)
		//	ft_sa(stacks);
			//ft_swap(&(*stacks).a->head, "sa\n");
		//else if (stacks->b->head && stacks->b->head->next && stacks->b->head->value < stacks->b->head->next->value)
		//	ft_sb(stacks);
			//ft_swap(&(*stacks).b->head, "sb\n");
		//if (ft_stack_a_has_only_high_areas(stacks->a->head))
		//{
			//ft_reset_area(stacks->a->head);
			//divider = ft_numbers_in_stack(stacks->a->head);
			/*
			if (divider >= 400)
				divider = (int) divider / 10;
			else if (divider >= 60)
				divider = (int) divider / 5;
			else
			*/
			//	divider = ((int) divider / 2);
			//ft_identify_area(stacks->a->head, divider);
			//order_is_ascending = ft_check_ascending_and_descenting(stacks);
			//ft_set_area_high(stacks->a->head);
		//}
		//printf("stacks->a->head->area[%i] == area[%i]\n", stacks->a->head->area, area);
		if (stacks->a->head->area == (char) area)
		{
			ft_pb(stacks);
			area += ft_check_remaining_area(stacks, area);
			printf("area=[%i]\n", area);
			//return (0);
			if (stacks->b->head->value == min)
				ft_get_min_and_max(stacks->a->head, &min, &max);
			/*
			if (ft_stack_is_sorted(stacks->a->head))
			{
				ft_get_min_and_max(stacks->b->head, &min, &max);
				ft_pa(stacks);
				if (stacks->a->head->value > stacks->a->head->next->value)
					ft_sa(stacks);
				while (stacks->b->head)
				{
					if (stacks->b->head->value == max)
					{
						ft_pa(stacks);
						ft_get_min_and_max(stacks->b->head, &min, &max);
					}
					//else if (stacks->b->head->next && stacks->b->head->next->value == max)
					//	ft_sb(stacks);
					else if (ft_rotate_is_shortest(stacks->b->head, stacks->b->foot, max))
						ft_rb(stacks);
					else
						ft_rrb(stacks);
				}
				ft_print_stacks(stacks);
				return (0);
			}
			*/
			if (ft_numbers_in_stack(stacks->a) == 0)
			{
				//ft_sort_3_a(stacks);
				ft_get_min_and_max(stacks->b->head, &min, &max);
				while (stacks->b->head)
				{
					if (stacks->b->head->value == max)
					{
						ft_pa(stacks);
						ft_get_min_and_max(stacks->b->head, &min, &max);
					}
					//else if (stacks->b->head->next && stacks->b->head->next->value == max)
					//	ft_sb(stacks);
					else if (ft_rotate_is_shortest(stacks->b, max))
						ft_rb(stacks);
					else
						ft_rrb(stacks);
				}
				//ft_print_stacks(stacks);
				return (0);
			}
			//return (0);
			
		}
		else if (ft_rotate_is_shortest(stacks->a, min))
			ft_ra(stacks);
		else
			ft_rra(stacks);
		if (ft_stack_is_sorted(stacks->a) && ft_stack_b_is_sorted_descending(stacks->b->head))
		{
			while (stacks->b->head)
				ft_pa(stacks);
			return (0);
		}
		//ft_print_stacks(stacks);
	}
	return (0);
}

void	ft_move_everything_to_stack_b(t_stacks *stacks)
{
	int	area;
	int	min;
	int	max;

	area = 0;
	while (ft_numbers_in_stack(stacks->a) > 0)
	{
		if (stacks->a->head->area == (char) area)
		{
			ft_pb(stacks);
			area += ft_check_remaining_area(stacks, area);
			ft_get_min_and_max(stacks->b->head, &min, &max);
		}
		else if (ft_rotate_is_shortest(stacks->a, area))
		{
			if (ft_numbers_in_stack(stacks->b) > 1 && stacks->b->head->value == min)
				ft_rr(stacks);
			else
				ft_ra(stacks);
		}
		else
		{
			if (ft_numbers_in_stack(stacks->b) > 1 && stacks->b->foot->value == max)
				ft_rrr(stacks);
			else
				ft_rra(stacks);
		}
		
	}
	//ft_print_stacks(stacks);
}

void	ft_move_middle_area_to_b(t_stacks *stacks)
{
	int		area_top;
	int		area_bottom;

	area_top = 3;
	area_bottom = 2;
	while (ft_numbers_in_stack(stacks->a) > 0)
	{
		//ft_print_stacks(stacks);
		if (stacks->a->head->area == (char) area_top || stacks->a->head->area == (char) area_bottom)
		{
			ft_pb(stacks);
			area_top += ft_check_remaining_area(stacks, area_top);
			area_bottom -= ft_check_remaining_area(stacks, area_bottom);
			//printf("area_top=[%i] area_bottom=[%i]\n", area_top, area_bottom);
			//ft_get_min_and_max(stacks->b->head, min, max);
		}
		//else if (ft_check_for_double_swap(stacks))
			//ft_ss(stacks);
		else if (ft_rotate_is_shortest(stacks->a, area_top) || ft_rotate_is_shortest(stacks->a, area_bottom))
		{
			if (ft_numbers_in_stack(stacks->b) > 1 && stacks->b->head->area <= stacks->b->foot->area)
				ft_rr(stacks);
			else
				ft_ra(stacks);
		}
		else
		{
			if (ft_numbers_in_stack(stacks->b) > 1 && stacks->b->foot->area >= stacks->b->head->area)
				ft_rrr(stacks);
			else
				ft_rra(stacks);
		}
		if (stacks->b->head && stacks->b->head->area <= stacks->b->foot->area)
			ft_rb(stacks);
		
	}
	//ft_print_stacks(stacks);
}

void	ft_move_everything_back_to_stack_a(t_stacks *stacks)
{
	int	min;
	int	max;

	ft_get_min_and_max(stacks->b->head, &min, &max);
	//printf("min=[%i] max=[%i]\n", min, max);
	//ft_print_stacks(stacks);
	while (ft_numbers_in_stack(stacks->b) > 0)
	{
		//printf("in while loop\n");
		if (stacks->b->head->value == max)
		{
			ft_pa(stacks);
			ft_get_min_and_max(stacks->b->head, &min, &max);
		}
		else if (ft_rotate_is_shortest_value(stacks->b, max))
		{
			ft_rb(stacks);
		}
		else
		{
			ft_rrb(stacks);
		}
	}
}

void	ft_sort_stack_a(t_list *head_a, t_list *foot_a, int rotate)
{
	//while (!ft_stack_is_sorted(head_a))
	//{
		if (head_a->value > head_a->next->value)
			printf("rotate\n");
			//ft_swap(&head_a, "sa\n");
		//else if (rotate)
			//ft_rotate(head_a, foot_a);
		//else
			//ft_reverse_rotate(&head_a, &foot_a);
		if (rotate || foot_a)
			printf("rotate\n");
	//}	
}

int	ft_check_for_double_swap(t_stacks *stacks)
{
	if (stacks->a->head->area == stacks->a->head->next->area
		&& stacks->b->head->area == stacks->b->head->next->area
		&& stacks->a->head->value > stacks->a->head->next->value
		&& stacks->b->head->value < stacks->b->head->next->value)
		return (1);
	return (0);
}

void	ft_print_stacks(t_stacks *stacks)
{
	printf("=head=[%14p]==========================[STACK A]=============================================\n", stacks->a->head);
	ft_print_stack(stacks->a->head);
	printf("=foot=[%14p]==========================[STACK A]=============================================\n\n", stacks->a->foot);
	printf("=head=[%14p]==========================[STACK B]=============================================\n", stacks->b->head);
	ft_print_stack(stacks->b->head);
	printf("=foot=[%14p]==========================[STACK B]=============================================\n\n", stacks->b->foot);
}

void	ft_print_stack(t_list *tmp)
{
	int	i;
	t_list	*head;

	head = tmp;
	i = 0;
	while (head)
	{
		printf(" [%3i]=>[%p] (previous=[%14p] value=[%11i] area=[%2i] index=[%3i] next=[%14p])\n", i, head, head->previous, head->value, head->area, head->index, head->next);
		head = head->next;
		i++;
	}
}
