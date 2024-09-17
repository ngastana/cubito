/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:58:45 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/17 17:02:02 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	move_up_down(t_game *cube, int keycode)
{
	double	move_speed;

	move_speed = 0.1;
	if (keycode == 65362)
	{
		if (cube->map[(int)(cube->plyr_y + sin(cube->angle) * move_speed)] \
		[(int)(cube->plyr_x + cos(cube->angle) * move_speed)] == '0')
		{
			cube->plyr_x += cos(cube->angle) * move_speed;
			cube->plyr_y += sin(cube->angle) * move_speed;
		}
		return (1);
	}
	else if (keycode == 65364)
	{
		if (cube->map[(int)(cube->plyr_y - sin(cube->angle) * move_speed)] \
		[(int)(cube->plyr_x - cos(cube->angle) * move_speed)] == '0')
		{
			cube->plyr_x -= cos(cube->angle) * move_speed;
			cube->plyr_y -= sin(cube->angle) * move_speed;
		}
		return (1);
	}
	return (0);
}

int	move_right_left(t_game *cube, int keycode)
{
	double	move_speed;

	move_speed = 0.1;
	if (keycode == 65363)
	{
		if (cube->map[(int)(cube->plyr_y + cos(cube->angle) * move_speed)] \
		[(int)(cube->plyr_x - sin(cube->angle) * move_speed)] == '0')
		{
			cube->plyr_x -= sin(cube->angle) * move_speed;
			cube->plyr_y += cos(cube->angle) * move_speed;
		}
		return (1);
	}
	else if (keycode == 65361)
	{
		if (cube->map[(int)(cube->plyr_y - cos(cube->angle) * move_speed)] \
		[(int)(cube->plyr_x + sin(cube->angle) * move_speed)] == '0')
		{
			cube->plyr_x += sin(cube->angle) * move_speed;
			cube->plyr_y -= cos(cube->angle) * move_speed;
		}
		return (1);
	}
	return (0);
}

int	khook(int keycode, t_game *cube)
{
	cube->angle = normalize_angle(cube->angle);
	if (keycode == 65307)
		close_window(cube);
	else if (keycode == 97)
		cube->angle -= 0.1;
	else if (keycode == 100)
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
