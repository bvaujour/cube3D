/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:35:46 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/24 12:48:48 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"
#include "../../lib/test.h"

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	init_texinfo(t_info *i)
{
	i->no = NULL;
	i->so = NULL;
	i->we = NULL;
	i->ea = NULL;
	i->floor = NULL;
	i->ciel = NULL;
	i->hex_floor = 0x0;
	i->hex_ceiling = 0x0;
	i->step = 0.0;
	i->pos = 0.0;
	i->x = 0;
	i->y = 0;
}

void	init_player(t_player *player)
{
	player->dir = '\0';
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->has_moved = 0;
	player->move_x = 0;
	player->move_y = 0;
	player->rotate = 0;
	player->stats.ms = 0.05;
	player->stats.stamina = 100;
	player->stats.sprint = 0;
	init_player_2(player);
}

void	init_struct(t_data *data)
{
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->wall_dist = NULL;
	data->config = NULL;
	data->i.island = NULL;
	data->i.mapcopy = NULL;
	data->lockcursor = 1;
	data->config = malloc(sizeof(char *));
	if (!data->config)
		(ft_dprintf(2, "Error, allocation\n"), end(data));
	*data->config = NULL;
	data->i.map = malloc(sizeof(char *));
	if (!data->i.map)
		(ft_dprintf(2, "Error, allocation\n"), end(data));
	*data->i.map = NULL;
	data->done = 0;
	data->game_launched = false;
	data->anim.alloced = false;
	data->nb_enemies = 0;
	data->enemies = NULL;
	data->time_limit = 120000;
	data->win = false;
	data->door = false;
}
// TITLE("BEGIN OF INIT_STRUCT"); // debug

void	init_data(t_data *data)
{
	init_img_nullifier(data);
	init_texinfo(&data->i);
	init_struct(data);
	init_player(&data->player);
	init_ray(&data->ray);
	data->texture_pixels = NULL;
}
