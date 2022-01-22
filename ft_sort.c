/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:39:06 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/21 22:35:52 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_print_stack(t_list *head);
int	ft_sort_2(t_list *head)
{
	ft_swap(&head, "sa\n");
	ft_delete_list(&head);
	return (0);
}

int	ft_sort_3(t_list *head, t_list *foot)
{
	int	min;
	int	max;

	ft_get_min_and_max(head, &min, &max);
	ft_print_stack(head);
	while (!ft_stack_a_is_sorted(head))
	{
		if (head->value == max)
			ft_rotate(&head, &foot, "ra\n");
		else if (foot->value == max)
			ft_swap(&head, "sa\n");
		else if (head->value == min || foot->value == min)
			ft_reverse_rotate(&head, &foot, "rra\n");
		ft_print_stack(head);
	}
	ft_delete_list(&head);
	return (0);
}

int	ft_sort_algorythm(t_list *head_a, t_list *foot_a, t_list *head_b)
{
	int	min;
	int	max;

	ft_get_min_and_max(head_a, &min, &max);
	//printf("stack a\n");
	//ft_print_stack(head_a);
	while (!ft_stack_a_is_sorted(head_a) || head_b != NULL)
	{
		//printf("entered while loop\n");
		if (head_a->value > head_a->next->value)
			ft_swap(&head_a, "sa\n");
		//printf("stack a\n");
		//ft_print_stack(head_a);
		//printf("checking for swap sb\n");
		if (head_b && head_b->next && head_b->value < head_b->next->value)
			ft_swap(&head_b, "sb\n");
		//printf("checking for push pb\n");
		if (ft_stack_a_is_sorted(head_a) && ft_stack_b_is_sorted_descending(head_b))
			ft_push(&head_b, &head_a, "pb\n");
		//printf("checking for push pa\n");
		else if (head_a->area == (char) 0)
		{
			//printf("will push pa\n");
			ft_push(&head_a, &head_b, "pa\n");
			if (head_b->value == min)
				ft_get_min_and_max(head_a, &min, &max);
		}
		//printf("checking for rotate and reverse rotate\n");
		else if (ft_rotate_is_shortest(head_a, foot_a, min))
			ft_rotate(&head_a, &foot_a, "ra\n");
		else
			ft_reverse_rotate(&head_a, &foot_a, "rra\n");

		printf("stack a = \n");
		ft_print_stack(head_a);
		printf("stack b = \n");
		ft_print_stack(head_b);
	}
	//printf("left while loop\n");
	ft_delete_list(&head_a);
	ft_delete_list(&head_b);
	return (0);
}

void	ft_print_stack(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		printf("[%i]=>[%p] previous=[%14p] value=[%i] area=[%2i] next=[%14p]\n", i, head, head->previous, head->value, head->area, head->next);
		head = head->next;
		i++;
	}
}
