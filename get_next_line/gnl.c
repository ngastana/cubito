/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneko <eneko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:49:35 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/17 20:16:58 by eneko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

char	*ft_finalize_line(char *line, char *buf)
{
	char	*newline;
	int		to_copy;

	newline = ft_strchr(line, '\n');
	if (newline != NULL)
	{
		to_copy = newline - line + 1;
		ft_strcpy(buf, newline + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		buf[0] = '\0';
	}
	line[to_copy] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			countread;
	char		*newline;

	line = ft_strdup(buf);
	newline = ft_strchr(line, '\n');
	countread = 1;
	while (!newline && countread > 0)
	{
		countread = read(fd, buf, BUFFER_SIZE);
		if (countread <= 0)
			break ;
		buf[countread] = '\0';
		line = ft_strjoin(line, buf);
		newline = ft_strchr(line, '\n');
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	return (ft_finalize_line(line, buf));
}
