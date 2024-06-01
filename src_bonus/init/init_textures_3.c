/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:06:21 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/23 10:47:58 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	init_motion_2(t_data *data, t_motion *motion, t_img *load)
{
	motion->dino_attack[5] = new_img_xpm(data,
			"textures/enemies/dinoattack5.xpm");
	motion->dino_attack[6] = new_img_xpm(data,
			"textures/enemies/dinoattack6.xpm");
	motion->dino_attack[7] = new_img_xpm(data,
			"textures/enemies/dinoattack7.xpm");
	motion->dino_attack[8] = new_img_xpm(data,
			"textures/enemies/dinoattack8.xpm");
	motion->dino_attack[9] = new_img_xpm(data,
			"textures/enemies/dinoattack9.xpm");
	motion->dino_attack[10] = new_img_xpm(data,
			"textures/enemies/dinoattack10.xpm");
	loading(data, load, 90);
	motion->ter_attack = new_img(data, data->width, data->height,
			"textures/enemies/punch.xpm");
	motion->shiplr[0] = new_img_xpm(data, "textures/shipleft.xpm");
	motion->shiplr[1] = new_img_xpm(data, "textures/shipright.xpm");
	motion->shiplr[2] = new_img_xpm(data, "textures/shipfront.xpm");
	motion->shiplr[3] = new_img_xpm(data, "textures/shiprear.xpm");
}

void	init_player_img_2(t_data *data, t_player *player, t_img *load)
{
	player->hud = new_img(data, data->width, data->height / 6,
			"textures/HUD/HUD2.xpm");
	player->face[0] = new_img(data, data->width / 9, data->height / 8,
			"textures/face/djar0.xpm");
	player->face[1] = new_img(data, data->width / 9, data->height / 8,
			"textures/face/djar1.xpm");
	player->face[2] = new_img(data, data->width / 9, data->height / 8,
			"textures/face/djar2.xpm");
	player->face[3] = new_img(data, data->width / 9, data->height / 8,
			"textures/face/djar3.xpm");
	player->face[4] = new_img(data, data->width / 9, data->height / 8,
			"textures/face/djar4.xpm");
	loading(data, load, 40);
	player->gun[0] = new_img_xpm(data, "textures/gun/DE0.xpm");
	player->gun[1] = new_img_xpm(data, "textures/gun/DE1.xpm");
	player->gun[2] = new_img_xpm(data, "textures/gun/DE2.xpm");
	player->gun[3] = new_img_xpm(data, "textures/gun/DE3.xpm");
	player->gun[4] = new_img_xpm(data, "textures/gun/DE4.xpm");
	loading(data, load, 50);
	player->reload[0] = new_img_xpm(data, "textures/gun/reloadpistol0.xpm");
	player->reload[1] = new_img_xpm(data, "textures/gun/reloadpistol2.xpm");
	player->reload[2] = new_img_xpm(data, "textures/gun/reloadpistol4.xpm");
	loading(data, load, 55);
}

void	init_walls_2(t_data *data, t_img *load)
{
	loading(data, load, 15);
	data->mars = new_img_xpm(data, "textures/planetes/mars.xpm");
	data->moon = new_img_xpm(data, "textures/planetes/moon.xpm");
	data->earth = new_img_xpm(data, "textures/planetes/terre.xpm");
	data->textures2[NORTH] = new_img_xpm(data, data->i.no);
	data->textures2[SOUTH] = new_img_xpm(data, data->i.so);
	data->textures2[EAST] = new_img_xpm(data, data->i.ea);
	data->textures2[WEST] = new_img_xpm(data, data->i.we);
	data->textures2[ARROW] = new_img_xpm(data,
			"textures/murs/spacestationarrow.xpm");
	loading(data, load, 25);
	data->textures2[DOOR] = new_img_xpm(data, "textures/portes/sifi0.xpm");
	data->textures2[DOOR_OPEN0] = new_img_xpm(data,
			"textures/portes/sifi1.xpm");
	data->textures2[DOOR_OPEN1] = new_img_xpm(data,
			"textures/portes/sifi3.xpm");
	data->textures2[DOOR_OPEN2] = new_img_xpm(data,
			"textures/portes/sifi5.xpm");
	data->textures2[DOOR_OPEN3] = new_img_xpm(data,
			"textures/portes/sifi8.xpm");
	data->textures2[SASL] = new_img_xpm(data,
			"textures/portes/SASl.xpm");
	data->textures2[SASR] = new_img_xpm(data,
			"textures/portes/SASr.xpm");
	(loading(data, load, 35), protect_textures(data));
}

void	init_chipset(t_data *data)
{
	data->puce = new_img_xpm(data, "textures/fusible.xpm");
	data->chipset.motion = &data->puce;
	data->chipset.steptick = 0;
	data->chipset.steptime = get_time() + (rand() % 1000);
	data->chipset.pos_x = -10;
	data->chipset.pos_y = -10;
	data->chipset.dir_x = 0;
	data->chipset.dir_y = 0;
	data->chipset.stats.hp = 200;
	data->chipset.stats.max_hp = 200;
	data->chipset.last_move = 0;
	data->chipset.width_scale = 2;
	init_chipset_2(data);
}

void	init_heal(t_data *data)
{
	data->heal = new_img_xpm(data, "textures/greenherb.xpm");
	data->greenherb.motion = &data->heal;
	data->greenherb.steptick = 0;
	data->greenherb.steptime = get_time() + (rand() % 1000);
	data->greenherb.pos_x = -8;
	data->greenherb.pos_y = -8;
	data->greenherb.dir_x = 0;
	data->greenherb.dir_y = 0;
	data->greenherb.stats.hp = 200;
	data->greenherb.stats.max_hp = 200;
	data->greenherb.last_move = 0;
	data->greenherb.width_scale = 2.5;
	init_heal_2(data);
}
