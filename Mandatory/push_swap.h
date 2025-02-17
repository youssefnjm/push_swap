/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-01 16:24:16 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-02-01 16:24:16 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct stack
{
	int				value;
	int				index;
	int				sorted_index;
	int				how_far;
	struct stack	*next;
}	t_stack;

char	**ft_join_num(int ac, char **av);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		check_int_range(const char *str);

int		check_argements(char **str_numbers, int *stack_len);

void	free_2d_array(char **ptr);
void	free_lst(t_stack **stack);

void	how_much_far(t_stack *stack, int len);
void	set_sorted_index(t_stack *stack);
t_stack	*get_last_node(t_stack *stack);
void	add_to_stack(t_stack **stack, t_stack *new);
t_stack	*create_node(char *value, int index);

void	sa(t_stack **stack_a, int flag);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a, int flag);
void	rra(t_stack **stack_a, int flag);

void	sb(t_stack **stack_b, int flag);
void	pb(t_stack **stack_b, t_stack **stack_a);
void	rb(t_stack **stack_b, int flag);
void	rrb(t_stack **stack_b, int flag);

void	ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void	sort_process(t_stack **stack_a, t_stack **stack_b, int stack_len);

int		get_min_stack(t_stack *stack_a);
void	sort_5_moves(t_stack **stack_a, t_stack **stack_b, int *len, int far);
void	sort_5_numbers(t_stack **stack_a, t_stack **stack_b, int *stack_len);
void	sort_3_numbers(t_stack **stack_a);
void	sort_100_numbers(t_stack **stack_a, t_stack **stack_b, int stack_len);
void	sort_500_numbers(t_stack **stack_a, t_stack **stack_b, int stack_len);

#endif