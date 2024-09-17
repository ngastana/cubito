/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:35:50 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/17 17:53:21 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_mlx_xpm_file_to_img(void	**ptr, char *dir, t_game *cube)
{
	static int	i;
	int			res;

	res = 0;
	*ptr = mlx_xpm_file_to_image(cube->mlx->mlx_ptr, dir, &res, &res);
	if (!*ptr)
	{
		if (i == 0)
			ft_destroy(cube);
		if (i == 1)
		{
			mlx_destroy_image(cube->mlx->mlx_ptr, cube->mlx->north);
			ft_destroy(cube);
		}
		if (i == 2)
		{
			mlx_destroy_image(cube->mlx->mlx_ptr, cube->mlx->north);
			mlx_destroy_image(cube->mlx->mlx_ptr, cube->mlx->south);
			ft_destroy(cube);
		}
		if (i == 3)
		{
			mlx_destroy_image(cube->mlx->mlx_ptr, cube->mlx->north);
			mlx_destroy_image(cube->mlx->mlx_ptr, cube->mlx->south);
			mlx_destroy_image(cube->mlx->mlx_ptr, cube->mlx->south);
			ft_destroy(cube);
		}
	}
	i++;
}

void	ft_get_images(t_game *cube)
{
	ft_mlx_xpm_file_to_img(&cube->mlx->north, cube->north, cube);
	ft_mlx_xpm_file_to_img(&cube->mlx->south, cube->south, cube);
	ft_mlx_xpm_file_to_img(&cube->mlx->west, cube->west, cube);
	ft_mlx_xpm_file_to_img(&cube->mlx->east, cube->east, cube);
}
