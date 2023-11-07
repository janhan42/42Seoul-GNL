/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:53:53 by janhan            #+#    #+#             */
/*   Updated: 2023/11/07 12:26:40 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				fd;
	char			*backup;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	char			*buff;
	char			*res;
	t_list			*node;
}	t_data;

/*---------------------util func------------------------*/

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strchr(const char *str, int i);
void	*ft_list_delone(t_list **head, t_list *node);
char	*ft_strdup(const char *str);
/*---------------------main func------------------------*/
char	*get_next_line(int fd);
#endif
