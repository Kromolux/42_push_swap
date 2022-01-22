/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:20:53 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/21 22:04:14 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **src_stack, t_list **dst_stack, char *s)
{
	t_list	*tmp_src;

	tmp_src = *src_stack;
	//printf("tmp_src = *src_stack[%p]; done\n", *src_stack);
	if ((*src_stack)->next)
	{
		//printf("src_stack found\n");
		//printf("*src_stack = (*src_stack)->next[%p]; done\n", (*src_stack)->next);
		*src_stack = (*src_stack)->next;
		//printf("(*src_stack)->previous[%p] = NULL; done\n", (*src_stack)->previous);
		(*src_stack)->previous = NULL;
		//printf("tmp_src->next = *dst_stack[%p]; done\n", *dst_stack);
	}
	else
		*src_stack = NULL;
	tmp_src->next = *dst_stack;
	//printf("*src_stack = (*src_stack)->next[%p]; done\n", (*src_stack)->next);
	
	//printf("(*src_stack)->previous[%p] = NULL; done\n", (*src_stack)->previous);
	
	//printf("tmp_src->next = *dst_stack[%p]; done\n", *dst_stack);
	if (*dst_stack)
	{
		(*dst_stack)->previous = tmp_src;
		//printf("(*dst_stack)->previous = tmp_src[%p]; done\n", tmp_src);
	}
	*dst_stack = tmp_src;
	//printf("*dst_stack = tmp_src[%p]; done\n", tmp_src);
	write(1, s, 3);
}
