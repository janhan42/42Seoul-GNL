/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:28:26 by janhan            #+#    #+#             */
/*   Updated: 2023/11/04 17:54:03 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./get_next_line.h"


void	ft_list_clear(t_list **head)
{
	t_list	*next_node;
	t_list	*cursor;

	cursor = *head;
	while (cursor != NULL)
	{
		next_node = cursor->next;
		free(cursor->backup);
		free(cursor);
		cursor = next_node;
	}
	*head = NULL;
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int i)
{
	if (i == '\0')
		return ((char *)str);
	while (*str)
	{
		if (*str == i)
			return ((char *)str);
		str++;
	}
	return (0);
}

void	ft_list_dalone(t_list **head, int fd)
{
	t_list	*cursor;
	t_list	*before_node;
	t_list	*next_node;

	cursor = *head;
	while (cursor)
	{

		next_node = cursor->next;


	}
	// TODO:
}

#include <string.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*result;

	len = ft_strlen(s1);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	memcpy(result, s1, len);
	result[len] = '\0';
	return (result);
}
