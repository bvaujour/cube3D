/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:34:06 by vanitas           #+#    #+#             */
/*   Updated: 2023/12/20 23:00:37 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

static void	get_player_pos(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (data->i.map[++y])
	{
		x = -1;
		while (data->i.map[y][++x])
		{
			if (data->i.map[y][x] == 'N' || data->i.map[y][x] == 'S'
				|| data->i.map[y][x] == 'E' || data->i.map[y][x] == 'W')
			{
				data->player.pos_x = x + 0.5;
				data->player.pos_y = y + 0.5;
				data->i.map[y][x] = '0';
				data->i.mapcopy[y][x] = '0';
			}
		}
	}
}

static void	init_player_north_south(t_player *player)
{
	if (player->dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (player->dir == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else
		return ;
}

static void	init_player_east_west(t_player *player)
{
	if (player->dir == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (player->dir == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else
		return ;
}

void	init_player_direction(t_data *data)
{
	get_player_pos(data);
	init_player_north_south(&data->player);
	init_player_east_west(&data->player);
}
