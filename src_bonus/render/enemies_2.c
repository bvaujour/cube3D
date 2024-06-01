/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:10:15 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/19 18:44:54 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	add_ship_in_texture(t_data *data, t_sprite *enemy)
{
	int		y;
	t_norm	norm;

	norm.tex_y = 0;
	norm.color = 0;
	while (enemy->cl.draw_startx < enemy->cl.draw_endx)
	{
		y = enemy->cl.draw_starty - 1;
		norm.tex_x = (int)(256 * (enemy->cl.draw_startx
					- (-enemy->cl.enemy_width / 2 + enemy->cl.enemy_screen_x))
				* enemy->motion[enemy->steptick].width
				/ enemy->cl.enemy_width) / 256;
		if (enemy->cl.transform_y > 0
			&& enemy->cl.draw_startx > 0 && enemy->cl.draw_startx < data->width)
			add_ship_in_texture_norm(data, enemy, y, &norm);
		enemy->cl.draw_startx++;
	}
}
//with scaling 38

void	update_ship_render(t_data *data, t_sprite *enemy)
{
	enemy->cl.inv_det = 1.0 / (data->player.plane_x * data->player.dir_y
			- data->player.dir_x * data->player.plane_y);
	enemy->cl.transform_x = enemy->cl.inv_det * (data->player.dir_y
			* (enemy->pos_x - data->player.pos_x) - data->player.dir_x
			* (enemy->pos_y - data->player.pos_y));
	enemy->cl.transform_y = enemy->cl.inv_det * (-data->player.plane_y
			* (enemy->pos_x - data->player.pos_x) + data->player.plane_x
			* (enemy->pos_y - data->player.pos_y));
	enemy->cl.v_move_screen = (int)(((-1 + enemy->height_scale)
				* enemy->motion[enemy->steptick].height)
			/ enemy->cl.transform_y) - enemy->fly;
	enemy->cl.enemy_screen_x = (int)((data->width / 2)
			* (1 + enemy->cl.transform_x / enemy->cl.transform_y));
	update_ship_render_norm(data, enemy);
}
//with scaling 64/68/70/74/78

void	afficher_image_avion(t_data *data, t_sprite *ship)
{
	float	angle;

	angle = atan2(ship->pos_y - data->player.pos_y, ship->pos_x
			- data->player.pos_x);
	if (ship->dir_y < 0)
	{
		if (angle > -3.14 + 0.5 && angle < -0.6)
			ship->steptick = 3;
		else if (angle >= -0.6 && angle < 1.45)
			ship->steptick = 1;
		else if (angle >= 1.45 && angle < 1.65)
			ship->steptick = 2;
		else
			ship->steptick = 0;
	}
	else
		afficher_image_avion_norm(ship, angle);
}

void	update_ship(t_data *data, t_sprite *ship)
{
	afficher_image_avion(data, ship);
	ship->pos_x += ship->dir_x * ship->stats.ms;
	ship->pos_y += ship->dir_y * ship->stats.ms;
	if (fabs(ship->pos_x) + fabs(ship->pos_y) > 2000)
	{
		ship->pos_x = pos_neg() * (rand() % 100);
		ship->pos_y = pos_neg() * ((rand() % 1000) + 300);
		ship->fly = (rand() % 200) + 200;
		ship->dir_x = pos_neg() * ((double)(rand() % 50) / 100);
		ship->dir_y = pos_neg();
		ship->width_scale = (float)((rand() % 15) + 5) / 100;
		ship->height_scale = ship->width_scale;
		ship->stats.ms = (rand() % 40 + 1) / ship->width_scale / 50;
	}
	update_ship_render(data, ship);
	add_ship_in_texture(data, ship);
}

void	update_item(t_data *data, t_sprite *item)
{
	update_item_norm(item);
	if (item->c == 'A' && data->player.pos_x >= item->pos_x - 0.35
		&& data->player.pos_x <= item->pos_x + 0.35
		&& data->player.pos_y >= item->pos_y - 0.35
		&& data->player.pos_y <= item->pos_y + 0.35)
	{
		update_health_point(data, &data->player.stats, 50);
		data->player.stats.stamina = 100;
		item->pos_x = -8;
		item->pos_y = -8;
	}
	else if (item->c == 'C' && data->player.pos_x >= item->pos_x - 0.35
		&& data->player.pos_x <= item->pos_x + 0.35
		&& data->player.pos_y >= item->pos_y - 0.35
		&& data->player.pos_y <= item->pos_y + 0.35)
	{
		data->player.chipset++;
		item->pos_x = -10;
		item->pos_y = -10;
	}
	update_enemies_render(data, item);
	add_enemies_in_texture(data, item);
}
