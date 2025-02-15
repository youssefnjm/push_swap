/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 14:36:01 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-02-14 14:36:01 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack **stack_a, int flag)
{
	t_stack	*top_node;
	t_stack	*second_node;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	top_node = *stack_a;
	second_node = top_node->next;
	top_node->next = second_node->next;
	second_node->next = top_node;
	*stack_a = second_node;
	if (flag)
		write(1, "sa\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_b;

	if (!stack_b || !(*stack_b))
		return ;
	node_b = *stack_b;
	*stack_b = (*stack_b)->next;
	node_b->next = *stack_a;
	*stack_a = node_b;
}

void	ra(t_stack **stack_a, int flag)
{
	t_stack	*top_node;
	t_stack	*last_node;

	if (!stack_a || !*stack_a || (*stack_a)->next == NULL)
		return ;
	top_node = *stack_a;
	*stack_a = top_node->next;
	last_node = top_node;
	while (last_node && last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = top_node;
	top_node->next = NULL;
	if (flag)
		write(1, "ra\n", 3);
}

void	rra(t_stack **stack_a, int flag)
{
	t_stack	*last_node;
	t_stack	*berfore_last_node;

	if (!stack_a || !*stack_a || (*stack_a)->next == NULL)
		return ;
	last_node = *stack_a;
	while (last_node->next != NULL)
		last_node = last_node->next;
	berfore_last_node = *stack_a;
	while (berfore_last_node->next != last_node)
		berfore_last_node = berfore_last_node->next;
	berfore_last_node->next = NULL;
	last_node->next = *stack_a;
	*stack_a = last_node;
	if (flag)
		write(1, "rra\n", 4);
}
