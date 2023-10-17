/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:50:21 by janhan            #+#    #+#             */
/*   Updated: 2023/10/17 12:36:52 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

/*---------------------------------get_next_line---------------------------------*/
char	*get_next_line(int fd);
char	*ft_substr(char const *str, unsigned int start, size_t len);
int	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int i);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
