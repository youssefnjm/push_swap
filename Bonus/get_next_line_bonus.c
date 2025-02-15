/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 15:16:10 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-02-14 15:16:10 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static	char	*reset_ptr(char *ptr)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = NULL;
	while (ptr[i] != '\0' && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\0')
		return (free(ptr), NULL);
	i++;
	if (ptr[i] == '\0')
        return (free(ptr), NULL);
	while (ptr[i + j] != '\0')
		j++;
	tmp = malloc(sizeof(char) * (j + 1));
	if (!tmp)
		return (free(ptr), NULL);
	ft_strcpy(tmp, &ptr[i]);
	free(ptr);
	return (tmp);
}

static	char	*get_line(char *str)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static	char	*create_line(char *ptr, int fd)
{
	char	*buffer;
	int		chars_read;

	buffer = malloc((sizeof(char) * 1) + 1);
	if (!buffer)
		return (free(ptr), ptr = NULL, NULL);
	if (!ptr)
		ptr = ft_strdupp("");
	while (ptr && !check_new_line(ptr))
	{
		chars_read = read(fd, buffer, 1);
		if (chars_read <= 0)
		{
			if (chars_read < 0)
				return (free(buffer), buffer = NULL, NULL);
			return (free(buffer), buffer = NULL, ptr);
		}
		buffer[chars_read] = '\0';
		ptr = ft_strjoinn(ptr, buffer);
		if (!ptr)
			return (free(buffer), buffer = NULL, NULL);
	}
	free(buffer);
	buffer = NULL;
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*ptr = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || read(fd, line, 0) < 0)
		return (free(ptr), ptr = NULL, NULL);
	ptr = create_line(ptr, fd);
	if (!ptr || ptr[0] == '\0')
	{
		free(ptr);
		ptr = NULL;
		return (NULL);
	}
	line = get_line(ptr);
	if (line == NULL)
	{
		free(ptr);
		ptr = NULL;
		return (NULL);
	}
	ptr = reset_ptr(ptr);
	return (line);
}
