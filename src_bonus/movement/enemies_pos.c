/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanitas <vanitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:53:07 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/08 16:05:34 by vanitas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

int	on_player(t_data *data, double x, double y, t_sprite *enemy)
{
	if (y >= data->player.pos_y - 0.5 / enemy->width_scale && y
		<= data->player.pos_y + 0.5 / enemy->width_scale && x
		>= data->player.pos_x - 0.5 / enemy->width_scale && x
		<= data->player.pos_x + 0.5 / enemy->width_scale)
		return (1);
	return (0);
}

int	is_valid_enemy_pos(t_data *data, double x, double y, t_sprite *enemy)
{
	if ((data->i.map[(int)(y)][(int)(x)] == '0'
		|| data->i.map[(int)(y)][(int)(x)] == 'H')
		&& !on_player(data, x, y, enemy))
		return (1);
	return (0);
}

void	validate_enemies_move_2(t_data *data, t_sprite *enemy,
	double dir_x)
{
	if (dir_x > 0)
	{
		if (is_valid_enemy_pos(data,
				(enemy->pos_x + dir_x * enemy->stats.ms) + 0.25,
				enemy->pos_y, enemy))
			enemy->pos_x += dir_x * enemy->stats.ms;
	}
	else if (dir_x <= 0)
	{
		if (is_valid_enemy_pos(data,
				(enemy->pos_x + dir_x * enemy->stats.ms) - 0.5,
				enemy->pos_y, enemy))
			enemy->pos_x += dir_x * enemy->stats.ms;
	}
}

void	validate_enemies_move(t_data *data, t_sprite *enemy,
	double dir_x, double dir_y)
{
	validate_enemies_move_2(data, enemy, dir_x);
	if (dir_y > 0)
	{
		if (is_valid_enemy_pos(data,
				enemy->pos_x, enemy->pos_y + dir_y * enemy->stats.ms + 0.25,
				enemy))
			enemy->pos_y += dir_y * enemy->stats.ms;
	}
	else if (dir_y <= 0)
	{
		if (is_valid_enemy_pos(data,
				enemy->pos_x, enemy->pos_y + dir_y * enemy->stats.ms - 0.5,
				enemy))
			enemy->pos_y += dir_y * enemy->stats.ms;
	}
}
