/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_bonus2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:40:12 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/24 12:55:19 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

int	key_release_handler(int key, t_data *data)
{
	if ((key == XK_w || key == XK_Up) && data->player.move_y == 1)
		data->player.move_y = 0;
	if ((key == XK_s || key == XK_Down) && data->player.move_y == -1)
		data->player.move_y = 0;
	if (key == XK_a && data->player.move_x == -1)
		data->player.move_x += 1;
	if (key == XK_d && data->player.move_x == 1)
		data->player.move_x -= 1;
	if (key == XK_Left && data->player.rotate <= 3)
		data->player.rotate = 0;
	if (key == XK_Right && data->player.rotate >= -3)
		data->player.rotate = 0;
	if (key == XK_Shift_L && data->player.stats.sprint)
	{
		data->player.stats.sprint = 0;
		data->player.stats.ms /= 2.5;
	}
	return (0);
}

void	handle_mouse_bis_2(t_data *data)
{
	if (data->i.map[(int)(data->player.pos_y + data->player.dir_y)]
		[(int)(data->player.pos_x + data->player.dir_x)] == 'D')
	{
		open_door(data, &data->i.map[(int)(data->player.pos_y
				+ data->player.dir_y)][(int)(data->player.pos_x
				+ data->player.dir_x)]);
		data->i.mapcopy[(int)(data->player.pos_y
				+ data->player.dir_y)][(int)(data->player.pos_x
				+ data->player.dir_x)] = 'H';
	}
	else if (data->i.map[(int)(data->player.pos_y + data->player.dir_y)]
		[(int)(data->player.pos_x + data->player.dir_x)] == 'H')
	{
		close_door(data, &data->i.map[(int)(data->player.pos_y
				+ data->player.dir_y)][(int)(data->player.pos_x
				+ data->player.dir_x)]);
		data->i.mapcopy[(int)(data->player.pos_y
				+ data->player.dir_y)][(int)(data->player.pos_x
				+ data->player.dir_x)] = 'D';
	}
}

void	key_press_handler_bis_2(int key, t_data *data)
{
	if (key == XK_Delete)
	{
		if (data->lockcursor)
			data->lockcursor = 0;
		else
			data->lockcursor = 1;
	}
	else if (key == XK_Shift_L && !data->player.stats.sprint)
	{
		data->player.stats.sprint = 1;
		data->player.stats.ms *= 2.5;
	}
}
