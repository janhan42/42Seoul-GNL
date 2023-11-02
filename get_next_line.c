/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:08:38 by janhan            #+#    #+#             */
/*   Updated: 2023/11/02 19:02:15 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

t_list	*ft_new_node(int fd)
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

t_list	*ft_node_serch(t_list **list, int fd)
{
	t_list	*cursor;

	if (*list == NULL)
	{
		*list = ft_new_node(fd);
		if (!*list)
			return (NULL);
		return (*list);
	}
	cursor = *list;
	while (cursor)
	{
		if (cursor->fd == fd)
		{
			return (cursor);
		}
		cursor = cursor->next;
	}
	cursor = *list;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = ft_new_node(fd);
	return (cursor->next);
}

char	*read_txt(int fd, char *buff, t_list *list)
{
	char	*temp_back;
	int		read_index;

	read_index = 1;
	while (read_index != 0)
	{
		read_index = read(fd, buff, BUFFER_SIZE);
		if (read_index == 0)
			break ;
		else if (read_index == -1)
			return (NULL);
		buff[read_index] = '\0';
		if (!list->backup)
			list->backup = ft_substr("", 0, 1);
		if (!list->backup)
			return (NULL);
		temp_back = list->backup;
		list->backup = ft_strjoin(temp_back, buff);
		free(temp_back);
		temp_back = NULL;
		if (!list->backup)
			return (NULL);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (list->backup);
}

char	*cut_line(char *line)
{
	size_t	count;
	size_t	len;
	char	*temp;

	count = 0;
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (NULL);
	temp = ft_substr(line, count + 1, len - count);
	if (!temp)
		return (NULL);
	if (*temp == '\0')
	{
		free(temp);
		temp = NULL;
	}
	else
		line[count + 1] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_data			data;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data.node = ft_node_serch(&head, fd);
	data.buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!data.buff || !data.node)
	{
		free(data.buff);
		ft_list_clear(&head);
		return (NULL);
	}
	data.line = read_txt(fd, data.buff, head);
	free(data.buff);
	data.buff = NULL;
	if (!data.line)
		ft_list_clear(&head);
	else
		data.node->backup = cut_line(data.line);
	return (data.line);
}

// int main(int ac, char **av)
// {
// 	int fd, fd1;
// 	char *line;

// 	fd = open("test.txt", O_RDONLY);
// 	fd1 = open("test2.txt", O_RDONLY);
// 	printf("%d %d", fd, fd1);
// 	while (1)
// 	{
// 		scanf("%d", &fd);
// 		line = get_next_line(fd);
// 		printf("main line return value : %s\n", line);
// 		free(line);
// 		if (fd == 5)
// 			break ;
// 	}
// 	return (0);
// }
