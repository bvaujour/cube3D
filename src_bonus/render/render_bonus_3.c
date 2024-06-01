/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:08:08 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/17 16:33:40 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"
#include "../../lib/test.h"

void	menu_norm(t_data *data, int *i)
{
	if (data->mouse.y > data->height / 2 - data->anim.start.height
		* 1.3 && data->mouse.y < data->height / 2 - data->anim.start.height
		* 1.3 + data->anim.start.height && data->mouse.x > data->width / 2
		- data->anim.start.width && data->mouse.x < data->width / 2)
		refresh(data, *i, 1);
	else if (data->mouse.y > data->height / 2 + data->height / 9
		- data->anim.start.height * 1.3 && data->mouse.y < data->height
		/ 2 + data->height / 9 - data->anim.start.height * 1.3
		+ data->anim.settings.height && data->mouse.x > data->width / 2
		- data->anim.start.width && data->mouse.x < data->width / 2
		- data->anim.start.width + data->anim.settings.width)
		refresh(data, *i, 2);
	else if (data->mouse.y > data->height / 2 + 2 * data->height / 9
		- data->anim.start.height * 1.3 && data->mouse.y < data->height
		/ 2 + 2 * data->height / 9 - data->anim.start.height * 1.3
		+ data->anim.exit.height && data->mouse.x > data->width / 2
		- data->anim.start.width && data->mouse.x < data->width / 2
		- data->anim.start.width + data->anim.exit.width)
		refresh(data, *i, 3);
	else
		refresh(data, *i, 0);
}

void	refresh_norm(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->anim.start.img_ptr, data->width / 2
		- data->anim.start.width, data->height / 2
		- data->anim.start.height * 1.3);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->anim.settings.img_ptr, data->width / 2
		- data->anim.start.width, data->height / 2
		+ data->height / 9 - data->anim.start.height * 1.3);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->anim.exit.img_ptr, data->width / 2
		- data->anim.start.width, data->height / 2
		+ 2 * data->height / 9 - data->anim.start.height * 1.3);
	mlx_put_image_to_window(data->mlx_ptr,
		data->mlx_win, data->anim.cube.img_ptr,
		data->anim.cube_pos_x, data->anim.cube_pos_y);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->anim.exc.img_ptr, data->width / 2
		+ data->anim.cube.width / 2
		+ data->anim.exc.width / 1.4, data->anim.cube_pos_y);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->anim.blank.img_ptr, data->width / 2
		- data->anim.start.width - data->anim.idler[0].width,
		data->anim.pos_y);
}

void	time_s_out(t_data *data)
{
	static time_t	time = 0;
	static int		i = -1;

	if (i >= 9)
		return ;
	if (get_time() - time > 70)
	{
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		time = get_time();
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->time_out[i].img_ptr, 0, 0);
}
