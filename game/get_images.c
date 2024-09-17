/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:35:50 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/17 17:41:34 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_mlx_xpm_file_to_img(void	**ptr, char *dir, t_mlx *mlx)
{
	int	res;

	res = 0;
	*ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, dir, &res, &res);
	if (!*ptr)
		exit(1);
}// free bien

void	ft_get_images(t_game *cube)
{
	ft_mlx_xpm_file_to_img(&cube->mlx->north, cube->north, cube->mlx);
	ft_mlx_xpm_file_to_img(&cube->mlx->south, cube->south, cube->mlx);
	ft_mlx_xpm_file_to_img(&cube->mlx->west, cube->west, cube->mlx);
	ft_mlx_xpm_file_to_img(&cube->mlx->east, cube->east, cube->mlx);
}
