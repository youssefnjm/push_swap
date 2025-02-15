/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 14:35:51 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-02-14 14:35:51 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_2d_array(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

void	free_lst(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;

	current = *stack;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}
