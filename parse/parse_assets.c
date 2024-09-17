/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:50:57 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/17 15:44:59 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	ft_parse_assets(t_game *cube)
{
	int	fd;

	if (!ft_clean_file(cube))
		return (0);
	if (!cube->north || !cube->south || !cube->west
		|| !cube->east || !cube->floor || !cube->ceiling)
		return (printf("Invalid File: check parameters\n"), 0);
	fd = open(cube->north, O_RDONLY);
	if (fd < 0)
		return (printf("Invalid file: make sure the file exists\n"), 0);
	close(fd);
	fd = open(cube->south, O_RDONLY);
	if (fd < 0)
		return (printf("Invalid file: make sure the file exists\n"), 0);
	close(fd);
	fd = open(cube->west, O_RDONLY);
	if (fd < 0)
		return (printf("Invalid file: make sure the file exists\n"), 0);
	close(fd);
	fd = open(cube->east, O_RDONLY);
	if (fd < 0)
		return (printf("Invalid file: make sure the file exists\n"), 0);
	return (close(fd), 1);
}
