/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:38:57 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/20 12:04:05 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

char	*ft_fill_line(char *line, int start, int max_len)
{
	char	*join;
	char	*ret;
	int		i;

	i = 0;
	if (!line)
		return (NULL);
	join = malloc((max_len - start + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (i < max_len - start)
		join[i++] = 'x';
	join[i] = '\0';
	ret = ft_strjoin(line, join);
	return (free(join), ret);
}

int	ft_take_map(t_game *cube)
{
	int	max_len;
	int	i;
	int	j;

	i = -1;
	max_len = ft_map_max_len(cube);
	if (max_len == 0)
		return (0);
	while (cube->map[++i])
	{
		j = -1;
		while (cube->map[i][++j])
		{
			if (ft_isspace(cube->map[i][j]))
				cube->map[i][j] = 'x';
		}
	}
	i = -1;
	while (cube->map[++i])
	{
		j = ft_strlen(cube->map[i]);
		if (j < max_len)
			cube->map[i] = ft_fill_line(cube->map[i], j, max_len);
	}
	return (ft_spaces(cube->map));
}
