# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 17:45:41 by rkaufman          #+#    #+#              #
#    Updated: 2022/02/08 18:49:14 by rkaufman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_MANDA	:=	push_swap
NAME_BONUS	:=	checker
NAME_LIB	:=	libft_push_swap.a

LIB_PATH	:=	./

CC			:=	gcc
HEADERFILE	:=	push_swap.h

SRC_LIB		:=	ft_error.c \
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
				ft_sort0.c \
				ft_sort1.c \
				ft_array_string.c \
				ft_check_number.c \
				ft_read_input.c

SRC_MANDA	:=	ft_push_swap.c

SRC_BONUS	:=	ft_checker.c

OBJ_LIB		:=	$(SRC_LIB:%.c=%.o)

CFLAGS		:=	-Wall -Wextra -Werror

all: $(NAME_MANDA)

$(NAME_MANDA): $(NAME_LIB)
	$(CC) $(CFLAGS) $(SRC_MANDA) -o $(NAME_MANDA) -L$(LIB_PATH) -lft_push_swap

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(NAME_LIB)
	$(CC) $(CFLAGS) $(SRC_BONUS) -o $(NAME_BONUS) -L$(LIB_PATH) -lft_push_swap

$(NAME_LIB): $(OBJ_LIB)
	$(AR) rcs $(NAME_LIB) $(OBJ_LIB)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_LIB)

fclean: clean
	rm -f $(NAME_MANDA) $(NAME_BONUS) $(NAME_LIB)

re: fclean all

norminette:
	norminette -R CheckForbiddenSourceHeader $(SRC_MANDA) $(SRC_BONUS) $(SRC_LIB) $(HEADERFILE)

git:
	git add *

.PHONY: clean fclean re