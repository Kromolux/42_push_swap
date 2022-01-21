/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:20:53 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/20 21:53:16 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list *src_stack, t_list *dst_stack, char *s)
{
	t_list	*tmp_src;

	//if (!src_stack || !dst_stack)
	//	return (NULL);
	tmp_src = src_stack;
	src_stack = src_stack->next;
	src_stack->previous = NULL;
	tmp_src->next = dst_stack;
	dst_stack->previous = tmp_src;
	write(1, s, 3);
}
