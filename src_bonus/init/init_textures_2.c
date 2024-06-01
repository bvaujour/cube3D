/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:06:10 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/16 14:26:22 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	init_term_2(t_sprite *new)
{
	new->height_scale = (float)(rand() % 4 + 8) / 10;
	new->width_scale = new->height_scale + 0.5;
	new->stats.dmg = 15;
	new->stats.as = 1000;
	new->attacking = false;
	new->range = 2 - new->height_scale;
	new->in_range = false;
	new->stats.is_player = false;
	new->see_player = false;
	new->c = 'Z';
	new->incr = 1;
	new->fly = 0;
}

void	init_dino_2(t_sprite *new)
{
	new->width_scale = 0.8;
	new->height_scale = 0.9;
	new->stats.dmg = 20;
	new->stats.as = 1300;
	new->attacking = false;
	new->range = 1.5;
	new->in_range = false;
	new->stats.is_player = false;
	new->see_player = false;
	new->c = 'X';
	new->incr = 1;
	new->fly = 0;
}

void	init_ship_2(t_sprite *new)
{
	new->height_scale = new->width_scale;
	new->stats.ms = (rand() % 40 + 1) / new->width_scale / 50;
	new->stats.dmg = 20;
	new->stats.as = 1300;
	new->attacking = false;
	new->range = 1.5;
	new->in_range = false;
	new->stats.is_player = false;
	new->see_player = false;
	new->c = 'S';
	new->incr = 1;
	new->fly = (rand() % 200) + 200;
}

void	init_chipset_2(t_data *data)
{
	data->chipset.height_scale = 2;
	data->chipset.stats.ms = 0;
	data->chipset.stats.dmg = 0;
	data->chipset.stats.as = 1;
	data->chipset.attacking = false;
	data->chipset.range = 1;
	data->chipset.in_range = false;
	data->chipset.stats.is_player = false;
	data->chipset.see_player = false;
	data->chipset.c = 'C';
	data->chipset.incr = 1;
	data->chipset.fly = 0;
}

void	init_heal_2(t_data *data)
{
	data->greenherb.height_scale = 2.5;
	data->greenherb.stats.ms = 0;
	data->greenherb.stats.dmg = 0;
	data->greenherb.stats.as = 1;
	data->greenherb.attacking = false;
	data->greenherb.range = 1;
	data->greenherb.in_range = false;
	data->greenherb.stats.is_player = false;
	data->greenherb.see_player = false;
	data->greenherb.c = 'A';
	data->greenherb.incr = 0;
	data->greenherb.fly = -15;
}
