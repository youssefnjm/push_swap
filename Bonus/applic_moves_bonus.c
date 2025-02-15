/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applic_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 16:33:44 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-02-14 16:33:44 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static	int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

void handle_moves(t_stack **stack_a, t_stack **stack_b)
{
	char *buffer;

	buffer = get_next_line(0);
	while (buffer)
	{
		if (ft_strcmp(buffer, "sa\n") == 0)
			sa(stack_a, 0);
		else if (ft_strcmp(buffer, "pa\n") == 0)
			pa(stack_a, stack_b);
		else if (ft_strcmp(buffer, "ra\n") == 0)
			ra(stack_a, 0);
		else if (ft_strcmp(buffer, "rra\n") == 0)
			rra(stack_a, 0);
		else if (ft_strcmp(buffer, "sb\n") == 0)
			sb(stack_b, 0);
		else if (ft_strcmp(buffer, "pb\n") == 0)
			pb(stack_b, stack_a);
		else if (ft_strcmp(buffer, "rb\n") == 0)
			rb(stack_b, 0);
		else if (ft_strcmp(buffer, "rrb\n") == 0)
			rrb(stack_b, 0);
		else if (ft_strcmp(buffer, "ss\n") == 0)
			ss(stack_a, stack_b);
		else if (ft_strcmp(buffer, "rr\n") == 0)
			rr(stack_a, stack_b);
		else if (ft_strcmp(buffer, "rrr\n") == 0)
			rrr(stack_a, stack_b);
		else
		{
			if (stack_a && *stack_a)
				free_lst(stack_a);
			if (stack_b && *stack_b)
				free_lst(stack_b);
			write(1, "Error\n", 6);
			free(buffer);
			exit(1);
		}
		free(buffer);
		buffer = get_next_line(0);
	}
	buffer = NULL;
	if (stack_b && *stack_b)
	{
		if (stack_a && *stack_a)
			free_lst(stack_a);
		if (stack_b && *stack_b)
			free_lst(stack_b);
		write(1, "KO\n", 3);
		exit(1);
	}
}
