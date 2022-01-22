/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:20:40 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/22 21:27:25 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stacks	*ft_init_stacks(void);
static void	ft_free_stacks(t_stacks *stacks);
static void	ft_free_stack(t_stack_x *stack);

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_list	*head_a;
	t_list	*head_b;
	t_list	*foot_a;
	t_list	*foot_b;

	stacks = ft_init_stacks();
	head_a = NULL;
	foot_a = NULL;
	head_b = NULL;
	foot_b = NULL;
	if (argc == 1)
		return (0);
	if (!ft_argv_is_number_only(argv))
		return (ft_error());
	if (!ft_create_stack_and_check_int_size(argc, argv, (*stacks).a))
		return (ft_delete_list_and_return_error(head_a));
	if (argc == 2)
		return (0);
	ft_print_stacks(stacks);
	if (!ft_stack_a_is_sorted((*stacks).a->head))
	{
		ft_identify_area((*stacks).a->head, ((int)(argc -1) / 2));
		//return (0);
		if (argc == 3)
			ft_sort_2((*stacks).a->head);
		else if (argc == 4)
			ft_sort_3((*stacks).a->head, (*stacks).a->foot);
		else
			ft_sort_algorythm(stacks);
		ft_free_stacks(stacks);
		//ft_delete_list(&head_a);
		//ft_delete_list(&head_b);
	}

	return (0);
}

static	t_stacks	*ft_init_stacks(void)
{
	t_stacks *stacks;

	stacks = malloc(sizeof(t_stacks));
	printf("malloc stacks\n");
	(*stacks).a = malloc(sizeof(t_stack_x));
	(*stacks).a->head = NULL;
	(*stacks).a->foot = NULL;
	(*stacks).b = malloc(sizeof(t_stack_x));
	(*stacks).b->head = NULL;
	(*stacks).b->foot = NULL;
	printf("return stacks\n");
	return (stacks);
}

static void	ft_free_stacks(t_stacks *stacks)
{
	ft_free_stack(stacks->a);
	ft_free_stack(stacks->b);
	free(stacks);	
}

static void	ft_free_stack(t_stack_x *stack)
{
	t_list	*object;
	
	while (stack->head)
	{
		object = stack->head;
		stack->head = stack->head->next;
		free(object);
	}
	stack->head = NULL;
	stack->foot = NULL;
}
