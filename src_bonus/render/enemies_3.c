/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:10:27 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/17 18:31:31 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	update_enemies_render(t_data *data, t_sprite *enemy)
{
	update_enemies_render_norm(data, enemy);
	enemy->cl.enemy_height = abs((int)(data->height / enemy->cl.transform_y))
		/ enemy->height_scale;
	enemy->cl.draw_starty = (-enemy->cl.enemy_height / 2 + data->height / 2)
		+ enemy->cl.v_move_screen;
	if (enemy->cl.draw_starty < 0)
		enemy->cl.draw_starty = 0;
	enemy->cl.draw_endy = (enemy->cl.enemy_height / 2 + data->height / 2)
		+ enemy->cl.v_move_screen;
	if (enemy->cl.draw_endy >= data->height)
		enemy->cl.draw_endy = data->height - 1;
	enemy->cl.enemy_width = abs((int)(data->height / enemy->cl.transform_y))
		/ enemy->width_scale;
	enemy->cl.draw_startx = -enemy->cl.enemy_width
		/ 2 + enemy->cl.enemy_screen_x;
	if (enemy->cl.draw_startx < 0)
		enemy->cl.draw_startx = 0;
	enemy->cl.draw_endx = enemy->cl.enemy_width / 2 + enemy->cl.enemy_screen_x;
	if (enemy->cl.draw_endx >= data->width)
		enemy->cl.draw_endx = data->width - 1;
}

void	add_enemies_in_texture(t_data *data, t_sprite *enemy)
{
	t_norm	norm;
	int		y;

	norm.tex_y = 0;
	norm.color = 0;
	while (enemy->cl.draw_startx < enemy->cl.draw_endx)
	{
		y = enemy->cl.draw_starty - 1;
		norm.tex_x = (int)(256 * (enemy->cl.draw_startx
					- (-enemy->cl.enemy_width / 2 + enemy->cl.enemy_screen_x))
				* enemy->motion[enemy->steptick].width
				/ enemy->cl.enemy_width) / 256;
		if (enemy->cl.transform_y > 0 && enemy->cl.draw_startx > 0
			&& enemy->cl.draw_startx < data->width
			&& enemy->cl.transform_y < data->wall_dist[enemy->cl.draw_startx])
			add_enemies_in_texture_norm(data, enemy, y, &norm);
		enemy->cl.draw_startx++;
	}
}

void	player_detection(t_data *data, t_sprite *enemy, int x, int y)
{
	if (enemy->see_player == true || (data->i.mapcopy[y][x] != '0'
		&& data->i.mapcopy[y][x] != 'H') || x - enemy->pos_x > 15
			|| x - enemy->pos_x < -15 || y - enemy->pos_y > 15
				|| y - enemy->pos_y < -15)
		return ;
	if (x == (int)data->player.pos_x && y == (int)data->player.pos_y)
		enemy->see_player = true;
	data->i.mapcopy[y][x] = 'Z';
	player_detection(data, enemy, x - 1, y);
	player_detection(data, enemy, x + 1, y);
	player_detection(data, enemy, x, y - 1);
	player_detection(data, enemy, x, y + 1);
}

void	map_restore(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (data->i.mapcopy[++j])
	{
		i = -1;
		while (data->i.mapcopy[j][++i])
			if (data->i.mapcopy[j][i] == 'Z')
				data->i.mapcopy[j][i] = '0';
	}
}

void	update_enemies(t_data *data, t_sprite *enemy)
{
	if (enemy->c == 'Z' && enemy->stats.hp <= 0)
		return ;
	if (enemy->c == 'X' && enemy->stats.hp <= 0 && enemy->steptick == 6)
		return ;
	update_animation(data, enemy);
	update_enemies_render(data, enemy);
	add_enemies_in_texture(data, enemy);
	if (enemy->stats.hp > 0 && !enemy->see_player)
	{
		player_detection(data, enemy, (int)enemy->pos_x, (int)enemy->pos_y);
		map_restore(data);
	}
	if (enemy->stats.hp > 0 && enemy->see_player)
	{
		enemy->dir_x = data->player.pos_x - enemy->pos_x;
		enemy->dir_y = data->player.pos_y - enemy->pos_y;
		attack(data, enemy);
		chase_player(data, enemy);
	}
}
