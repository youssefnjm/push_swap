/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 14:36:31 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-02-14 14:36:31 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	set_index(t_stack *stack_a)
{
	t_stack *current;
	int i = 0;

	current = stack_a;
	while (current != NULL)
	{
		current->index = i;
		current = current->next;
		i++;
	}
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

#include <string.h>

void gg(void){
	system("leaks checker");
}

int	main(int ac, char **av)
{
	char	**str_numbers;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_len;
	// atexit(gg);
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (1);
	str_numbers = ft_join_num(ac, av);
	if (!str_numbers)
		return (1);
	if (check_argements(str_numbers, &stack_len) == 1)
		return (free_2d_array(str_numbers), write(2, "Error\n", 6), 1);
	build_stack(&stack_a, str_numbers);
	handle_moves(&stack_a, &stack_b);
	set_sorted_index(stack_a);
	set_index(stack_a);
	if (is_argument_sorted(&stack_a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_lst(&stack_a);
	return (0);
}


		// t_stack *current = stack_a;
		// puts("a");
		// while (current != NULL)
		// {
		// 	printf("%d ", current->value);
		// 	current = current->next;
		// }
		// // puts("\nb");
		// // current = stack_b;
		// // while (current != NULL)
		// // {
		// // 	printf("%d ", current->value);
		// // 	current = current->next;
		// // }
		// // puts("");
