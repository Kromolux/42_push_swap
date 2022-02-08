/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:20:40 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/08 17:36:29 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			numbers;

	if (argc == 1)
		return (0);
	if (!ft_argv_is_number_only(argv))
		return (ft_error());
	stacks = ft_init_stacks();
	if (!ft_create_stack_and_check_int_size(argc, argv, stacks->a))
		return (ft_free_stacks_and_return_error(stacks));
	numbers = ft_numbers_in_stack(stacks->a);
	if (!ft_stack_is_sorted(stacks->a))
	{
		if (numbers == 2)
			ft_ra(stacks);
		else if (numbers == 3)
			ft_sort_3_a(stacks);
		else if (numbers == 5)
			ft_sort_5_a(stacks);
		else
			ft_sort_algorythm(stacks, numbers);
	}
	ft_free_stacks(stacks);
	return (0);
}
