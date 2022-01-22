/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:39:06 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/22 22:43:13 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_print_stack(t_list *head);
void	ft_print_stacks(t_stacks *stacks);
int	ft_sort_2(t_list *head)
{
	ft_swap(&head, "sa\n");
	return (0);
}

int	ft_sort_3(t_list *head, t_list *foot)
{
	int	min;
	int	max;

	ft_get_min_and_max(head, &min, &max);
	while (!ft_stack_a_is_sorted(head))
	{
		if (foot)
			printf("foot\n");
		/*
		if (head->value == max)
			ft_rotate(head, foot);
		else if (foot->value == max)
			ft_swap(&head, "sa\n");
		else if (head->value == min || foot->value == min)
			ft_reverse_rotate(&head, &foot);
		printf("stack a = \n");
		ft_print_stack(head);
		*/
	}
	return (0);
}

int	ft_sort_algorythm(t_stacks *stacks)
{
	int	min;
	int	max;
	printf("ft_sort_algorythm entered\n");
	ft_get_min_and_max((*stacks).a->head, &min, &max);
	//printf("stack a\n");
	//ft_print_stack(head_a);
	/*
	ft_print_stacks(stacks);
	ft_push_pb(stacks);
	ft_print_stacks(stacks);
	ft_push_pb(stacks);
	ft_print_stacks(stacks);
	ft_push_pa(stacks);
	ft_print_stacks(stacks);
	ft_push_pa(stacks);
	ft_print_stacks(stacks);
	*/
	ft_rotate_ra(stacks);
	ft_print_stacks(stacks);
	ft_rotate_ra(stacks);
	ft_print_stacks(stacks);
	ft_reverse_rotate_rra(stacks);
	ft_print_stacks(stacks);
	ft_reverse_rotate_rra(stacks);
	ft_print_stacks(stacks);
	/*
	while (!ft_stack_a_is_sorted((*stacks).a->head) || (*stacks).b->head != NULL)
	{
		//printf("entered while loop\n");
		if ((*stacks).a->head->value > (*stacks).a->head->next->value)
			ft_swap(&(*stacks).a->head, "sa\n");
		//printf("stack a\n");
		//ft_print_stack(head_a);
		//printf("checking for swap sb\n");
		if ((*stacks).b->head && (*stacks).b->head->next && (*stacks).b->head->value < (*stacks).b->head->next->value)
			ft_swap(&(*stacks).b->head, "sb\n");
		//printf("checking for push pb\n");
		//printf("checking for push pa head_a->area=[%i]\n", head_a->area);
		if ((*stacks).a->head->area != (char) 1 || (ft_stack_a_has_only_high_areas((*stacks).a->head) && (*stacks).a->head->value == min))
		{
			//printf("will push pa\n");
			ft_push_pb(stacks);
			ft_print_stacks(stacks);
			if (!(*stacks).b->foot)
				(*stacks).b->foot = (*stacks).b->head;
			if ((*stacks).b->head->value == min)
				ft_get_min_and_max((*stacks).a->head, &min, &max);
			if (ft_numbers_in_stack((*stacks).a->head) == 3)
			{
				//printf("just 3 numbers remain in stack a\n");
				ft_sort_3((*stacks).a->head, (*stacks).a->foot);
				ft_get_min_and_max((*stacks).b->head, &min, &max);
				while ((*stacks).b->head)
				{
					if ((*stacks).b->head->value == max)
					{
						ft_push_pa(stacks);
						//ft_push(&(*stacks).b->head, &(*stacks).a->head, "pa\n");
						//printf("pushed to a\n");
						ft_get_min_and_max((*stacks).b->head, &min, &max);
					}
					else if (ft_rotate_is_shortest((*stacks).b->head, (*stacks).b->foot, max))
						ft_rotate(&(*stacks).b->head, &(*stacks).a->foot, "rb\n");
					else
						ft_reverse_rotate(&(*stacks).b->head, &(*stacks).b->foot, "rrb\n");
					ft_print_stacks(stacks);
				}
				//return (0);
			}
		}
		//printf("checking for rotate and reverse rotate\n");
		else if (ft_rotate_is_shortest((*stacks).a->head, (*stacks).a->foot, min))
			ft_rotate(&(*stacks).a->head, &(*stacks).a->foot, "ra\n");
		else
			ft_reverse_rotate(&(*stacks).a->head, &(*stacks).a->foot, "rra\n");
		if (ft_stack_a_is_sorted((*stacks).a->head) && ft_stack_b_is_sorted_descending((*stacks).b->head))
		{
			//ft_sort_stack_a(head_a, foot_a, ft_rotate_is_shortest(head_a, foot_a, min));
			while ((*stacks).b->head)
				ft_push_pa(stacks);
				//ft_push(&(*stacks).b->head, &(*stacks).a->head, "pa\n");
			//return (0);
		}
		
		ft_print_stacks(stacks);
	}
	*/
	//printf("left while loop\n");
	return (0);
}

void	ft_sort_stack_a(t_list *head_a, t_list *foot_a, int rotate)
{
	while (!ft_stack_a_is_sorted(head_a))
	{
		if (head_a->value > head_a->next->value)
			ft_swap(&head_a, "sa\n");
		//else if (rotate)
			//ft_rotate(head_a, foot_a);
		//else
			//ft_reverse_rotate(&head_a, &foot_a);
		if (rotate || foot_a)
			printf("rotate\n");
	}	
}

void	ft_print_stacks(t_stacks *stacks)
{
	printf("==============================================[STACK A]==============================================\n");
	ft_print_stack((*stacks).a->head);
	printf("==============================================[STACK B]==============================================\n");
	ft_print_stack((*stacks).b->head);
}

void	ft_print_stack(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		printf("[%i]=>[%p] (previous=[%14p] value=[%11i] area=[%2i] next=[%14p])\n", i, head, head->previous, head->value, head->area, head->next);
		head = head->next;
		i++;
	}
}
