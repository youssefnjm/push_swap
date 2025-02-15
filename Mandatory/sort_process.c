/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-03 18:11:08 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-02-03 18:11:08 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_numbers(t_stack **stack_a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*stack_a)->value;
	n2 = (*stack_a)->next->value;
	n3 = (*stack_a)->next->next->value;
	if (n2 > n1 && n2 > n3 && n3 > n1)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (n2 < n1 && n2 < n3 && n1 < n3)
		sa(stack_a, 1);
	else if (n2 > n1 && n2 > n3 && n1 > n3)
		rra(stack_a, 1);
	else if (n2 < n1 && n2 < n3 && n1 > n3)
		ra(stack_a, 1);
	else if (n2 < n1 && n2 > n3)
	{
		ra(stack_a, 1);
		sa(stack_a, 1);
	}
}

void	sort_small_stack(t_stack **stack_a, t_stack **stack_b, int *stack_len)
{
	if ((*stack_len) <= 2)
		ra(stack_a, 1);
	else if ((*stack_len) <= 3)
		sort_3_numbers(stack_a);
	else if ((*stack_len) <= 4 || (*stack_len) <= 5)
		sort_5_numbers(stack_a, stack_b, stack_len);
}

int	is_argument_sorted(t_stack **stack_a)
{
	t_stack	*current;

	current = *stack_a;
	while (current != NULL)
	{
		if (current->index != current->sorted_index)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_process(t_stack **stack_a, t_stack **stack_b, int stack_len)
{
	if (is_argument_sorted(stack_a) == 1)
		return ;
	else if (stack_len <= 5)
		sort_small_stack(stack_a, stack_b, &stack_len);
	else if (stack_len <= 100)
		sort_100_numbers(stack_a, stack_b, stack_len);
	else
		sort_500_numbers(stack_a, stack_b, stack_len);
}
