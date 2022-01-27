# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 17:45:41 by rkaufman          #+#    #+#              #
#    Updated: 2022/01/23 13:20:10 by rkaufman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:=	push_swap
CC 			:=	gcc
HEADERFILES :=	push_swap.h

SRCFILES 	:=	ft_push_swap.c \
				ft_error.c \
				ft_check_argv.c \
				ft_memory.c \
				ft_list_combined.c \
				ft_list.c \
				ft_check_stack.c \
				ft_operation_swap.c \
				ft_operation_push.c \
				ft_operation_rotate.c \
				ft_operation_reverse_rotate.c \
				ft_sort.c

SRCBONUS	:=	

OBJFILES 	:=	$(SRCFILES:%.c=%.o)
OBJBONUS	:=	$(SRCBONUS:%.c=%.o)

CFLAGS 		:=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCFILES) -o $(NAME)

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

norminette:
	norminette -R CheckForbiddenSourceHeader $(SRCFILES) $(HEADERFILES)

git:
	git add *

.PHONY: clean fclean re