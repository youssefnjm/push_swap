/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_num_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 14:35:24 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-02-14 14:35:24 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static	int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static	char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	p = (char *)malloc(sizeof(char) * i + 1);
	if (p == NULL)
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

static	size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (p == NULL)
		return (NULL);
	while (s1[j] != '\0')
		p[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		p[i++] = s2[j++];
	p[i] = '\0';
	free(s1);
	return (p);
}

char	**ft_join_num(int ac, char **av)
{
	char	**splite_str;
	char	*join_str;
	int		i;

	i = 1;
	join_str = ft_strdup("");
	if (!join_str)
		return (NULL);
	while (i < ac)
	{
		if (check_spaces(av[i]) == 1)
			return (write(2, "Error\n", 6), free(join_str), NULL);
		if (av[i][0] == '\0')
			return (write(2, "Error\n", 6), free(join_str), NULL);
		join_str = ft_strjoin(join_str, av[i]);
		join_str = ft_strjoin(join_str, " ");
		i++;
	}
	splite_str = ft_split(join_str, ' ');
	free(join_str);
	join_str = NULL;
	if (!splite_str)
		return (NULL);
	return (splite_str);
}
