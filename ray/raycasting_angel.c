/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_angel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:54:52 by ngastana          #+#    #+#             */
/*   Updated: 2024/09/19 15:56:25 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

double	normalize_angle(double angle)
{
	while (angle < 0)
		angle += 2 * PI;
	while (angle > 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

void	obt_info(t_game *cube, double ray_angel, int *draw_start, int *draw_end)
{
	int	line_height;

	cube->ray_length *= sin(PI / 2 + ray_angel - cube->angle);
	if (cube->ray_length < 0.5)
		cube->ray_length += 0.1;
	line_height = (int)(cube->mlx->height / cube->ray_length);
	*draw_start = -line_height / 2 + cube->mlx->height / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = line_height / 2 + cube->mlx->height / 2;
	if (*draw_end >= cube->mlx->height)
		*draw_end = cube->mlx->height;
}

void	ft_screen(int ray, int draw_start, int draw_end, t_game *cube)
{
	ft_draw(ray, draw_start, draw_end, cube);
	if (cube->side == 0)
		ft_wall_h(ray, draw_start, draw_end, cube);
	else
		ft_wall_v(ray, draw_start, draw_end, cube);
}

void	raycasting_angel(t_game *cube)
{
	int		ray;
	int		draw_start;
	int		draw_end;
	double	ray_angel;

	ray = 0;
	ray_angel = cube->angle - ((FOV * PI / 180) / 2);
	while (ray < cube->mlx->width)
	{
		cube->side = 1;
		ray_angel = normalize_angle(ray_angel);
		if (get_h(cube, ray_angel) > get_v(cube, ray_angel))
			cube->ray_length = get_v(cube, ray_angel);
		else
		{
			cube->ray_length = get_h(cube, ray_angel);
			cube->side = 0;
		}
		obt_info(cube, ray_angel, &draw_start, &draw_end);
		ray_angel += ((FOV * PI / 180) / cube->mlx->width);
		ft_screen(ray, draw_start, draw_end, cube);
		ray++;
	}
}
