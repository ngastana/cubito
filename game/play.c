/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:58:45 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/19 21:43:07 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	move_up_down(t_game *cube, int keycode)
{
	double	move_speed;
	double	new_x;
	double	new_y;

	move_speed = 0.1;
	new_x = 0;
	new_y = 0;
	if (keycode == 119)
	{
		new_x = cube->plyr_x + cos(cube->angle) * move_speed;
		new_y = cube->plyr_y + sin(cube->angle) * move_speed;
	}
	else if (keycode == 115)
	{
		new_x = cube->plyr_x - cos(cube->angle) * move_speed;
		new_y = cube->plyr_y - sin(cube->angle) * move_speed;
	}
	else
		return (0);
	if (cube->map[(int)(new_y)][(int)cube->plyr_x] == '0')
		cube->plyr_y = new_y;
	if (cube->map[(int)cube->plyr_y][(int)(new_x)] == '0')
		cube->plyr_x = new_x;
	return (1);
}

int	move_right_left(t_game *cube, int keycode)
{
	double	move_speed;
	double	new_x;
	double	new_y;

	move_speed = 0.1;
	new_x = 0;
	new_y = 0;
	if (keycode == 100)
	{
		new_x = cube->plyr_x - sin(cube->angle) * move_speed;
		new_y = cube->plyr_y + cos(cube->angle) * move_speed;
	}
	else if (keycode == 97)
	{
		new_x = cube->plyr_x + sin(cube->angle) * move_speed;
		new_y = cube->plyr_y - cos(cube->angle) * move_speed;
	}
	else
		return (0);
	if (cube->map[(int)new_y][(int)cube->plyr_x] == '0')
		cube->plyr_y = new_y;
	if (cube->map[(int)cube->plyr_y][(int)new_x] == '0')
		cube->plyr_x = new_x;
	return (1);
}

int	khook(int keycode, t_game *cube)
{
	cube->angle = normalize_angle(cube->angle);
	if (keycode == 65307)
		close_window(cube);
	else if (keycode == 65361)
		cube->angle -= 0.1;
	else if (keycode == 65363)
		cube->angle += 0.1;
	else if (move_up_down(cube, keycode) == 0)
		move_right_left(cube, keycode);
	memset(cube->mlx->data_addr, 0, cube->mlx->height * cube->mlx->size_line);
	raycasting_angel(cube);
	mlx_put_image_to_window(cube->mlx->mlx_ptr, cube->mlx->win_ptr, \
	cube->mlx->buffer, 0, 0);
	mlx_do_sync(cube->mlx->mlx_ptr);
	return (0);
}
