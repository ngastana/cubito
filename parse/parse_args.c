/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:55:35 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/10 15:55:50 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void ft_get_args(t_game *cube, int fd)
{
	int	i;
	char *ret;

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
	i = 1;
	cube->map[0] = ft_take_all(ret);
	while (cube->map[0] != NULL)
	{
		cube->map[i] = ft_take_all(get_next_line(fd));
		if (cube->map[i] == NULL)
			break ;
		i++;
	}
}