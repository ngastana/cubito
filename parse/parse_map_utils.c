/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:46:38 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/20 15:21:11 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	ft_valid_close(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '\n')
		return (0);
	while (str[i])
	{
		if (str[i] == 32 || (str[i] < 14 && str[i] > 8) || str[i] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

char	*ft_take_all(char *line)
{
	char	*ret;
	int		i;
	int		end;

	i = 0;
	end = 0;
	if (!line)
		return (NULL);
	if (line[i] == '\n')
		return (free(line), NULL);
	while (ft_isspace(line[i]))
		i++;
	if (line[i] != '1')
		return (free(line), "M");
	end = ft_strlen(line) -1;
	while (ft_isspace(line[end]))
		end--;
	if (line[end] != '1')
		return (free(line), "M");
	ret = ft_substr(line, 0, end + 1);
	return (free(line), ret);
}

int	ft_check_map_content(t_game *cube)
{
	int	i;
	int	j;

	i = -1;
	while (cube->map[++i])
	{
		j = -1;
		while (cube->map[i][++j])
		{
			if (cube->map[i][j] == 'N' || cube->map[i][j] == 'S'
				|| cube->map[i][j] == 'W' || cube->map[i][j] == 'E')
			{
				cube->flag++;
				cube->plyr_x = j;
				cube->plyr_y = i;
				cube->mlx->direction = cube->map[i][j];
				cube->map[i][j] = '0';
			}
			else if ((cube->map[i][j] != '1' && cube->map[i][j] != '0' \
			&& cube->map[i][j] != ' ') || cube->flag > 1)
				return (0);
		}
	}
	return (1);
}

int	ft_spaces(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				if (map[i][j + 1] == '\0' || map[i][j - 1] == '\0' || \
				map[i][j + 1] == ' ' || map[i][j - 1] == ' ')
					return (0);
				else if (map[i + 1][j] == '\0' || map[i - 1][j] == '\0' || \
				map[i][j + 1] == 'x' || map[i][j - 1] == 'x')
					return (0);
				else if (map[i + 1][j] == ' ' || map[i - 1][j] == ' ' || \
				map[i + 1][j] == 'x' || map[i - 1][j] == 'x')
					return (0);
			}
		}
	}
	return (1);
}

int	ft_map_max_len(t_game *cube)
{
	int	i;
	int	max_len;
	int	len;

	i = 0;
	max_len = 0;
	while (cube->map[i])
	{
		len = ft_strlen(cube->map[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	cube->map_width = max_len;
	cube->map_height = i;
	return (max_len);
}
