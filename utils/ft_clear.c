/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:19:41 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/12 18:28:20 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_free_matrix(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void ft_clear_cub(t_game *cube)
{
	ft_free_matrix(cube->map);
	free(cube->mlx);
	free(cube->north);
	free(cube->south);
	free(cube->west);
	free(cube->east);
	free(cube->file);
}

void ft_print_map(char **map)
{
	int i =0;
	while (map[i])			
		printf ("%s\n", map[i++]);
}

void	ft_destroy_imgs(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->north);
	mlx_destroy_image(mlx->mlx_ptr, mlx->south);
	mlx_destroy_image(mlx->mlx_ptr, mlx->west);
	mlx_destroy_image(mlx->mlx_ptr, mlx->east);
}

int	close_window(t_game *cube)
{
	ft_destroy_imgs(cube->mlx);
	mlx_loop_end(cube->mlx->win_ptr);
	mlx_destroy_image(cube->mlx->mlx_ptr, cube->mlx->buffer);
    mlx_destroy_window(cube->mlx->mlx_ptr, cube->mlx->win_ptr);
	mlx_destroy_display(cube->mlx->mlx_ptr),
	mlx_loop_end(cube->mlx->mlx_ptr);
	free(cube->mlx->mlx_ptr);
    ft_clear_cub(cube);
    exit(0);
}