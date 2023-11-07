/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:28:26 by janhan            #+#    #+#             */
/*   Updated: 2023/11/07 12:34:49 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strchr(const char *str, int i)
{
	size_t	c;

	c = 0;
	while (str[c])
	{
		if (str[c] == i || str[c] == '\0')
			return (c);
		c++;
	}
	return (0);
}

void	*ft_list_delone(t_list **head, t_list *node)
{
	t_list	*cursor;

	cursor = *head;
	if (node == *head)
		*head = node->next;
	else
	{
		while (cursor->next && cursor->next != node)
			cursor = cursor->next;
		cursor->next = node->next;
	}
	free(node->backup);
	free(node);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*result;

	if (!str)
		return (NULL);
	i = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!result)
		return (NULL);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
