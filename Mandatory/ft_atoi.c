/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-01 17:24:20 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-02-01 17:24:20 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	check_overflow(size_t n, int signe)
{
	if (n >= 9223372036854775807 && signe == 1)
		return (-1);
	if (n > 9223372036854775807 && signe == -1)
		return (0);
	return (3);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		signe;
	size_t	n;

	i = 0;
	n = 0;
	signe = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		if (check_overflow(n, signe) != 3)
			return (check_overflow(n, signe));
		result = result * 10 + (str[i++] - 48);
	}
	return (result * signe);
}

int	check_int_range(const char *str)
{
	int		i;
	int		signe;
	int		bl;
	size_t	n;

	i = 0;
	n = 0;
	bl = 1;
	signe = 1;
	while (str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		bl = 0;
		n = n * 10 + (str[i++] - 48);
		if ((n > 2147483647 && signe == 1) || (n > 2147483648 && signe == -1))
			return (1);
	}
	return (bl);
}
