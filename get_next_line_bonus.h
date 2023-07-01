/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:44:54 by ntardy            #+#    #+#             */
/*   Updated: 2022/06/08 21:45:16 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strcat_remake(char *next_line, char *buff);
char	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup_remake(const char *src, char c);
int		ft_strlen_remake(const char *s, char c);

#endif
