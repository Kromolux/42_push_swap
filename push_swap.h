/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:52:02 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/22 22:42:47 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include <stdio.h>
typedef struct s_list
{
	struct s_list	*previous;
	int				value;
	char			area;
	struct s_list	*next;
}				t_list;

typedef struct s_stack_x
{
	struct s_list	*head;
	struct s_list	*foot;
}				t_stack_x;

typedef struct s_stacks
{
	struct s_stack_x	*a;
	struct s_stack_x	*b;
}				t_stacks;

int		ft_error(void);

int		ft_argv_is_number_only(char **argv);
int		ft_check_int_size(char *argv, int *value);

t_list	*ft_create_new_list_element(int value);
void	ft_add_element_front(t_list **head, t_list *new_ele);
void	ft_add_element_last(t_list **foot, t_list *new_ele);
void	ft_delete_list(t_list **head);

int		ft_create_stack_and_check_int_size(int argc, char **argv,
			t_stack_x *stack);
int		ft_delete_list_and_return_error(t_list *head);

int		ft_sort_2(t_list *head);
int		ft_sort_3(t_list *head, t_list *foot);
int		ft_sort_algorythm(t_stacks *stacks);
void	ft_sort_stack_a(t_list *head_a, t_list *foot_a, int rotate);

int		ft_numbers_in_stack(t_list *head);
int		ft_stack_a_is_sorted(t_list *head);
int		ft_stack_b_is_sorted_descending(t_list *head);
void	ft_get_min_and_max(t_list *head, int *min, int *max);
void	ft_identify_area(t_list *head, int iterations);
int		ft_rotate_is_shortest(t_list *head, t_list *foot, int number);
int		ft_stack_a_has_only_high_areas(t_list *head);

void	ft_push_pb(t_stacks *stacks);
void	ft_push_pa(t_stacks *stacks);
t_list	*ft_swap(t_list **head, char *s);
//void	ft_push(t_list **src_stack, t_list **dst_stack, char *s);
void	ft_rotate(t_stack_x *stack);
void	ft_rotate_ra(t_stacks *stacks);
void	ft_rotate_rb(t_stacks *stacks);
void	ft_reverse_rotate(t_stack_x *stack);
void	ft_reverse_rotate_rra(t_stacks *stacks);
void	ft_reverse_rotate_rrb(t_stacks *stacks);

void	ft_print_stack(t_list *head);
void	ft_print_stacks(t_stacks *stacks);
#endif