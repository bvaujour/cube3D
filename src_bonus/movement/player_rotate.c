/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:05:16 by vanitas           #+#    #+#             */
/*   Updated: 2023/12/19 17:47:03 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

static int	rotate_left_right(t_data *data, double rotspeed)
{
	t_player	*p;
	double		tmp_x;

	p = &data->player;
	tmp_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rotspeed) - p->dir_y * sin(rotspeed);
	p->dir_y = tmp_x * sin(rotspeed) + p->dir_y * cos(rotspeed);
	tmp_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rotspeed) - p->plane_y * sin(rotspeed);
	p->plane_y = tmp_x * sin(rotspeed) + p->plane_y * cos(rotspeed);
	return (1);
}

int	rotate_player(t_data *data, double rotdir)
{
	int		moved;
	double	rotspeed;

	moved = 0;
	rotspeed = ROTSPEED * rotdir;
	moved += rotate_left_right(data, rotspeed);
	return (moved);
}

void	mouse_rotate(t_data *data)
{
	static int	x_saved = 0;
	int			limit;

	limit = data->width / 100;
	if (data->mouse.x != x_saved)
	{
		data->player.rotate = data->mouse.x - x_saved;
		if (data->player.rotate > limit)
			data->player.rotate = limit;
		else if (data->player.rotate < -limit)
			data->player.rotate = -limit;
	}
	else
		data->player.rotate = 0;
	x_saved = data->mouse.x;
	if (data->mouse.x != data->width / 2 || data->mouse.y != data->height / 2)
	{
		mlx_mouse_move(data->mlx_ptr, data->mlx_win,
			data->width / 2, data->height / 2);
		x_saved = data->width / 2;
	}
}
