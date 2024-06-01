/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:25:26 by vanitas           #+#    #+#             */
/*   Updated: 2023/12/19 17:51:43 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	init_img(t_data *data, t_img *image, int width, int height)
{
	init_img_clean(image);
	image->img_ptr = mlx_new_image(data->mlx_ptr, width, height);
	if (image->img_ptr == NULL)
		clean_exit(data, err_msg(ERR_MLX_IMG));
	image->addr = (int *)mlx_get_data_addr(image->img_ptr,
			&image->bits_per_pixel, &image->line_length, &image->endian);
	return ;
}

void	init_texture_img(t_data *data, t_img *image, char *path)
{
	init_img_clean(image);
	image->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->i.size,
			&data->i.size);
	if (image->img_ptr == NULL)
		clean_exit(data, err_msg(ERR_MLX_IMG));
	image->addr = (int *)mlx_get_data_addr(image->img_ptr,
			&image->bits_per_pixel, &image->line_length, &image->endian);
	return ;
}

void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		clean_exit(data, err_msg(ERR_MLX_START));
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->mlx_win)
		clean_exit(data, err_msg(ERR_MLX_WIN));
	return ;
}
