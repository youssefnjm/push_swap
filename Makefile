#**************************************************************************#
#                                                                          #
#                                                       :::      ::::::::  #
#  Makefile                                           :+:      :+:    :+:  #
#                                                   +:+ +:+         +:+    #
#  By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+       #
#                                               +#+#+#+#+#+   +#+          #
#  Created: 2025-02-01 17:07:00 by ynoujoum          #+#    #+#            #
#  Updated: 2025-02-01 17:07:00 by ynoujoum         ###   ########.fr      #
#                                                                          #
#**************************************************************************#

NAME=push_swap

NAME_BONUS=checker

CC=cc

CFLAGS=-Wall -Wextra -Werror

SRC_BNS= ./Bonus/push_swap_bonus.c \
			./Bonus/ft_atoi_bonus.c \
			./Bonus/ft_split_bonus.c \
			./Bonus/ft_join_num_bonus.c \
			./Bonus/check_argements_bonus.c \
			./Bonus/memory_utils_bonus.c \
			./Bonus/build_stack_bonus.c \
			./Bonus/operations_a_bonus.c \
			./Bonus/operations_b_bonus.c \
			./Bonus/operations_s_bonus.c \
			./Bonus/applic_moves_bonus.c \
			./Bonus/get_next_line_bonus.c \
			./Bonus/get_next_line_utils_bonus.c

SRC = ./Mandatory/push_swap.c \
		./Mandatory/ft_atoi.c \
		./Mandatory/ft_split.c \
		./Mandatory/ft_join_num.c \
		./Mandatory/check_argements.c \
		./Mandatory/memory_utils.c \
		./Mandatory/build_stack.c \
		./Mandatory/operations_a.c \
		./Mandatory/operations_b.c \
		./Mandatory/operations_s.c \
		./Mandatory/sort_process.c \
		./Mandatory/sort_5.c \
		./Mandatory/sort_100.c \
		./Mandatory/sort_500.c 

OBJ=$(SRC:.c=.o)

OBJ_BNS=$(SRC_BNS:.c=.o)

./Mandatory/%.o : ./Mandatory/%.c ./Mandatory/push_swap.h 
	$(CC) $(CFLAGS) -c $< -o $@

./Bonus/%.o : ./Bonus/%.c ./Bonus/push_swap_bonus.h 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BNS)
	$(CC) $(CFLAGS) $(OBJ_BNS) -o $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ) $(OBJ_BNS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
