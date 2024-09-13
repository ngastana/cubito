/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:38:57 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/13 10:37:59 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	ft_valid_close(const char *str)
{
	int i = 0;
	if (str[i] == '\n')
		return (0);
	while(str[i])
	{
		if (str[i] == 32 || (str[i] < 14 && str[i] > 8) || str[i] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

char *ft_take_all(char *line)
{
	char *ret;
	int i = 0;
	int end = 0;
	if (!line)
		return (NULL);
	if (line[i] == '\n')
		return (free(line), NULL);
	while (ft_isspace(line[i]))
		i++;
	if (line[i] != '1')
		return (free(line), printf("Error1\n"), NULL);
	end = ft_strlen(line) -1;
	while (ft_isspace(line[end]))
		end--;
	if (line[end] != '1')
		return (free(line), printf("Erro2\n"), NULL);
	ret = ft_substr(line, 0, end +1);
	return (free(line), ret);
}

int ft_check_map_content(t_game *cube)
{
	int i = 0;
	int j = 0;
	int flag = 0;

	while (cube->map[i])
	{
		j = 0;
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == 'N' || cube->map[i][j] == 'S' || cube->map[i][j] == 'W' || cube->map[i][j] == 'E')
			{
				flag++;
				cube->plyr_x = j;
				cube->plyr_y = i;
				cube->mlx->direction = cube->map[i][j];
				cube->map[i][j]  = '0';
			}
			j++;
		}
		i++;
	}
	cube->map_width = j;
	cube->map_height = i;
	if (flag != 1)
		return (printf("Error3\n"), 0);
	else
		return (1);
}

int	ft_map_max_len(char **map) 
{
	int i = 0;
	int max_len = 0;
	int len;

	while (map[i]) 
	{
		len = ft_strlen(map[i]); 	
		if (len > max_len) 
			max_len = len;	
		i++;
	}
	i = 0;
	while (map[i])
	{
		len = 0;
		while (map[i][len])
		{
			if (map[i][len] == '0' || map[i][len] == 'N' || map[i][len] == 'S' || map[i][len] == 'W' || map[i][len] == 'E')
			{
				if (map[i][len + 1] == '\0' || map[i][len - 1] == '\0')
					return (0);
				if (map[i + 1] == NULL || map[i - 1] == NULL)
					return (0);
				if (map[i][len + 1] == ' ' || map[i][len - 1] == ' ')
					return (0);
				if (map[i + 1][len] == ' ' || map[i - 1][len] == ' ')
					return (0);
			}
			len++;
		}
		i++;
	}
	return (max_len);
}

char *ft_fill_line(char *line, int start, int max_len)
{
	char *join;
	char *ret;
	int i = 0;
	if (!line)
		return (NULL);
	join = malloc((max_len - start + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while(i < max_len - start)
		join[i++] = '1';
	join[i] = '\0';
	ret = ft_strjoin(line, join);
	return (free(join), ret);
}

int	ft_take_map(t_game *cube)
{
	int max_len = ft_map_max_len(cube->map);
	int i = 0;
	int j = 0;
	
	if (max_len == 0)
		return (0);
	while(cube->map[i])
	{
		j = 0;
		while (cube->map[i][j])
		{
			if (ft_isspace(cube->map[i][j]))
				cube->map[i][j] = '1';
			j++;
		}
		i++;
	}
	i = 0;
	while (cube->map[i])
	{
		j = ft_strlen(cube->map[i]);
		if (j < max_len)
			cube->map[i] = ft_fill_line(cube->map[i], j, max_len);
		i++;
	}
	return (1);
}
