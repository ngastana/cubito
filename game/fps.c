/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:30:51 by ngastana          #+#    #+#             */
/*   Updated: 2024/09/11 08:20:29 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

double get_current_time()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000.0) + (time.tv_usec / 1000.0);
}

int lhook(t_game *cube)
{
    static double previous_time = 0;
    double current_time;
    double frame_time;
    static int frame_count = 0;
    static double fps_time_accumulator = 0;
    const double frame_time_limit = 1000.0 / 144.0;
    current_time = get_current_time();
    frame_time = current_time - previous_time;
    if (frame_time < frame_time_limit)
    {
        usleep((frame_time_limit - frame_time) * 1000);
        current_time = get_current_time();
        frame_time = current_time - previous_time;
    }
    previous_time = current_time;
    fps_time_accumulator += frame_time;
    frame_count++;
    if (fps_time_accumulator >= 1000.0)
    {
        int fps = frame_count / (fps_time_accumulator / 1000.0);
        cube->flag = fps;
        fps_time_accumulator = 0;
        frame_count = 0;
    }
    char *str = ft_strdup("CUB3D | FPS: ");
    char *num = ft_itoa(cube->flag);
    char *full_title = ft_strjoin(str, num);
    mlx_change_window_title(cube->mlx->mlx_ptr, cube->mlx->win_ptr, full_title);
    free(num);
    free(full_title);
    return (0);
}
