/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:54:00 by ngastana          #+#    #+#             */
/*   Updated: 2024/09/17 15:04:27 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char *argv[])
{
	t_game	cube;
	int		i;
	int		fd;

	i = 0;
	i = ft_strlen(argv[1]);
	cube.file = NULL;
	if (argc != 2 || (argv[1][i - 1] != 'b' || argv[1][i - 2] != 'u' || argv[1][i - 3] != 'c' || argv[1][i - 4] != '.'))
		return (printf("Parameter bad written: ./cub3d <map>.cub\n"), 1);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (printf("Invalid file: make sure the file exists\n"), 1);
		cube.file = malloc(500);
		cube.map = malloc(500);
		cube.mlx = malloc(sizeof(t_mlx));
		ft_get_args(&cube, fd);
		close(fd);
		if (ft_parse_assets(&cube))
		{
			if (!ft_take_map(&cube))
				return (printf("Error4\n"), ft_clear_cub(&cube), 0);
			if (!ft_check_map_content(&cube))
				return (printf("Error5\n"), ft_clear_cub(&cube), 0);
			init_the_player(&cube);
			ft_start_game(&cube);
		}
		ft_clear_cub(&cube);
	}
}
