/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:36:49 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/29 21:10:24 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_create_new_list_element(int value)
{
	t_list	*new_element;

	new_element = (t_list *) malloc(sizeof(*new_element));
	if (!new_element)
		return (NULL);
	new_element->previous = NULL;
	new_element->value = value;
	new_element->area = (char) -1;
	new_element->index = -1;
	new_element->next = NULL;
	return (new_element);
}

void	ft_add_element_last(t_list **foot, t_list *new_ele)
{
	new_ele->previous = *foot;
	(*foot)->next = new_ele;
	*foot = new_ele;
}

void	ft_delete_list(t_list **head)
{
	t_list	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	*head = NULL;
}
