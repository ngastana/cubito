/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:56:55 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/17 17:33:50 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	init_the_player(t_game *cube)
{
	cube->plyr_x += 0.5;
	cube->plyr_y += 0.5;
	cube->mlx->width = 800;
	cube->mlx->height = 600;
	if (cube->mlx->direction == 'W')
		cube->angle = PI;
	else if (cube->mlx->direction == 'N')
		cube->angle = PI / 2;
	else if (cube->mlx->direction == 'S')
		cube->angle = 3 * PI / 2;
	else if (cube->mlx->direction == 'E')
		cube->angle = 0;
	cube->flag = 0;
}

void	ft_start_game(t_game *cube)
{
	cube->mlx->mlx_ptr = mlx_init();
	ft_get_images(cube);
	cube->mlx->win_ptr = mlx_new_window(cube->mlx->mlx_ptr, \
		cube->mlx->width, cube->mlx->height, "CUB3D | FPS: 0");
	cube->mlx->buffer = mlx_new_image(cube->mlx->mlx_ptr, \
		cube->mlx->width, cube->mlx->height);
	cube->mlx->data_addr = mlx_get_data_addr(cube->mlx->buffer, \
		&cube->mlx->bpp, &cube->mlx->size_line, &cube->mlx->endian);
	raycasting_angel(cube);
	mlx_put_image_to_window(cube->mlx->mlx_ptr, cube->mlx->win_ptr, \
		cube->mlx->buffer, 0, 0);
	mlx_key_hook(cube->mlx->win_ptr, khook, cube);
	mlx_loop_hook(cube->mlx->mlx_ptr, lhook, cube);
	mlx_hook(cube->mlx->win_ptr, 17, 1, close_window, cube);
	mlx_loop(cube->mlx->mlx_ptr);
}
