/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:20:40 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/20 22:17:20 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*head_a;
	//t_list	*head_b;
	t_list	*foot_a;
	//t_list	*foot_b;

	head_a = NULL;
	foot_a = NULL;
	if (argc == 1)
		return (0);
	if (!ft_argv_is_number_only(argv))
		return (ft_error());
	if (!ft_create_stack_and_check_int_size(argc, argv, &head_a, &foot_a))
		return (ft_delete_list_and_return_error(head_a));
	if (argc == 2)
		return (0);
	if (ft_is_stack_sorted(&head_a))
		return (0);
	else if (argc == 3)
		return (ft_sort_2(head_a));
	else if (argc == 4)
		return (ft_sort_3(head_a, foot_a));
	
	return (0);
}
