/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:43:23 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/18 13:21:05 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	init_motion_3(t_data *data, t_motion *motion, t_img *load)
{
	motion->dino_attack[0] = new_img_xpm(data,
			"textures/enemies/dinoattack0.xpm");
	motion->dino_attack[1] = new_img_xpm(data,
			"textures/enemies/dinoattack1.xpm");
	motion->dino_attack[2] = new_img_xpm(data,
			"textures/enemies/dinoattack2.xpm");
	motion->dino_attack[3] = new_img_xpm(data,
			"textures/enemies/dinoattack3.xpm");
	motion->dino_attack[4] = new_img_xpm(data,
			"textures/enemies/dinoattack4.xpm");
	loading(data, load, 85);
}

void	init_shipyard(t_data *data)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		data->ship[i] = init_ship(data);
		i++;
	}
	data->ship[0].pos_x = data->i.map_w;
	data->ship[0].pos_y = data->i.map_h;
	data->ship[0].stats.ms = 0;
	data->ship[0].fly = 50;
	data->ship[0].width_scale = 0.05;
	data->ship[0].height_scale = 0.05;
	data->ship[0].dir_x = 0.5;
	data->ship[0].dir_y = -0.9;
}

t_sprite	init_term(t_data *data, int i, int j)
{
	t_sprite	new;

	new.motion = data->all_enemies_anim.ter_walk;
	new.steptick = 0;
	new.steptime = get_time() + (rand() % 1000);
	new.pos_x = i + 0.5;
	new.pos_y = j + 0.5;
	new.dir_x = 0;
	new.dir_y = 0;
	new.stats.hp = 500;
	new.stats.max_hp = 500;
	new.stats.ms = 0.05;
	new.last_move = 0;
	init_term_2(&new);
	return (new);
}

t_sprite	init_dino(t_data *data, int i, int j)
{
	t_sprite	new;

	new.motion = data->all_enemies_anim.dino_roar;
	new.steptick = 0;
	new.steptime = get_time() + (rand() % 1000);
	new.pos_x = i + 0.5;
	new.pos_y = j + 0.5;
	new.dir_x = 0;
	new.dir_y = 0;
	new.stats.hp = 300;
	new.stats.max_hp = 300;
	new.stats.ms = 0.2;
	new.last_move = 0;
	init_dino_2(&new);
	return (new);
}

t_sprite	init_ship(t_data *data)
{
	t_sprite	new;

	new.motion = data->all_enemies_anim.shiplr;
	new.steptick = 0;
	new.steptime = get_time() + (rand() % 1000);
	new.pos_x = pos_neg() * (rand() % 100);
	new.pos_y = pos_neg() * ((rand() % 1000) + 300);
	new.dir_x = pos_neg() * ((double)(rand() % 50) / 100);
	new.dir_y = pos_neg();
	new.stats.hp = 200;
	new.stats.max_hp = 200;
	new.last_move = 0;
	new.width_scale = (float)((rand() % 15) + 5) / 100;
	init_ship_2(&new);
	return (new);
}
