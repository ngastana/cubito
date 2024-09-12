/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:35:50 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/12 18:37:39 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_mlx_xpm_file_to_img(void	**ptr, char *dir, t_mlx *mlx)
{
	int	res;

	res = 1;
	*ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, dir, &res, &res);
    if (!*ptr)
        exit(1);
}

void    ft_get_images(t_game *cube)
{    
    ft_mlx_xpm_file_to_img(&cube->mlx->north, cube->north, cube->mlx);
    ft_mlx_xpm_file_to_img(&cube->mlx->south, cube->south, cube->mlx);
    ft_mlx_xpm_file_to_img(&cube->mlx->west, cube->west, cube->mlx);
    ft_mlx_xpm_file_to_img(&cube->mlx->east, cube->east, cube->mlx);
}