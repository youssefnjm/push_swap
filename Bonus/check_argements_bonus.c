/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argements_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 14:34:41 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-02-14 14:34:41 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	*create_arr(char **str_numbers, int len)
{
	int		i;
	int		*arr;

	i = 0;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	while (str_numbers[i])
	{
		arr[i] = ft_atoi(str_numbers[i]);
		i++;
	}
	return (arr);
}

int	detect_repeated_digits(char **str_numbers, int len)
{
	int	i;
	int	j;
	int	*arr;
	int	tmp;

	arr = create_arr(str_numbers, len);
	if (!arr)
		return (1);
	i = 0;
	while (i < len)
	{
		tmp = arr[i];
		j = 0;
		while (j < len)
		{
			if (i != j && arr[j] == tmp)
				return (free(arr), 1);
			j++;
		}
		i++;
	}
	free(arr);
	return (0);
}

int	check_all_conditions(char *number)
{
	int	j;

	j = 0;
	if (number[j] == '-' || number[j] == '+')
		j++;
	if (number[j] == '\0')
		return (1);
	while (number[j])
	{
		if (!(number[j] >= '0' && number[j] <= '9'))
			return (1);
		j++;
	}
	if (check_int_range(number) == 1)
		return (1);
	return (0);
}

int	are_all_digits(char **str_numbers, int *len)
{
	int	i;

	i = 0;
	while (str_numbers[i])
	{
		if (check_all_conditions(str_numbers[i]) == 1)
			return (1);
		i++;
		(*len)++;
	}
	return (0);
}

int	check_argements(char **str_numbers, int *stack_len)
{
	*stack_len = 0;
	if (are_all_digits(str_numbers, stack_len) == 1)
		return (1);
	if (detect_repeated_digits(str_numbers, *stack_len) == 1)
		return (1);
	return (0);
}
