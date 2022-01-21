/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:52:02 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/20 22:17:03 by rkaufman         ###   ########.fr       */
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
	struct s_list	*next;
}				t_list;

int		ft_error(void);

int		ft_argv_is_number_only(char **argv);
int		ft_check_int_size(char *argv, int *value);

t_list	*ft_create_new_list_element(int value);
void	ft_add_element_front(t_list **head, t_list *new);
void	ft_add_element_last(t_list **foot, t_list *new);
void	ft_delete_list(t_list *head);

int		ft_create_stack_and_check_int_size(int argc, char **argv,
			t_list **head, t_list **foot);
int		ft_delete_list_and_return_error(t_list *head);

int		ft_is_stack_sorted(t_list **head);
int		ft_sort_2(t_list *head);
int		ft_sort_3(t_list *head, t_list *foot);

void	ft_get_min_and_max(t_list **head, int *min, int *max);

t_list	*ft_swap(t_list **head, char *s);
void	ft_push(t_list *src_stack, t_list *dst_stack, char *s);
void	ft_rotate(t_list **head, t_list **foot, char *s);
void	ft_reverse_rotate(t_list **head, t_list **foot, char *s);

#endif