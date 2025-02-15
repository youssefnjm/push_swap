/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-01 16:24:13 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-02-01 16:24:13 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	build_stack(t_stack **stack, char **str_numbers)
{
	t_stack	*node;
	int		i;
	int		len;

	i = 0;
	node = NULL;
	while (str_numbers[i] != NULL)
	{
		node = create_node(str_numbers[i], i);
		add_to_stack(stack, node);
		i++;
	}
	len = i;
	set_sorted_index(*stack);
	how_much_far(*stack, len);
	free_2d_array(str_numbers);
}

int	main(int ac, char **av)
{
	char	**str_numbers;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_len;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (1);
	str_numbers = ft_join_num(ac, av);
	if (!str_numbers)
		return (1);
	if (check_argements(str_numbers, &stack_len) == 1)
	{
		free_2d_array(str_numbers);
		return (write(2, "Error\n", 6), 1);
	}
	build_stack(&stack_a, str_numbers);
	sort_process(&stack_a, &stack_b, stack_len);
	free_lst(&stack_a);
	return (0);
}
