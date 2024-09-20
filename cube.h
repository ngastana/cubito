/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:50:27 by ngastana          #+#    #+#             */
/*   Updated: 2024/09/20 12:39:33 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <time.h>
# include <mlx.h>
# include <stdbool.h>
# include <sys/time.h>  

# define BUFFER_SIZE 42
# define PI 3.14159265358979323846
# define FOV 60 // field of view
# define IMG_WIDTH 64
# define IMG_HEIGHT 64

typedef struct s_mlx
{
	int		width;
	int		height;
	char	direction;
	void	*mlx_ptr;
	void	*win_ptr;
	void	**img_ptr;
	void	*buffer;
	void	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		bpp_t;
	int		size_line_t;
	int		endian_t;
	void	*north;
	void	*south;
	void	*west;
	void	*east;
}				t_mlx;

typedef struct s_game
{
	double	plyr_x;
	double	plyr_y;
	double	angle;
	double	ray_length;
	char	**file;
	char	**map;
	int		map_height;
	int		map_width;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceiling;
	int		flag;
	int		side;
	double	x_wall_v;
	double	y_wall_v;
	double	x_wall_h;
	double	y_wall_h;
	bool	ray_facing_up;
	bool	ray_facing_right;
	t_mlx	*mlx;
}	t_game;

		/* Libft */
		/* LIBFT 00 */
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(const char *s);
void	ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char const *s2);

		/* LIBFT 01 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_strstr(const char *s1, const char *s2);
int		ft_isalpha(int c);
int		ft_isspace(int c);

		/* LIBFT 02 */
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	*ft_memset(void *str, int c, size_t n);

		/* FT_SPLIT */
char	**ft_split(char const *s, char c);

		/* FT_ITOA */
char	*ft_itoa(int n);

		/* FT_CLEAR */
void	ft_free_matrix(char **tab);
void	ft_clear_cub(t_game *cube);
int		close_window(t_game *cube);
void	ft_destroy(t_game *cube);

		/* Get_next_line */
char	*get_next_line(int fd);

		/* Parse Assets */
int		ft_parse_assets(t_game *cube);
char	*ft_clear_textures(char *str);
int		ft_clear_colors(char *color);

		/* Parse Assets */
int		ft_get_args(t_game *cube, int fd);
int		ft_get_after_map(int fd);
int		ft_clean_file(t_game *cube);

		/* Parse Map */
int		ft_valid_close(const char *str);
char	*ft_take_all(char *line);
int		ft_check_map_content(t_game *cube);
int		ft_take_map(t_game *cube);
int		ft_map_max_len(t_game *cube);
int		ft_spaces(char **map);

		/* Start game */
void	init_the_player(t_game *cube);
void	ft_start_game(t_game *cube);
void	ft_get_images(t_game *cube);

		/* Raycasting */
void	raycasting_angel(t_game *cube);
void	ft_draw(int x, int start, int end, t_game *cube);
void	ft_wall_h(int ray, int start, int end, t_game *cube);
void	ft_wall_v(int ray, int start, int end, t_game *cube);
double	get_v(t_game *cube, double ray_angle);
double	get_h(t_game *cube, double ray_angle);
double	normalize_angle(double angle);

		/* Play */
int		khook(int keycode, t_game *cube);
int		lhook(t_game *cube);

#endif
