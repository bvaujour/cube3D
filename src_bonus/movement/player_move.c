/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:11:24 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/18 13:15:30 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

static int	move_player_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_x * data->player.stats.ms;
	new_y = data->player.pos_y + data->player.dir_y * data->player.stats.ms;
	return (validate_move(data, new_x, new_y));
}

static int	move_player_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_x * data->player.stats.ms;
	new_y = data->player.pos_y - data->player.dir_y * data->player.stats.ms;
	return (validate_move(data, new_x, new_y));
}

static int	move_player_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_y * data->player.stats.ms;
	new_y = data->player.pos_y - data->player.dir_x * data->player.stats.ms;
	return (validate_move(data, new_x, new_y));
}

static int	move_player_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_y * data->player.stats.ms;
	new_y = data->player.pos_y + data->player.dir_x * data->player.stats.ms;
	return (validate_move(data, new_x, new_y));
}

int	move_player(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player.move_y == 1 && data->win == false)
		moved += move_player_forward(data);
	if (data->player.move_y == -1 && data->win == false)
		moved += move_player_backward(data);
	if (data->player.move_x == -1 && data->win == false)
		moved += move_player_left(data);
	if (data->player.move_x == 1 && data->win == false)
		moved += move_player_right(data);
	if (data->player.rotate != 0)
		moved += rotate_player(data, data->player.rotate);
	return (moved);
}
