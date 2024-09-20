/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:55:35 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/20 12:46:17 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	ft_get_after_map(int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		if (!ft_isspace(tmp[0]))
			return (printf("Invalid File: check parameters\n"), free(tmp), 1);
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp == NULL)
			return (free(tmp), 0);
	}
	return (0);
}

int	ft_get_map(t_game *cube, char *ret, int fd)
{
	int		i;

	cube->north = NULL;
	cube->south = NULL;
	cube->west = NULL;
	cube->east = NULL;
	i = 1;
	cube->map[0] = ft_take_all(ret);
	while (cube->map[0] != NULL && i < 50)
	{
		cube->map[i] = ft_take_all(get_next_line(fd));
		if (cube->map[i] == NULL)
			break ;
		else if (cube->map[i][0] == 'M')
		{
			cube->map[i] = NULL;
			return (printf("Invalid File: check parameters\n"), 1);
		}
		i++;
	}
	if (i == 50)
		cube->map[i] = NULL;
	if (!ft_valid_close(cube->map[i -1]) || i == 50)
		return (printf("Invalid File: check parameters\n"), 1);
	return (0);
}

int	ft_get_args(t_game *cube, int fd)
{
	int		i;
	char	*ret;

	cube->flag = 0;
	cube->ceiling = 0;
	cube->floor = 0;
	i = 0;
	while (1)
	{
		cube->file[i] = get_next_line(fd);
		if (cube->file[i] == NULL || ft_valid_close(cube->file[i]))
		{
			ret = ft_strdup(cube->file[i]);
			free(cube->file[i]);
			cube->file[i] = NULL;
			break ;
		}
		if (cube->file[i][0] == '\n')
		{
			free(cube->file[i]);
			continue ;
		}
		i++;
	}
	return (ft_get_map(cube, ret, fd));
}
