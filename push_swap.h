/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:52:02 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/02 16:18:19 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16384
# endif

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
	int					min;
	int					max;
	struct s_stack_x	*stack;
	void				(*swap)(t_stacks *stacks);
	void				(*rotate)(t_stacks *stacks);
	void				(*reverse)(t_stacks *stacks);
}				t_sort_stack;

//ft_read_input.c
char		*ft_read_input(void);

//ft_array_string.c
char		**ft_split(char const *s, char c);
size_t		ft_words_in_str(char const *s, char c);
size_t		ft_copy(char *dst, char *src, size_t size);

//ft_error.c
int			ft_error(void);

//ft_check_argv.c
int			ft_argv_is_number_only(char **argv);
int			ft_number_is_unique(int number, t_stack_x *stack);
int			ft_check_int_size(char *argv, int *value);

//ft_memory.c
t_stacks	*ft_init_stacks(void);
void		ft_free_stacks(t_stacks *stacks);
void		ft_free_stack(t_stack_x *stack);
int			ft_free_stacks_and_return_error(t_stacks *stacks);
void		ft_free_array(char **array);

//ft_list.c
t_list		*ft_create_new_list_element(int value);
void		ft_add_element_last(t_list **foot, t_list *new_ele);
void		ft_delete_list(t_list **head);

//ft_list_combined.c
int			ft_create_stack_and_check_int_size(int argc, char **argv,
				t_stack_x *stack);

//ft_sort.c
void		ft_sort_3_a(t_stacks *stacks);
int			ft_sort_3(t_stacks *stacks, t_sort_stack *sort_stack);
int			ft_sort_algorythm(t_stacks *stacks, int argc);
void		ft_move_middle_area_to_b(t_stacks *stacks, int divider);
void		ft_move_everything_back_to_stack_a_before(t_stacks *stacks);

//ft_prepare_stack.c
int			ft_index_stack(t_stacks *stacks);
void		ft_set_areas(t_stacks *stacks, int divider);

//ft_check_stack0.c
int			ft_numbers_in_stack(t_stack_x *stack);
int			ft_stack_is_sorted(t_stack_x *stack);
void		ft_get_min_and_max(t_list *head, int *min, int *max);
t_list		*ft_get_next_min(t_list *head);
int			ft_check_remaining_area(t_stacks *stacks, int area);

//ft_check_stack1.c
int			ft_rotate_is_shortest_index(t_stack_x *stack, int number);
int			ft_get_higest_index_in_stack(t_stack_x *stack);

//ft_operation_swap.c
void		ft_sa(t_stacks *stacks);
void		ft_sb(t_stacks *stacks);
void		ft_ss(t_stacks *stacks);
int			ft_check_for_double_swap(t_stacks *stacks);

//ft_operation_push.c
void		ft_pb(t_stacks *stacks);
void		ft_pa(t_stacks *stacks);

//ft_operation_rotate.c
void		ft_ra(t_stacks *stacks);
void		ft_rb(t_stacks *stacks);
void		ft_rr(t_stacks *stacks);

//ft_operation_reverse_rotate.c
void		ft_rra(t_stacks *stacks);
void		ft_rrb(t_stacks *stacks);
void		ft_rrr(t_stacks *stacks);

#endif