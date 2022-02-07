# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 17:45:41 by rkaufman          #+#    #+#              #
#    Updated: 2022/02/04 08:19:05 by rkaufman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:=	push_swap
NAME_BONUS	:=	checker

CC 			:=	gcc
HEADERFILES :=	push_swap.h

SRCFILES 	:=	ft_push_swap.c \
				ft_error.c \
				ft_check_argv.c \
				ft_memory.c \
				ft_list_combined.c \
				ft_list.c \
				ft_prepare_stack.c \
				ft_check_stack0.c \
				ft_check_stack1.c \
				ft_operation_swap.c \
				ft_operation_push.c \
				ft_operation_rotate.c \
				ft_operation_reverse_rotate.c \
				ft_sort.c \
				ft_array_string.c \
				ft_check_number.c

SRCBONUS	:=	ft_checker.c \
				ft_error.c \
				ft_check_argv.c \
				ft_read_input.c \
				ft_memory.c \
				ft_list_combined.c \
				ft_list.c \
				ft_check_stack0.c \
				ft_operation_swap.c \
				ft_operation_push.c \
				ft_operation_rotate.c \
				ft_operation_reverse_rotate.c \
				ft_array_string.c \
				ft_check_number.c

OBJFILES 	:=	$(SRCFILES:%.c=%.o)
OBJBONUS	:=	$(SRCBONUS:%.c=%.o)

CFLAGS 		:=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCFILES) -o $(NAME)

bonus:
	$(CC) $(CFLAGS) $(SRCBONUS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJFILES) $(OBJBONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

norminette:
	norminette -R CheckForbiddenSourceHeader $(SRCFILES) $(SRCBONUS) $(HEADERFILES)

git:
	git add *

.PHONY: clean fclean re