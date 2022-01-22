/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:00:01 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/21 22:03:44 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_swap(t_list **head, char *s)
{
	t_list	*old_first;
	t_list	*old_second;
	t_list	*new_first;
	t_list	*new_second;

	old_first = *head;
	old_second = (*head)->next;
	new_first = old_second;
	new_second = old_first;
	//printf("new_second->next = old_second->next[%p];\n", old_second->next);
	new_second->next = old_second->next;
	//printf("new_first->previous[%p] = NULL\n", new_first->previous);
	new_first->previous = NULL;
	//printf("new_first->next = old_first[%p];\n", old_first);
	new_first->next = old_first;
	//printf("new_second->previous = new_first[%p];\n", new_first);
	new_second->previous = new_first;
	//printf("new_second->next->previous = new_second;\n");
	if (new_second->next)
		new_second->next->previous = new_second;
	//printf("*head = new_first;\n");
	*head = new_first;
	write(1, s, 3);
	return (*head);
}
