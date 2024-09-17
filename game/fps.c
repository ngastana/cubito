/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:30:51 by ngastana          #+#    #+#             */
/*   Updated: 2024/09/17 17:00:11 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

double	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000.0) + (time.tv_usec / 1000.0));
}

double	handle_frame_time(double *time, int *f_count, double *fps)
{
	double	current_time;
	double	frame_time;
	double	frame_time_limit;

	frame_time_limit = 1000.0 / 144.0;
	current_time = get_current_time();
	frame_time = current_time - *time;
	if (frame_time < frame_time_limit)
	{
		usleep((frame_time_limit - frame_time) * 1000);
		current_time = get_current_time();
		frame_time = current_time - *time;
	}
	*time = current_time;
	*fps += frame_time;
	(*f_count)++;
	return (frame_time);
}

void	update_window_title(t_game *cube, int *frame_count, double *fps_acu)
{
	char	*str;
	char	*num;
	char	*full_title;
	int		fps;

	if (*fps_acu >= 1000.0)
	{
		fps = *frame_count / (*fps_acu / 1000.0);
		cube->flag = fps;
		*fps_acu = 0;
		*frame_count = 0;
	}
	str = ft_strdup("CUB3D | FPS: ");
	num = ft_itoa(cube->flag);
	full_title = ft_strjoin(str, num);
	mlx_change_window_title(cube->mlx->mlx_ptr, cube->mlx->win_ptr, full_title);
	free(num);
	free(full_title);
}

int	lhook(t_game *cube)
{
	static double	previous_time;
	static int		frame_count;
	static double	fps_time_accumulator;

	handle_frame_time(&previous_time, &frame_count, &fps_time_accumulator);
	update_window_title(cube, &frame_count, &fps_time_accumulator);
	return (0);
}
