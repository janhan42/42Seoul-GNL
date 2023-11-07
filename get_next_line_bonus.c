/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:08:38 by janhan            #+#    #+#             */
/*   Updated: 2023/11/07 12:29:59 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list	*ft_new_node(int fd)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->backup = NULL;
	new_node->next = NULL;
	return (new_node);
}

static t_list	*ft_node_serch(t_list **head, int fd)
{
	t_list	*cursor;

	if (!*head)
		*head = ft_new_node(fd);
	cursor = *head;
	while (cursor)
	{
		if (cursor->fd == fd)
			return (cursor);
		if (!cursor->next)
			cursor->next = ft_new_node(fd);
		cursor = cursor->next;
	}
	return (NULL);
}

static char	*ft_read_txt(t_data *data)
{
	char	*temp;
	char	buff[BUFFER_SIZE + 1];
	ssize_t	read_index;

	read_index = 1;
	while (read_index != 0)
	{
		read_index = read(data->node->fd, buff, BUFFER_SIZE);
		if (read_index == 0)
			break ;
		else if (read_index == -1)
			return (NULL);
		buff[read_index] = '\0';
		if (!data->node->backup)
			data->node->backup = ft_strdup("");
		temp = data->node->backup;
		data->node->backup = ft_strjoin(data->node->backup, buff);
		free(temp);
		if (!data->node->backup)
			return (NULL);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (data->node->backup);
}

static char	*ft_cut_line(t_data *data, t_list **head, size_t i)
{
	char	*temp;

	temp = data->node->backup;
	data->node->backup = ft_strdup(&data->node->backup[i]);
	if (!data->node->backup)
	{
		free(temp);
		return (ft_list_delone(head, data->node));
	}
	temp[i] = '\0';
	data->res = ft_strdup(temp);
	free(temp);
	if (!data->res)
		return (ft_list_delone(head, data->node));
	if (!data->node->backup[0])
		ft_list_delone(head, data->node);
	return (data->res);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_data			data;
	size_t			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > SSIZE_MAX)
		return (NULL);
	data.node = ft_node_serch(&head, fd);
	if (!data.node)
		return (NULL);
	if (!ft_read_txt(&data))
		return (ft_list_delone(&head, data.node));
	i = 0;
	while (data.node->backup[i] && data.node->backup[i] != '\n')
		i++;
	if (data.node->backup[i] == '\n')
		return (ft_cut_line(&data, &head, i + 1));
	else
	{
		data.res = ft_strdup(data.node->backup);
		ft_list_delone(&head, data.node);
		if (!data.res)
			return (NULL);
		return (data.res);
	}
}
