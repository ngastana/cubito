/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:06:39 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/17 16:44:15 by emunoz           ###   ########.fr       */
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
// Pa mas adelante
void	ft_wall(void *img_ptr, int ray, int start, int end, t_game *cube, double x_wall)
{
	char            *pixel;
	char            *pixel2;
	unsigned int    color;
	int             bpp, size_line, endian;
	char            *img_data;
	int             y;
	double			step;
	double          tex_pos;

	img_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	int img_width = 80;
	int img_height = 72;
	int tex_x = (int)(x_wall * img_width);
	tex_pos = 0;
	step = (double)img_height / (end - start);
	for (y = start; y < end; y++)
	{
		pixel = img_data + ((int)tex_pos % img_height * size_line + (tex_x) * (bpp / 8));
		tex_pos += step;
		color = *(unsigned int *)pixel;
		pixel2 = cube->mlx->data_addr + (int)(y * (cube->mlx->size_line) + ray * (cube->mlx->bpp / 8));
		*(unsigned int*)pixel2 = color;
	}
}
