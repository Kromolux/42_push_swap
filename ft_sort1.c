/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:29:07 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/08 18:38:26 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_5_a(t_stacks *stacks)
{
	ft_index_stack(stacks);
	while (ft_numbers_in_stack(stacks->a) > 3)
	{
		if (stacks->a->head->index == 0
			|| stacks->a->head->index == 1)
		{
			ft_pb(stacks);
			if (ft_check_for_double_swap(stacks))
				ft_ss(stacks);
			else if (stacks->b->head && stacks->b->head->next
				&& stacks->b->head->index < stacks->b->head->next->index)
				ft_sb(stacks);
		}
		else if (ft_rotate_is_shortest_index(stacks->a, 0) == 1
			|| ft_rotate_is_shortest_index(stacks->a, 1) == 1)
			ft_ra(stacks);
		else
			ft_rra(stacks);
	}
	ft_sort_3_a(stacks);
	ft_pa(stacks);
	ft_pa(stacks);
	return (0);
}
