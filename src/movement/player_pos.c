/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanitas <vanitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:54:43 by vanitas           #+#    #+#             */
/*   Updated: 2023/11/18 15:14:18 by vanitas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static int	is_valid_pos_wall_collision(t_data *data, double x, double y)
{
	if (data->i.map[(int)y][(int)x] == '0')
		return (1);
	return (0);
}

static int	is_valid_pos_in_map(t_data *data, double x, double y)
{
	if (x < 0.25 || x >= data->i.map_w - 1.25)
		return (0);
	if (y < 0.25 || y >= data->i.map_h -0.25)
		return (0);
	return (1);
}

static int	is_valid_pos(t_data *data, double x, double y)
{
	if (is_valid_pos_in_map(data, x, y))
		return (1);
	if (is_valid_pos_wall_collision(data, x, y))
		return (1);
	return (0);
}

int	validate_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(data, new_x, data->player.pos_y))
	{
		data->player.pos_x = new_x;
		moved = 1;
	}
	if (is_valid_pos(data, data->player.pos_x, new_y))
	{
		data->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}
