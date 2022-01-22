/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_combined.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:29:04 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/21 07:59:25 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_create_stack_and_check_int_size(int argc, char **argv,
	t_list **head, t_list **foot)
{
	int	value;
	int	i;

	i = 2;
	value = 0;
	if (!ft_check_int_size(argv[1], &value))
		return (0);
	*head = ft_create_new_list_element(value);
	//printf("created head=[%p] previous=[%p] value=[%i] next=[%p]\n", *head, (*head)->previous, (*head)->value, (*head)->next);
	*foot = *head;
	while (i < argc)
	{
		if (!ft_check_int_size(argv[i], &value))
			return (0);
		ft_add_element_last(foot, ft_create_new_list_element(value));
		//printf("head=[%p] previous=[%p] value=[%i] next=[%p]\n", *head, (*head)->previous, (*head)->value, (*head)->next);
		//printf("created foot=[%p] previous=[%p] value=[%i] next=[%p]\n", *foot, (*foot)->previous, (*foot)->value, (*foot)->next);
		i++;
	}
	return (1);
}

int	ft_delete_list_and_return_error(t_list *head)
{
	ft_delete_list(&head);
	return (ft_error());
}
