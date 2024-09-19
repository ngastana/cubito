/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:06:39 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/19 21:32:59 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_pixel_put(int x, int y, int color, t_game *cube)
{
	char	*pixel;

	pixel = cube->mlx->data_addr + (y * cube->mlx->size_line) + \
		(x * (cube->mlx->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	ft_draw(int x, int start, int end, t_game *cube)
{
	int	y;

	y = -1;
	while (++y < start)
		ft_pixel_put(x, y, cube->ceiling, cube);
	while (end < cube->mlx->height)
	{
		ft_pixel_put(x, end, cube->floor, cube);
		end++;
	}
}

void	ft_wall_h(int ray, int start, int end, t_game *cube)
{
	unsigned int	color;
	char			*img_data;
	double			step;
	double			tex_pos;
	float			j;

	if (cube->ray_facing_up)
		img_data = mlx_get_data_addr(cube->mlx->north, &cube->mlx->bpp_t, \
		&cube->mlx->size_line_t, &cube->mlx->endian_t);
	else
		img_data = mlx_get_data_addr(cube->mlx->south, &cube->mlx->bpp_t, \
		&cube->mlx->size_line_t, &cube->mlx->endian_t);
	tex_pos = 0;
	step = (double)IMG_HEIGHT / (end - start);
	cube->x_wall_h = fmod(cube->x_wall_h, 1.0);
	while ((++start -1) < end)
	{
		j = (int)tex_pos % IMG_HEIGHT;
		if (cube->ray_length < 1)
			j = (int)(tex_pos * cube->ray_length) % IMG_HEIGHT;
		color = *(unsigned int *)(img_data + ((int) j * cube->mlx->size_line_t \
		+ ((int)(cube->x_wall_h * IMG_WIDTH)) * (cube->mlx->bpp_t / 8))); 
		tex_pos += step;
		ft_pixel_put(ray, start - 1, color, cube);
	}
}

void	ft_wall_v(int ray, int start, int end, t_game *cube)
{
	unsigned int	color;
	char			*img_data;
	double			step;
	double			tex_pos;
	float			j;

	if (cube->ray_facing_right)
		img_data = mlx_get_data_addr(cube->mlx->west, &cube->mlx->bpp_t, \
		&cube->mlx->size_line_t, &cube->mlx->endian_t);
	else
		img_data = mlx_get_data_addr(cube->mlx->east, &cube->mlx->bpp_t, \
		&cube->mlx->size_line_t, &cube->mlx->endian_t);
	tex_pos = 0;
	step = (double)IMG_HEIGHT / (end - start);
	cube->x_wall_v = fmod(cube->x_wall_v, 1.0);
	while ((++start - 1) < end)
	{
		j = (int)tex_pos % IMG_HEIGHT;
		if (cube->ray_length < 1)
			j = (int)(tex_pos * cube->ray_length) % IMG_HEIGHT;
		color = *(unsigned int *)(img_data + ((int)j  * cube->mlx->size_line_t \
		+ ((int)(cube->y_wall_v * IMG_WIDTH)) * (cube->mlx->bpp_t / 8)));
		tex_pos += step;
		ft_pixel_put(ray, start - 1, color, cube);
	}
}
