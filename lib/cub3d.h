/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:34:06 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/29 13:14:43 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <math.h>
# include <X11/Xlib.h>

# define ERR_MLX_IMG "Could not create mlx image"
# define ERR_MLX_START "Could not start mlx"
# define ERR_MLX_WIN "Could not create mlx window"

# define ERR_TEX_MISSING "Missing texture(s)"
# define ERR_COLOR_MISSING "Missing color(s)"

# define ERR_MALLOC "Allocation error"

# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define TEX_SIZE 64

# define MOVESPEED 0.0125
# define ROTSPEED 0.015

# ifndef BONUS
#  define BONUS 0
# endif

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_info
{
	char			**map;
	char			**island;
	int				map_line;
	int				index;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	double			step;
	char			*floor;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	double			pos;
	int				size;
	unsigned int	r_floor;
	unsigned int	g_floor;
	unsigned int	b_floor;
	char			*ciel;
	unsigned int	r_ciel;
	unsigned int	g_ciel;
	unsigned int	b_ciel;
	int				map_w;
	int				map_h;
	int				x;
	int				y;
}			t_info;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}			t_ray;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}			t_player;

typedef struct s_img
{
	void	*img_ptr;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	char		**config;
	int			**textures;
	int			**texture_pixels;
	int			height;
	int			width;
	int			done;
	t_info		i;
	t_ray		ray;
	t_player	player;
	t_img		img;
}				t_data;

/*Init*/
void	init_struct(t_data *data);
void	init_data(t_data *data);
void	init_textures(t_data *data);
void	init_ray(t_ray *ray);
void	init_mlx(t_data *data);
void	init_img_clean(t_img *img);
void	init_texture_img(t_data *data, t_img *image, char *path);
void	init_img(t_data *data, t_img *image, int width, int height);
void	init_texture_pixels(t_data *data);
void	init_player_direction(t_data *data);
void	set_image_pixel(t_img *image, int x, int y, int color);

/*Parsing*/
void	get_info(t_data *data, char *path);
void	get_texture2(t_data *data, char *cpy);
void	ft_safe_trim(t_data *data, char **str, char *charset);
char	*ft_safe_dup(t_data *data, char *todup);
char	*ft_safe_dup_init(t_data *data, char *todup);
void	print_var(t_data *data);
int		only_blank(char *str);
void	parse_map(t_data *data);
char	last_occur(char *str);
char	first_occur(char *str);
void	island(t_data *data);
int		longest_str(char *str);
void	parse_info(t_data *data);

/*Render*/
int		raycasting(t_player *player, t_data *data);
void	render_images(t_data *data);
int		render(t_data *data);
int		check_put_textures(t_info *i);

/*Inputs*/
int		move_player(t_data *data);
int		validate_move(t_data *data, double new_x, double new_y);
int		rotate_player(t_data *data, double rotdir);
void	update_texture_pixels(t_data *data, t_info *i, t_ray *ray, int x);
void	listen_for_input(t_data *data);

/*Exit*/
void	clean_exit(t_data *data, int code);
int		err_msg(char *str);
int		quit_cub3d(t_data *data);
int		end(t_data *data);
void	end_norm(t_data *data);

/*Utils*/
int		ft_abs(int nbr);
int		isdigitstr(char *str);
void	datalog(t_data *data);
void	free_tab(void **tab);
int		open_door(char *a);
int		close_door(char *a);
int		explosion(char *a);
void	error_alloc(t_data *data);
void	error_map(t_data *data);

#endif