/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:20:40 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/27 16:27:44 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = ft_init_stacks();
	if (argc == 1)
		return (0);
	if (!ft_argv_is_number_only(argv))
		return (ft_error());
	if (!ft_create_stack_and_check_int_size(argc, argv, stacks->a))
		return (ft_free_stacks_and_return_error(stacks));
	if (argc == 2)
		return (0);
	//ft_print_stacks(stacks);
	//printf("stacks->a->head[%p]\n", stacks->a->head);

	if (!ft_stack_is_sorted(stacks->a))
	{
		
		//ft_identify_area(stacks->a->head, divider);
		//ft_set_area_high(stacks->a->head);
		//ft_check_ascending_and_descenting(stacks);
		//ft_print_stacks(stacks);
			//ft_identify_area(stacks->a->head, ((int)(argc -1) / 2));
		//return (0);
		
		if (argc == 3)
			ft_sort_3_a(stacks);
		else if (argc == 4)
			ft_sort_3_a(stacks);
		else
			ft_sort_algorythm(stacks);
	}
	//ft_print_stacks(stacks);
	ft_free_stacks(stacks);
	return (0);
}
