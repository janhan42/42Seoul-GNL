/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:53:53 by janhan            #+#    #+#             */
/*   Updated: 2023/11/02 18:41:33 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*backup;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	char			*buff;
	char			*line;
	t_list			*node;
}	t_data;

/*---------------------util func------------------------*/

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int i);
char	*ft_substr(char const *str, unsigned int start, size_t len);
void	ft_list_clear(t_list **haed);
/*---------------------main func------------------------*/
char	*get_next_line(int fd);
#endif
