/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanitas <vanitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:51:57 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/08 15:52:13 by vanitas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	loading(t_data *data, t_img *load, int percent)
{
	int	x;
	int	y;

	y = 1.5 * load->height / 4;
	while (y < 3 * load->height / 4)
	{
		x = 0;
		while (++x < (load->width * percent) / 100)
			set_image_pixel(load, x, y, 0xFFFFFF);
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, load->img_ptr,
		0, data->height - load->height);
}
