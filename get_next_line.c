/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:03:32 by janhan            #+#    #+#             */
/*   Updated: 2023/10/17 13:30:31 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

 #ifndef BUFFER_SIZE
 # define BUFFER_SIZE 1024
 #endif

static char *ft_cutchar(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if(line[count] == '\0' || line[1] == '\0')
		return (NULL);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

static char *ft_read(int fd, char *buff, char *backup)
{
	int		read_line;
	char	*temp_char;

	read_line = 1;
	while (read_line != '\0')
	{
		if ((read_line = read(fd, buff, BUFFER_SIZE)) == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buff[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp_char = backup;
		backup = ft_strjoin(temp_char, buff);
		free(temp_char);
		temp_char = NULL;
		if(ft_strchr(buff, '\n'))
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*backup;

	if ( fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	line = ft_read(fd, buff, backup);
	free(buff);
	if (!line)
	{
		if (backup)
		{
			free(backup);
			backup = NULL;
		}
		return (NULL);
	}
	backup = ft_cutchar(line);
	return (line);
}
