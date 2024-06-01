/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:21:18 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/19 18:10:50 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

bool	update_health_point(t_data *data, t_stats *stats, int delta)
{
	if (stats->hp > 0)
		stats->hp += delta;
	if (stats->is_player && delta < 0)
		data->player.hited = 1;
	if (stats->hp <= 0)
	{
		if (stats->is_player)
			mlx_clear_window(data->mlx_ptr, data->mlx_win);
		stats->hp = 0;
		return (true);
	}
	if (stats->hp > 100)
		stats->hp = 100;
	return (false);
}

void	pop_item(t_data *data)
{
	if (data->player.aiming_at->c == 'Z')
	{
		data->chipset.pos_x = data->player.aiming_at->pos_x;
		data->chipset.pos_y = data->player.aiming_at->pos_y;
	}
	if (data->player.aiming_at->c == 'X')
	{
		data->greenherb.pos_x = data->player.aiming_at->pos_x;
		data->greenherb.pos_y = data->player.aiming_at->pos_y;
	}
}

static void	start_firing(t_data *data)
{
	data->player.is_firing = 1;
	data->player.can_damage = true;
	if (data->player.aiming_at != NULL
		&& data->player.aiming_at->stats.hp > 0)
	{
		if (data->player.aiming_at->c == 'Z')
		{
			data->player.aiming_at->steptick += pos_neg();
			if (data->player.aiming_at->steptick <= -1)
				data->player.aiming_at->steptick = 5;
			else if (data->player.aiming_at->steptick >= 6)
				data->player.aiming_at->steptick = 0;
			data->player.aiming_at->stats.ms = 0;
		}
		update_health_point(data, &data->player.aiming_at->stats,
			-data->player.stats.dmg);
		if (data->player.aiming_at->stats.hp <= 0)
		{
			pop_item(data);
			data->player.aiming_at->stats.ms = 0;
			data->player.aiming_at->steptick = 0;
		}
		data->player.aiming_at->see_player = true;
	}
}

void	fire(t_data *data)
{
	if (data->player.reloading == false)
	{
		if (!data->player.nb_bullets)
		{
			data->player.is_firing = 0;
			data->player.reloading = true;
		}
		else
		{
			start_firing(data);
			data->player.nb_bullets--;
		}
	}
}
