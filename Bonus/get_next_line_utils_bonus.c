/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 15:15:55 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-02-14 15:15:55 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strlenn(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_new_line(char	*str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdupp(const char *s1)
{
	char	*p;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	p = malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	char	*str;
	int		s2_len;
	int		i;
	int		j;

	s2_len = ft_strlenn(s2);
	i = 0;
	j = 0;
	str = malloc((ft_strlenn(s1) + s2_len + 1) * sizeof(char));
	if (!str)
		return (free(s1), s1 = NULL, NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

void	ft_strcpy(char	*dest, char	*src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
