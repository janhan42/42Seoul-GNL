/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:28:26 by janhan            #+#    #+#             */
/*   Updated: 2023/10/20 16:02:15 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char 	*result;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	if (result == s1)
		return (result);
	while (i < len)
	{
		result[i] = s1[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t 	j;
	char	*str;

	i = 0;
	j = 0;
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

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp_str;

	temp_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (i >= start &&  j < len)
		{
			temp_str[j] = str[i];
			j++;
		}
		i++;
	}
	temp_str[j] = '\0';
	return (temp_str);
}
