/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:20:40 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/21 20:20:39 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*foot_a;
	//t_list	*foot_b;

	head_a = NULL;
	foot_a = NULL;
	head_b = NULL;
	//foot_b = NULL;
	if (argc == 1)
		return (0);
	if (!ft_argv_is_number_only(argv))
		return (ft_error());
	if (!ft_create_stack_and_check_int_size(argc, argv, &head_a, &foot_a))
		return (ft_delete_list_and_return_error(head_a));
	if (argc == 2)
		return (0);
	if (!ft_stack_a_is_sorted(head_a))
	{
		ft_identify_area(head_a, ((int)(argc -1) / 2));
		if (argc == 3)
			ft_sort_2(head_a);
		else if (argc == 4)
			ft_sort_3(head_a, foot_a);
		else
			ft_sort_algorythm(head_a, foot_a, head_b);
	}

	return (0);
}
