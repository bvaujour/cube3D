/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:54:41 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/17 18:01:29 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	init_player_2(t_player *player)
{
	player->stats.hp = 100;
	player->stats.dmg = 20;
	player->stats.is_player = true;
	player->is_firing = 0;
	player->can_damage = false;
	player->aiming_at = NULL;
	player->hited = 0;
	player->punched = 0;
	player->nb_bullets = 6;
	player->reloading = false;
	player->teleporting = 0;
	player->chipset = 0;
}

void	init_img_clean(t_img *img)
{
	img->img_ptr = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
}
