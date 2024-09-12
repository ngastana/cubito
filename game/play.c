/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:58:45 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/12 17:15:58 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int khook(int keycode, t_game *cube)
{
	double moveSpeed = 0.1;
	double rotSpeed = 0.1;

	cube->angle = normalize_angle(cube->angle);
	if (keycode == 65307)  // ESC key
		close_window(cube);
	else if ((keycode == 65364 && ((cube->angle > PI/4 && cube->angle < 3*PI/4) || (cube->angle > 5*PI/4 && cube->angle < 7*PI/4))) || (keycode == 65362 && !((cube->angle > PI/4 && cube->angle < 3*PI/4) || (cube->angle > 5*PI/4 && cube->angle < 7*PI/4)))) // Flecha arriba (mover adelante)
	{
		if (cube->map[(int)(cube->plyr_y - sin(cube->angle)* moveSpeed)][(int)(cube->plyr_x + cos(cube->angle)* moveSpeed)] == '0')
		{
			cube->plyr_x += cos(cube->angle)* moveSpeed;
			cube->plyr_y -= sin(cube->angle)* moveSpeed;
		}
	}
	else if ((keycode == 65362 && ((cube->angle > PI/4 && cube->angle < 3*PI/4) || (cube->angle > 5*PI/4 && cube->angle < 7*PI/4))) ||  (keycode == 65364 && !((cube->angle > PI/4 && cube->angle < 3*PI/4) || (cube->angle > 5*PI/4 && cube->angle < 7*PI/4)))) // Flecha abajo (mover atrás)
	{
		if (cube->map[(int)(cube->plyr_y + sin(cube->angle)* moveSpeed)][(int)(cube->plyr_x - cos(cube->angle)* moveSpeed)] == '0')
		{ 
			cube->plyr_x -= cos(cube->angle)* moveSpeed;
			cube->plyr_y += sin(cube->angle)* moveSpeed;
		}
	}
	else if (keycode == 65363) //mover derecha
	{
		if (cube->map[(int)(cube->plyr_y + cos(cube->angle)* moveSpeed)][(int)(cube->plyr_x - sin(cube->angle)* moveSpeed)] == '0')
		{
			cube->plyr_x -= sin(cube->angle)* moveSpeed;
			cube->plyr_y += cos(cube->angle)* moveSpeed;
		}
	}
	else if (keycode == 65361) //mover izquierda
	{
		if (cube->map[(int)(cube->plyr_y - cos(cube->angle)* moveSpeed)][(int)(cube->plyr_x + sin(cube->angle)* moveSpeed)] == '0')
		{
			cube->plyr_x += sin(cube->angle)* moveSpeed;
			cube->plyr_y -= cos(cube->angle)* moveSpeed;
		}
	}
	else if (keycode == 97)
		cube->angle -= rotSpeed;
	else if (keycode == 100)
		cube->angle += rotSpeed;
	memset(cube->mlx->data_addr, 0, cube->mlx->height * cube->mlx->size_line);
	raycasting_angel(cube);
	mlx_put_image_to_window(cube->mlx->mlx_ptr, cube->mlx->win_ptr, cube->mlx->buffer, 0, 0);
	return (0);
}