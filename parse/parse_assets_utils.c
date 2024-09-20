/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assets_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:43:49 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/20 15:32:16 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

char	*ft_clear_textures(char *str)
{
	char	*s2;
	int		start;
	int		end;

	start = 0;
	if (!str)
		return (NULL);
	while (str[start] && ft_isspace(str[start]))
		start++;
	end = start;
	while (str[end] && !ft_isspace(str[end]))
		end++;
	start = end;
	while (ft_isspace(str[start]))
		start++;
	end = start;
	while (str[end] && !ft_isspace(str[end]))
		end++;
	s2 = ft_substr(str, start, (end - start));
	return (free(str), s2);
}

int	ft_trans_rgb(int *rgb)
{
	return (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

int	ft_clear_colors(char *color)
{
	char	**split;
	int		rgb[3];
	int		i;

	i = 0;
	if (!color)
		return (0);
	while (color[i] && ft_isspace(color[i]))
		i++;
	if ((color[i] != 'F' && color[i] != 'C') || color[i + 1] != ' ')
		return (free(color), 0);
	while (!ft_isspace(color[i + 1]))
		i++;
	split = ft_split(color + i + 1, ',');
	free(color);
	i = -1;
	while (split[++i])
	{
		rgb[i] = ft_atoi(split[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (ft_free_matrix(split), 0);
	}
	if (i != 3)
		return (ft_free_matrix(split), 0);
	return (ft_free_matrix(split), ft_trans_rgb(rgb));
}

char	*ft_check_xpm(char *dir)
{
	int	i;

	i = ft_strlen(dir);
	if (dir[i - 1] != 'm' || dir[i - 2] != 'p'
		|| dir[i - 3] != 'x' || dir[i - 4] != '.')
	{
		free(dir);
		return (printf("Invalid Parameter: not xpm file\n"), NULL);
	}
	return (dir);
}

int	ft_clean_file(t_game *cube)
{
	int	i;

	i = 0;
	while (cube->file[i])
	{
		if (ft_strstr(cube->file[i], "NO ") && !cube->north)
			cube->north = ft_check_xpm(ft_clear_textures(cube->file[i]));
		else if (ft_strstr(cube->file[i], "SO ") && !cube->south)
			cube->south = ft_check_xpm(ft_clear_textures(cube->file[i]));
		else if (ft_strstr(cube->file[i], "WE ") && !cube->west)
			cube->west = ft_check_xpm(ft_clear_textures(cube->file[i]));
		else if (ft_strstr(cube->file[i], "EA ") && !cube->east)
			cube->east = ft_check_xpm(ft_clear_textures(cube->file[i]));
		else if (ft_strstr(cube->file[i], "F "))
			cube->floor = ft_clear_colors(cube->file[i]);
		else if (ft_strstr(cube->file[i], "C "))
			cube->ceiling = ft_clear_colors(cube->file[i]);
		else
			free(cube->file[i]);
		i++;
	}
	if (i == 6)
		return (1);
	return (printf("Invalid File: check parameters\n"), 0);
}
