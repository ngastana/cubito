/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_angel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:54:52 by ngastana          #+#    #+#             */
/*   Updated: 2024/09/13 13:46:28 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void ft_draw(int x, int start, int end, int color, t_game *cube)
{
	char *pixel;
	
    while (start < end)
    {
        pixel = cube->mlx->data_addr + (start * cube->mlx->size_line) + (x * (cube->mlx->bpp / 8));
        *(unsigned int*)pixel = color;
        start++;
    }
}

void ft_wall(void *img_ptr, int ray, int start, int end, t_game *cube)
{
    char            *pixel;
    char            *pixel2;
    unsigned int    color;
    int             bpp, size_line, endian;
    char            *img_data;
    int             y;
    int             tex_y;
    double          step;
    double          tex_pos;

    img_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
    int img_width = 55;
    int img_height = 55;
	step = (double)img_height / (end - start);
    tex_pos = 0;

    for (y = start; y < end; y++)
    {
  		tex_y = (int)tex_pos & (img_height);
        tex_pos += step;
        pixel = img_data + (tex_y * size_line + (ray % img_width) * (bpp / 8));
        color = *(unsigned int *)pixel;
        pixel2 = cube->mlx->data_addr + (y * cube->mlx->size_line + ray * (cube->mlx->bpp / 8));
        *(unsigned int*)pixel2 = color;
    }
}

double normalize_angle(double angle)
{
	while (angle < 0)
		angle += 2 * PI;
	while (angle > 2 * PI)
		angle -= 2 * PI;
	return angle;
}

void raycasting_angel(t_game *cube)
{
	double 	side_v;
	double 	side_h;
	int 	ray;
    int 	side;
    int 	draw_start;
    int 	draw_end;
	double ray_angle;

	ray = 0;
	ray_angle = cube->angle - ((FOV * PI / 180) / 2);
	while (ray < cube->mlx->width)
	{
		side = 1;
		side_v = get_v(cube, ray_angle);
		side_h = get_h(cube, ray_angle);
		ray_angle = normalize_angle(ray_angle);
		if (side_h > side_v)
			cube->ray_length = side_v;
		else
		{
			cube->ray_length = side_h;
			side = 0;
		}
		cube->ray_length = cube->ray_length * sin(PI/2 + ray_angle - cube->angle);
		if (cube->ray_length < 0.1)
			cube->ray_length += 0.1;
		int lineHeight = (int)(cube->mlx->height / cube->ray_length);
		draw_start = -lineHeight / 2 + cube->mlx->height / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = lineHeight / 2 + cube->mlx->height / 2;
		if (draw_end >= cube->mlx->height)
			draw_end = cube->mlx->height;
		ray_angle += ((FOV * PI / 180)/ cube->mlx->width);
		int color = 0xFF0000;
		if (side == 1) color /= 2;
		ft_draw(ray, 0, draw_start, cube->ceiling, cube);
		if (side == 0)
			ft_wall(cube->mlx->north, ray, draw_start, draw_end, cube);
		else 
			ft_wall(cube->mlx->west, ray, draw_start, draw_end, cube);			
		ft_draw(ray, draw_end, cube->mlx->height, cube->floor, cube);
		ray++;
	}
}
