/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 15:43:42 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-02-06 15:43:42 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_stack(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	while (current != NULL)
	{
		if (current->sorted_index == 0)
			return (current->how_far);
		current = current->next;
	}
	return (0);
}

void	sort_5_moves(t_stack **stack_a, t_stack **stack_b, int *len, int far) 

{
	while ((*len) != 3)
	{
		set_sorted_index(*stack_a);
		how_much_far(*stack_a, (*len));
		far = get_min_stack(*stack_a);
		while (*stack_a)
		{
			if (far > 0)
			{
				ra(stack_a, 1);
				far--;
			}
			else if (far < 0)
			{
				rra(stack_a, 1);
				far++;
			}
			else
			{
				pb(stack_b, stack_a);
				(*len)--;
				break ;
			}
		}
	}
}

void	sort_5_numbers(t_stack **stack_a, t_stack **stack_b, int *stack_len)
{
	int	how_far;

	how_far = 0;
	sort_5_moves(stack_a, stack_b, stack_len, how_far);
	sort_3_numbers(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	(*stack_len) += 2;
}
