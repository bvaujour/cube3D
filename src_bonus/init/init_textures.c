/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:59:29 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/29 13:57:53 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"
#include <pthread.h>

void	init_motion(t_data *data, t_motion *motion, t_img *load)
{
	motion->ter_walk[0] = new_img_xpm(data, "textures/enemies/terminator0.xpm");
	motion->ter_walk[1] = new_img_xpm(data, "textures/enemies/terminator1.xpm");
	motion->ter_walk[2] = new_img_xpm(data, "textures/enemies/terminator2.xpm");
	motion->ter_walk[3] = new_img_xpm(data, "textures/enemies/terminator3.xpm");
	motion->ter_walk[4] = new_img_xpm(data, "textures/enemies/terminator4.xpm");
	motion->ter_walk[5] = new_img_xpm(data, "textures/enemies/terminator5.xpm");
	loading(data, load, 70);
	motion->dino_walk[0] = new_img_xpm(data, "textures/enemies/dinorun0.xpm");
	motion->dino_walk[1] = new_img_xpm(data, "textures/enemies/dinorun1.xpm");
	motion->dino_walk[2] = new_img_xpm(data, "textures/enemies/dinorun2.xpm");
	motion->dino_walk[3] = new_img_xpm(data, "textures/enemies/dinorun3.xpm");
	motion->dino_walk[4] = new_img_xpm(data, "textures/enemies/dinorun4.xpm");
	loading(data, load, 75);
	motion->dino_roar[0] = new_img_xpm(data, "textures/enemies/roar0.xpm");
	motion->dino_roar[1] = new_img_xpm(data, "textures/enemies/roar1.xpm");
	motion->dino_roar[2] = new_img_xpm(data, "textures/enemies/roar2.xpm");
	motion->dino_roar[3] = new_img_xpm(data, "textures/enemies/roar3.xpm");
	motion->dino_roar[4] = new_img_xpm(data, "textures/enemies/roar4.xpm");
	motion->dino_roar[5] = new_img_xpm(data, "textures/enemies/roar5.xpm");
	loading(data, load, 80);
	init_motion_2(data, motion, load);
	init_motion_3(data, motion, load);
}

void	init_enemies(t_data *data)
{
	int	i;
	int	j;
	int	k;

	j = -1;
	k = 0;
	while (data->i.map[++j])
	{
		i = -1;
		while (data->i.map[j][++i])
		{
			if (data->i.map[j][i] == 'Z')
			{
				data->i.map[j][i] = '0';
				data->i.mapcopy[j][i] = '0';
				data->enemies[k++] = init_term(data, i, j);
			}
			else if (data->i.map[j][i] == 'X')
			{
				data->i.mapcopy[j][i] = '0';
				data->i.map[j][i] = '0';
				data->enemies[k++] = init_dino(data, i, j);
			}
		}
	}
}

static void	init_player_img(t_data *data, t_player *player, t_img *load)
{
	init_player_img_2(data, player, load);
	player->reload[3] = new_img_xpm(data, "textures/gun/reloadpistol6.xpm");
	player->reload[4] = new_img_xpm(data, "textures/gun/reloadpistol8.xpm");
	player->reload[5] = new_img_xpm(data, "textures/gun/reloadpistol10.xpm");
	player->reload[6] = new_img_xpm(data, "textures/gun/reloadpistol12.xpm");
	loading(data, load, 60);
	player->reload[7] = new_img_xpm(data, "textures/gun/reloadpistol14.xpm");
	player->reload[8] = new_img_xpm(data, "textures/gun/reloadpistol16.xpm");
	player->reload[9] = new_img_xpm(data, "textures/gun/reloadpistol18.xpm");
	player->reload[10] = new_img_xpm(data, "textures/gun/reloadpistol20.xpm");
	data->win_screen = new_img(data, data->width, data->height,
			"textures/you_win.xpm");
	loading(data, load, 65);
	player->bullets = new_img(data, data->width / 100, data->height / 30,
			"textures/HUD/bullet.xpm");
	player->death = new_img(data, data->width, data->height,
			"textures/end/you_died.xpm");
	player->obj1 = new_img(data, data->width / 4, data->height / 20,
			"textures/objectives/obj1.xpm");
}

void	init_walls(t_data *data, t_img *load)
{
	int	i;

	i = -1;
	while (++i < 200)
	{
		data->stars[i].x = rand() % data->width;
		data->stars[i].y = rand() % data->height / 2;
	}
	init_walls_2(data, load);
	data->textures2[BARREL0] = new_img_xpm(data,
			"textures/barrel/sifibarrel0.xpm");
	data->textures2[BARREL1] = new_img_xpm(data,
			"textures/barrel/sifibarrel1.xpm");
	data->textures2[BARREL2] = new_img_xpm(data,
			"textures/barrel/sifibarrel2.xpm");
	data->textures2[BARREL3] = new_img_xpm(data,
			"textures/barrel/sifibarrel3.xpm");
	data->textures2[BARREL4] = new_img_xpm(data,
			"textures/barrel/sifibarrel4.xpm");
	data->textures2[BARREL5] = new_img_xpm(data,
			"textures/barrel/sifibarrel5.xpm");
	data->textures2[BARREL6] = new_img_xpm(data,
			"textures/barrel/sifibarrel6.xpm");
	data->textures2[FLOOR] = new_img_xpm(data, "textures/floor.xpm");
	data->textures2[CEILING] = new_img_xpm(data, "textures/floor3.xpm");
}

void	init_textures(t_data *data)
{
	data->load = new_img(data, data->width / 4, data->height / 12,
			"textures/HUD/loading.xpm");
	loading(data, &data->load, 0);
	init_time_s_out(data);
	set_anim(data, &data->anim);
	init_cat_stats(data);
	init_texture_pixels(data);
	loading(data, &data->load, 10);
	init_walls(data, &data->load);
	data->enemies = malloc(sizeof(t_sprite) * data->nb_enemies);
	if (!data->enemies)
		clean_exit(data, 0);
	init_player_img(data, &data->player, &data->load);
	init_motion(data, &data->all_enemies_anim, &data->load);
	init_enemies(data);
	init_shipyard(data);
	init_chipset(data);
	init_heal(data);
	loading(data, &data->load, 100);
}
