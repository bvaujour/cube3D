/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:25:26 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/29 14:00:00 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	init_img(t_data *data, t_img *image, int width, int height)
{
	init_img_clean(image);
	image->img_ptr = mlx_new_image(data->mlx_ptr, width, height);
	if (!image->img_ptr)
		clean_exit(data, 1);
	image->width = width;
	image->height = height;
	if (image->img_ptr == NULL)
		clean_exit(data, err_msg(ERR_MLX_IMG));
	image->addr = (int *)mlx_get_data_addr(image->img_ptr,
			&image->bits_per_pixel, &image->line_length, &image->endian);
	return ;
}

void	init_time_s_out(t_data *data)
{
	data->time_out[0] = new_img(data, data->width, data->height,
			"textures/timeout/explo_0.xpm");
	data->time_out[1] = new_img(data, data->width, data->height,
			"textures/timeout/explo_1.xpm");
	data->time_out[2] = new_img(data, data->width, data->height,
			"textures/timeout/explo_2.xpm");
	data->time_out[3] = new_img(data, data->width, data->height,
			"textures/timeout/explo_3.xpm");
	data->time_out[4] = new_img(data, data->width, data->height,
			"textures/timeout/explo_4.xpm");
	data->time_out[5] = new_img(data, data->width, data->height,
			"textures/timeout/explo_5.xpm");
	data->time_out[6] = new_img(data, data->width, data->height,
			"textures/timeout/explo_6.xpm");
	data->time_out[7] = new_img(data, data->width, data->height,
			"textures/timeout/explo_7.xpm");
	data->time_out[8] = new_img(data, data->width, data->height,
			"textures/timeout/explo_8.xpm");
	data->time_out[9] = new_img(data, data->width, data->height,
			"textures/timeout/explo_9.xpm");
}

void	init_mlx(t_data *data)
{
	t_img	title;

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		clean_exit(data, err_msg(ERR_MLX_START));
	mlx_get_screen_size(data->mlx_ptr, &data->width, &data->height);
	data->height -= 100;
	title = new_img(data, data->width, data->height, "textures/title.xpm");
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			data->width, data->height, "Cub3D");
	if (!data->mlx_win)
		clean_exit(data, err_msg(ERR_MLX_START));
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, title.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, title.img_ptr);
	if (!data->mlx_win)
		clean_exit(data, err_msg(ERR_MLX_WIN));
	data->wall_dist = malloc(sizeof(double) * data->width);
	if (!data->wall_dist)
		(ft_dprintf(2, "Error, allocation\n"), end(data));
	data->test = 1.0;
}
