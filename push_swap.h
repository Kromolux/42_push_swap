/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:52:02 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/27 19:17:41 by rkaufman         ###   ########.fr       */
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
	int				index;
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

typedef struct s_sort_stack
{
	int				*min;
	int				*max;
	struct s_stack_x	*stack;
	void				(*swap)(t_stacks *stacks);
	void				(*rotate)(t_stacks *stacks);
	void				(*reverse)(t_stacks *stacks);
}				t_sort_stack;

int		ft_error(void);
int		ft_check_ascending_and_descenting(t_stacks *stacks);
int		ft_argv_is_number_only(char **argv);
int		ft_check_int_size(char *argv, int *value);

t_list	*ft_create_new_list_element(int value);
void	ft_add_element_front(t_list **head, t_list *new_ele);
void	ft_add_element_last(t_list **foot, t_list *new_ele);
void	ft_delete_list(t_list **head);
//ft_memory.c
t_stacks	*ft_init_stacks(void);
void		ft_free_stacks(t_stacks *stacks);
void		ft_free_stack(t_stack_x *stack);
int			ft_free_stacks_and_return_error(t_stacks *stacks);

int		ft_create_stack_and_check_int_size(int argc, char **argv,
			t_stack_x *stack);
//ft_sort.c
int		ft_sort_2_a(t_stacks *stacks);
void	ft_sort_3_a(t_stacks *stacks);
void	ft_sort_3_b(t_stacks *stacks);
int		ft_sort_3(t_stacks *stacks, t_sort_stack *sort_stack);
int		ft_sort_algorythm(t_stacks *stacks);
void	ft_sort_stack_a(t_list *head_a, t_list *foot_a, int rotate);
int		ft_index_stack(t_stacks *stacks);
int		ft_check_remaining_area(t_stacks *stacks, int area);
int		ft_numbers_in_stack(t_stack_x *stack);
int		ft_stack_is_sorted(t_stack_x *stack);
int		ft_stack_b_is_sorted_descending(t_list *head);
void	ft_get_min_and_max(t_list *head, int *min, int *max);
t_list	*ft_get_next_min(t_list *head);
void	ft_identify_area(t_list *head, int iterations);
void	ft_set_5_areas(t_stacks *stacks);
void	ft_reset_area(t_list *head);
void	ft_set_area_high(t_list *head);
int	ft_rotate_is_shortest_value(t_stack_x *stack, int number);
int		ft_rotate_is_shortest(t_stack_x *stack, int number);
int		ft_stack_a_has_only_high_areas(t_list *head);
void	ft_move_everything_to_stack_b(t_stacks *stacks);
void	ft_move_middle_area_to_b(t_stacks *stacks);
void	ft_move_everything_back_to_stack_a(t_stacks *stacks);
int	ft_check_for_double_swap(t_stacks *stacks);
//ft_operation_swap.c
void	ft_sa(t_stacks *stacks);
void	ft_sb(t_stacks *stacks);
void	ft_ss(t_stacks *stacks);
//ft_operation_push.c
void	ft_pb(t_stacks *stacks);
void	ft_pa(t_stacks *stacks);
//ft_operation_rotate.c
void	ft_ra(t_stacks *stacks);
void	ft_rb(t_stacks *stacks);
void	ft_rr(t_stacks *stacks);
//ft_operation_reverse_rotate.c
void	ft_rra(t_stacks *stacks);
void	ft_rrb(t_stacks *stacks);
void	ft_rrr(t_stacks *stacks);
//remove before submission!!!
void	ft_print_stack(t_list *head);
void	ft_print_stacks(t_stacks *stacks);
#endif