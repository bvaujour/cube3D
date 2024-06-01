/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:19:24 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/23 10:19:11 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	afficher_image_avion_norm(t_sprite *ship, float angle)
{
	if (angle < 3.14 - 0.5 && angle > 0.6)
		ship->steptick = 3;
	else if (angle <= 0.6 && angle > -1.45)
		ship->steptick = 0;
	else if (angle <= -1.45 && angle > -1.65)
		ship->steptick = 2;
	else
		ship->steptick = 1;
}

void	update_ship_render_norm(t_data *data, t_sprite *enemy)
{
	enemy->cl.enemy_height = abs((int)(data->height
				/ enemy->cl.transform_y)) / enemy->height_scale;
	enemy->cl.draw_starty = (-enemy->cl.enemy_height / 2
			+ data->height / 2) + enemy->cl.v_move_screen;
	if (enemy->cl.draw_starty < 0)
		enemy->cl.draw_starty = 0;
	enemy->cl.draw_endy = (enemy->cl.enemy_height / 2 + data->height / 2)
		+ enemy->cl.v_move_screen;
	if (enemy->cl.draw_endy >= data->height)
		enemy->cl.draw_endy = data->height - 1;
	enemy->cl.enemy_width = abs((int)(data->height / enemy->cl.transform_y))
		/ enemy->width_scale;
	enemy->cl.draw_startx = -enemy->cl.enemy_width / 2
		+ enemy->cl.enemy_screen_x;
	if (enemy->cl.draw_startx < 0)
		enemy->cl.draw_startx = 0;
	enemy->cl.draw_endx = enemy->cl.enemy_width / 2 + enemy->cl.enemy_screen_x;
	if (enemy->cl.draw_endx >= data->width)
		enemy->cl.draw_endx = data->width - 1;
}

void	add_ship_in_texture_norm(t_data *data, t_sprite *enemy, int y,
	t_norm *norm)
{
	while (y++ < enemy->cl.draw_endy)
	{
		norm->tex_y = ((((y - enemy->cl.v_move_screen) * 256
						- data->height * 128
						+ enemy->cl.enemy_height * 128)
					* enemy->motion[enemy->steptick].height)
				/ enemy->cl.enemy_height) / 256;
		if (norm->tex_y < 0)
			continue ;
		norm->color = enemy->motion[enemy->steptick]
			.addr[enemy->motion[enemy->steptick].width
			* norm->tex_y + norm->tex_x];
		if ((norm->color & 0x00FFFFFF) != 0
			&& data->texture_pixels[y][enemy->cl.draw_startx] == 0)
			data->texture_pixels[y][enemy->cl.draw_startx] = norm->color;
	}
}

void	order_enemy_norm(t_sprite *enemies, t_sprite *new, int nb_enemies,
	t_order *norm)
{
	while (++norm->i < nb_enemies)
	{
		norm->j = -1;
		norm->count = 0;
		while (++norm->j < nb_enemies)
			if (enemies[norm->i].distance < enemies[norm->j].distance)
				norm->count++;
		new[norm->count] = enemies[norm->i];
	}
}

void	update_animation(t_data *data, t_sprite *enemy)
{
	if (enemy->see_player && enemy->c == 'Z')
		update_animation_norm(enemy);
	else if (enemy->c == 'X')
	{
		if (enemy->stats.hp <= 0 && enemy->steptick < 5
			&& get_time() - enemy->steptime > 100 * enemy->steptick)
		{
			enemy->motion = data->all_enemies_anim.dino_roar;
			enemy->steptick++;
			enemy->steptime = get_time();
		}
		else if (enemy->stats.hp > 0 && !enemy->attacking
			&& enemy->see_player && get_time() - enemy->steptime > 70)
		{
			enemy->motion = data->all_enemies_anim.dino_walk;
			enemy->steptick++;
			enemy->steptick %= 5;
			enemy->steptime = get_time();
		}
		else if (enemy->stats.hp > 0 && !enemy->attacking && !enemy->see_player)
			roar(enemy);
		else if (enemy->stats.hp > 0
			&& enemy->attacking && get_time() - enemy->steptime > 70)
			update_animation_norm_2(data, enemy);
	}
}
