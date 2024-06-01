/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanitas <vanitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:49:47 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/09 17:26:47 by vanitas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	update_animation_norm_2(t_data *data, t_sprite *enemy)
{
	enemy->steptick++;
	enemy->steptime = get_time();
	if (enemy->steptick == 6 && enemy->in_range)
		update_health_point(data, &data->player.stats,
			-enemy->stats.dmg);
	if (enemy->steptick > 10)
	{
		enemy->motion = data->all_enemies_anim.dino_walk;
		enemy->steptick = 0;
		enemy->attacking = false;
		enemy->stats.ms = 0.2;
	}
}

void	update_animation_norm(t_sprite *enemy)
{
	if (enemy->steptick % 3 == 1 && get_time() - enemy->steptime > 450)
	{
		enemy->stats.ms = 0;
		enemy->steptick++;
		enemy->steptick %= 6;
		enemy->steptime = get_time();
	}
	else if (enemy->steptick % 3 != 1 && get_time() - enemy->steptime > 200)
	{
		enemy->stats.ms += 0.03;
		enemy->steptick++;
		enemy->steptick %= 6;
		enemy->steptime = get_time();
	}
}

void	add_enemies_in_texture_norm(t_data *data, t_sprite *enemy,
	int y, t_norm *norm)
{
	while (++y < enemy->cl.draw_endy)
	{
		norm->tex_y = ((((y - enemy->cl.v_move_screen) * 256
						- data->height * 128 + enemy->cl.enemy_height
						* 128) * enemy->motion[enemy->steptick].height)
				/ enemy->cl.enemy_height) / 256;
		if (norm->tex_y < 0)
			continue ;
		norm->color = enemy->motion[enemy->steptick]
			.addr[enemy->motion[enemy->steptick].width
			* norm->tex_y + norm->tex_x];
		if ((norm->color & 0x00FFFFFF) != 0)
			data->texture_pixels[y][enemy->cl.draw_startx] = norm->color
				| (65536 * ((enemy->stats.max_hp
							- enemy->stats.hp) / 5));
		if (enemy->cl.draw_startx == data->width / 2
			&& y == data->height / 2)
			data->player.aiming_at = enemy;
	}
}

void	update_enemies_render_norm(t_data *data, t_sprite *enemy)
{
	enemy->distance = calculate_sprite_distance(data,
			enemy->pos_x, enemy->pos_y);
	enemy->cl.inv_det = 1.0
		/ (data->player.plane_x * data->player.dir_y
			- data->player.dir_x * data->player.plane_y);
	enemy->cl.transform_x = enemy->cl.inv_det
		* (data->player.dir_y * (enemy->pos_x - data->player.pos_x)
			- data->player.dir_x * (enemy->pos_y - data->player.pos_y));
	enemy->cl.transform_y = enemy->cl.inv_det
		* (-data->player.plane_y * (enemy->pos_x - data->player.pos_x)
			+ data->player.plane_x * (enemy->pos_y - data->player.pos_y));
	enemy->cl.v_move_screen = (int)(((-1 + enemy->height_scale)
				* enemy->motion[enemy->steptick].height)
			/ enemy->cl.transform_y) - enemy->fly;
	enemy->cl.enemy_screen_x = (int)((data->width / 2)
			* (1 + enemy->cl.transform_x / enemy->cl.transform_y));
}

void	update_item_norm(t_sprite *item)
{
	if (get_time() - item->steptime > 5)
	{
		item->fly += item->incr;
		item->steptime = get_time();
	}
	if (item->fly == 15 || item->fly == -15)
		item->incr = -item->incr;
}
