/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-02 16:06:25 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-02-02 16:06:25 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	how_much_far(t_stack *stack, int len)
{
	t_stack	*current;
	int		i;
	int		half1;
	int		half2;

	i = 0;
	current = stack;
	half2 = len / 2;
	half1 = len - half2;
	while (current != NULL)
	{
		if (i < half1)
			current->how_far = i;
		else
		{
			current->how_far = half2 * -1;
			half2--;
		}
		i++;
		current = current->next;
	}
}

void	set_sorted_index(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*current;
	int		count;

	tmp = stack;
	while (stack != NULL)
	{
		current = tmp;
		count = 0;
		while (current != NULL)
		{
			if (stack->value > current->value)
				count++;
			current = current->next;
		}
		stack->sorted_index = count;
		stack = stack->next;
	}
}

t_stack	*get_last_node(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current != NULL && current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}

void	add_to_stack(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	last = NULL;
	if (!stack || !new)
		return ;
	if (*stack == NULL)
		*stack = new;
	else
	{
		last = get_last_node(*stack);
		last->next = new;
	}
}

t_stack	*create_node(char *value, int index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = ft_atoi(value);
	node->index = index;
	node->sorted_index = -1;
	node->how_far = -1;
	node->next = NULL;
	return (node);
}
