/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:21:34 by ngastana          #+#    #+#             */
/*   Updated: 2024/09/17 13:56:28 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

bool is_wall(int x_wall, int y_wall, t_game cube)
{
	if (x_wall < 0 || y_wall < 0 || y_wall > cube.map_height || x_wall > cube.map_width)
		return (true);
	if (cube.map[y_wall][x_wall] == '1')
		return (true);
	else
		return (false);
}

double get_v(t_game *cube, double ray_angle)
{
	float	x_step;
	float	y_step;
	bool	ray_facing_right;
	int		sum_h;

	x_step = 1;
	sum_h = 1;
	ray_angle = normalize_angle(ray_angle);
	ray_facing_right = ray_angle < PI / 2 || ray_angle > 3 * PI / 2;
	if (ray_facing_right)
	{
		cube->x_wall_v = floor(cube->plyr_x) + 1;
		sum_h = 0;
	}
	else
	{
		cube->x_wall_v = floor(cube->plyr_x);
		x_step = -1;
	}
	cube->y_wall_v = cube->plyr_y + (cube->x_wall_v - cube->plyr_x) * tan(ray_angle);
	y_step = x_step * tan(ray_angle);
	if (cube->x_wall_v >= cube->map_width || cube->x_wall_v < 0 || cube->y_wall_v >= cube->map_height || cube->y_wall_v < 0)
		return 1000000;
	while (!is_wall((int)(cube->x_wall_v - sum_h), (int)(cube->y_wall_v), *cube))
	{
		cube->x_wall_v += x_step;
		cube->y_wall_v += y_step;
		if (cube->x_wall_v >= cube->map_width || cube->x_wall_v < 0 ||
			cube->y_wall_v >= cube->map_height || cube->y_wall_v < 0)
			return 1000000;
	}
	return (sqrt(pow(cube->x_wall_v - cube->plyr_x, 2) + pow(cube->y_wall_v - cube->plyr_y, 2)));
}

double get_h(t_game *cube, double ray_angle)
{
	float	x_step;
	float	y_step;
	bool	ray_facing_up;
	int		sum_h;
	
	y_step = 1;
	sum_h = 1;
	ray_angle = normalize_angle(ray_angle);
	ray_facing_up = ray_angle > 0 && ray_angle < PI;
	if (ray_facing_up)
	{
		cube->y_wall_h = floor(cube->plyr_y) + 1;
		sum_h = 0;
	}
	else
	{
		cube->y_wall_h = floor(cube->plyr_y);
		y_step = -1;
	}
	cube->x_wall_h = cube->plyr_x + (cube->y_wall_h - cube->plyr_y) / tan(ray_angle);
	if (cube->x_wall_h >= cube->map_width || cube->x_wall_h < 0 || cube->y_wall_h >= cube->map_height || cube->y_wall_h < 0)
		return 1000000;
	x_step = y_step / tan(ray_angle);
	while (!is_wall((int)cube->x_wall_h, (int)(cube->y_wall_h - sum_h), *cube))
	{
		cube->x_wall_h += x_step;
		cube->y_wall_h += y_step;
		if (cube->x_wall_h >= cube->map_width || cube->x_wall_h < 0 || cube->y_wall_h >= cube->map_height || cube->y_wall_h < 0)
			return 1000000;
	}
	return (sqrt(pow(cube->x_wall_h - cube->plyr_x, 2) + pow(cube->y_wall_h - cube->plyr_y, 2)));
}
