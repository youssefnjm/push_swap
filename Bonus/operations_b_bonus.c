/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 14:36:09 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-02-14 14:36:09 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb(t_stack **stack_b, int flag)
{
	t_stack	*top_node;
	t_stack	*second_node;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	top_node = *stack_b;
	second_node = top_node->next;
	top_node->next = second_node->next;
	second_node->next = top_node;
	*stack_b = second_node;
	if (flag)
		write (1, "sb\n", 3);
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*node_a;

	if (!stack_a || !(*stack_a))
		return ;
	node_a = *stack_a;
	*stack_a = (*stack_a)->next;
	node_a->next = *stack_b;
	*stack_b = node_a;
}

void	rb(t_stack **stack_b, int flag)
{
	t_stack	*top_node;
	t_stack	*last_node;

	if (!stack_b || !*stack_b || (*stack_b)->next == NULL)
		return ;
	top_node = *stack_b;
	*stack_b = top_node->next;
	last_node = top_node;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = top_node;
	top_node->next = NULL;
	if (flag)
		write (1, "rb\n", 3);
}

void	rrb(t_stack **stack_b, int flag)
{
	t_stack	*last_node;
	t_stack	*berfore_last_node;

	if (!stack_b || !*stack_b || (*stack_b)->next == NULL)
		return ;
	last_node = *stack_b;
	while (last_node->next != NULL)
		last_node = last_node->next;
	berfore_last_node = *stack_b;
	while (berfore_last_node->next != last_node)
		berfore_last_node = berfore_last_node->next;
	berfore_last_node->next = NULL;
	last_node->next = *stack_b;
	*stack_b = last_node;
	if (flag)
		write (1, "rrb\n", 4);
}
