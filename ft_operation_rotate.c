/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:51:30 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/21 20:56:37 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **head, t_list **foot, char *s)
{
	t_list	*new_head;
	t_list	*new_foot;
	t_list	*old_head;
	t_list	*old_foot;

	old_head = *head;
	old_foot = *foot;
	new_foot = old_head;
	new_head = old_head->next;
	old_foot->next = new_foot;
	new_head->previous = NULL;
	new_foot->next = NULL;
	new_foot->previous = old_foot;
	*head = new_head;
	*foot = new_foot;
	write(1, s, 3);
}

void	ft_reverse_rotate(t_list **head, t_list **foot, char *s)
{
	t_list	*new_head;
	t_list	*new_foot;
	t_list	*old_head;
	t_list	*old_foot;

	old_head = *head;
	old_foot = *foot;
	new_foot = old_foot->previous;
	new_head = old_foot;
	old_head->previous = new_head;
	new_head->previous = NULL;
	new_head->next = old_head;
	new_foot->next = NULL;
	*head = new_head;
	*foot = new_foot;
	write(1, s, 4);
}
