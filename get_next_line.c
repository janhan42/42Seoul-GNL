/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:51:32 by janhan            #+#    #+#             */
/*   Updated: 2023/10/20 17:03:08 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif

static char	*read_line(int fd, char *buff, char *backup)
{
	int		read_index;
	char	*temp_back;

	read_index = 1;
	while (read_index != 0)
	{
		if ((read_index = read(fd, buff, BUFFER_SIZE)) == -1)
			return (NULL);
		else if (read_index == 0)
			break ;
		buff[read_index] = '\0';
		if (!backup) // 처음 읽어들이는 파일이라면
			backup = ft_strdup(""); // 빈문자열 생성
		temp_back = backup;
		backup = ft_strjoin(temp_back, buff); // 그후 backup에 읽어들인 파일을 이어붙이는 형식으로 삽입
		free(temp_back); // 그후 필요 없는 temp_back을 프리 시켜서 메모리 관리
		temp_back = NULL; // 이중 free방지
		if (ft_strchr(buff, '\n')) // buff에서 \n주소 까지 밀어둠
			break ; // 그후 break
	}
	return (backup); //
}

static char	*cut_line(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
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

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char *backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	line = read_line(fd, buff, backup);
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
	backup = cut_line(line);
	return (line);
}
