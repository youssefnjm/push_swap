/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-07 16:54:02 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-02-07 16:54:02 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	send_chunks(t_stack **stack_a, t_stack **stack_b, int moves)
{
	int	chunk;

	chunk = 50;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->sorted_index < chunk)
		{
			if ((*stack_a)->sorted_index > chunk - 25)
				pb(stack_b, stack_a);
			else
			{
				pb(stack_b, stack_a);
				if ((*stack_a) != NULL && !((*stack_a)->sorted_index < chunk))
					rr(stack_a, stack_b);
				else
					rb(stack_b, 1);
			}
			moves++;
		}
		else
			ra(stack_a, 1);
		if (moves >= chunk)
			chunk += 50;
	}
}

static	t_stack	*get_max(t_stack *stack_b, int flag)
{
	t_stack	*current;
	int		max;

	if (!stack_b)
		return (NULL);
	current = stack_b;
	max = current->sorted_index;
	while (current != NULL)
	{
		if (current->sorted_index > max)
			max = current->sorted_index;
		current = current->next;
	}
	if (flag == 1)
		max--;
	current = stack_b;
	while (current != NULL)
	{
		if (current->sorted_index == max)
			return (current);
		current = current->next;
	}
	return (NULL);
}

static	void	send_back(t_stack **a, t_stack **b, t_stack *max, int len)
{
	while (1)
	{
		how_much_far(*b, len);
		if (max->how_far > 0)
		{
			rb(b, 1);
		}
		else if (max->how_far < 0)
		{
			rrb(b, 1);
		}
		else if (max->how_far == 0)
		{
			pa(a, b);
			break ;
		}
	}
}

static	int	is_the_before_close(int before, int max)
{
	if (before < 0)
		before = -before;
	if (max < 0)
		max = -max;
	return (before < max);
}

void	sort_500_numbers(t_stack **stack_a, t_stack **stack_b, int stack_len)
{
	t_stack	*max;
	t_stack	*before_max;

	send_chunks(stack_a, stack_b, 0);
	while (*stack_b != NULL)
	{
		max = get_max(*stack_b, 0);
		before_max = get_max(*stack_b, 1);
		if (!max)
			return ;
		how_much_far(*stack_b, stack_len);
		if (before_max
			&& is_the_before_close(before_max->how_far, max->how_far) == 1)
		{
			send_back(stack_a, stack_b, before_max, stack_len);
			stack_len = stack_len - 1;
			send_back(stack_a, stack_b, max, stack_len);
			sa(stack_a, 1);
		}
		else
			send_back(stack_a, stack_b, max, stack_len);
		stack_len = stack_len - 1;
	}
}
