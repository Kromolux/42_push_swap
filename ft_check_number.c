/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:16:22 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/04 08:18:07 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sign(const char *str, int *i_str);
static long	ft_atoi(const char *nptr);

int	ft_check_int_size(char *argv, int *value)
{
	long	tmp;

	tmp = ft_atoi(argv);
	if (tmp > INT_MAX || tmp < INT_MIN)
		return (0);
	*value = (int) tmp;
	return (1);
}

static long	ft_atoi(const char *nptr)
{
	long	output;
	int		sign;
	int		i;

	output = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	sign = check_sign(nptr, &i);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		output *= 10;
		output += nptr[i] - '0';
		i++;
	}
	if (i > 10)
		output = LONG_MAX;
	return (output * sign);
}

static int	check_sign(const char *str, int *i_str)
{
	int	sign;
	int	i;

	i = *i_str;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	*i_str = i;
	return (sign);
}

int	ft_number_is_unique(int number, t_stack_x *stack)
{
	t_list	*head;

	if (!stack)
		return (0);
	head = stack->head;
	while (head)
	{
		if (number == head->value)
			return (0);
		head = head->next;
	}
	return (1);
}