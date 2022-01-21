/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:00:01 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/20 22:03:57 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_swap(t_list **head, char *s)
{
	t_list	*old_first;
	t_list	*old_second;
	t_list	*new_first;
	t_list	*new_second;

	if (!*head || !(*head)->next)
		return (NULL);
	old_first = *head;
	old_second = (*head)->next;
	new_first = old_second;
	new_second = old_first;
	new_first->previous = NULL;
	new_first->next = old_first;
	new_second->previous = new_first;
	new_second->next = old_second->next;
	*head = new_first;
	write(1, s, 3);
	return (*head);
}
