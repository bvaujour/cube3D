/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_norm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:33:21 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/19 19:23:15 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	init_raycasting_info(t_data *data, int x, t_ray *ray, t_player *player)
{
	ray->camera_x = 2 * x / (double)data->width - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

void	floorcasting_norm(t_data *data, t_floor *floor, int y)
{
	floor->ray_dirx0 = data->player.dir_x - data->player.plane_x;
	floor->ray_diry0 = data->player.dir_y - data->player.plane_y;
	floor->ray_dirx1 = data->player.dir_x + data->player.plane_x;
	floor->ray_diry1 = data->player.dir_y + data->player.plane_y;
	floor->p = y - data->height / 2;
	floor->pos_z = 0.5 * data->height;
	floor->row_distance = floor->pos_z / floor->p;
	floor->floor_stepx = floor->row_distance
		* (floor->ray_dirx1 - floor->ray_dirx0) / data->width;
	floor->floor_stepy = floor->row_distance
		* (floor->ray_diry1 - floor->ray_diry0) / data->width;
	floor->floor_x = data->player.pos_x + floor->row_distance
		* floor->ray_dirx0;
	floor->floor_y = data->player.pos_y + floor->row_distance
		* floor->ray_diry0;
}

void	floorcasting_norm_2(t_data *data, t_floor *floor, int y, int x)
{
	floor->cell_x = (int)(floor->floor_x);
	floor->cell_y = (int)(floor->floor_y);
	floor->tx = (int)(data->textures2[FLOOR].width
			* (floor->floor_x - floor->cell_x))
		& (data->textures2[FLOOR].width - 1);
	floor->ty = (int)(data->textures2[FLOOR].height
			* (floor->floor_y - floor->cell_y))
		& (data->textures2[FLOOR].height - 1);
	floor->floor_x += floor->floor_stepx;
	floor->floor_y += floor->floor_stepy;
	floor->floor_texture = FLOOR;
	floor->ceiling_texture = CEILING;
	floor->color = data->textures2[floor->floor_texture]
		.addr[data->textures2[FLOOR].width * floor->ty + floor->tx];
	floor->color = (floor->color >> 1) & 8355711;
	data->texture_pixels[y][x] = floor->color;
	floor->color = data->textures2[floor->ceiling_texture]
		.addr[data->textures2[CEILING].width * floor->ty + floor->tx];
	floor->color = (floor->color >> 1) & 8355711;
	data->texture_pixels[data->height - y - 1][x] = floor->color;
}

static void	perform_dda_norm_2(t_data *data, t_ray *ray, int ok)
{
	if (data->i.map[ray->map_y][ray->map_x] == 'N' && !ok)
		ray->hit = 8;
	else if (data->i.map[ray->map_y][ray->map_x] == 'O')
		ray->hit = 9;
	else if (data->i.map[ray->map_y][ray->map_x] == 'P')
		ray->hit = 10;
	else if (data->i.map[ray->map_y][ray->map_x] == 'Q')
		ray->hit = 11;
	else if (data->i.map[ray->map_y][ray->map_x] == 'R')
		ray->hit = 12;
	else if (data->i.map[ray->map_y][ray->map_x] == 'S')
		ray->hit = 13;
	else if (data->i.map[ray->map_y][ray->map_x] == '2')
		ray->hit = 14;
	else if (data->i.map[ray->map_y][ray->map_x] == '3')
		ray->hit = 15;
	else if (data->i.map[ray->map_y][ray->map_x] == '4')
		ray->hit = 16;
}

void	perform_dda_norm(t_data *data, t_ray *ray)
{
	int	ok;

	ok = 0;
	if (data->i.map[ray->map_y][ray->map_x] == '1')
		ray->hit = 1;
	else if (data->i.map[ray->map_y][ray->map_x] == 'D')
		ray->hit = 2;
	else if (data->i.map[ray->map_y][ray->map_x] == 'E')
		ray->hit = 3;
	else if (data->i.map[ray->map_y][ray->map_x] == 'F')
		ray->hit = 4;
	else if (data->i.map[ray->map_y][ray->map_x] == 'G')
		ray->hit = 5;
	else if (data->i.map[ray->map_y][ray->map_x] == 'H')
		ray->hit = 6;
	else if (data->i.map[ray->map_y][ray->map_x] == 'M')
	{
		ray->hit = 7;
		ok = 1;
	}
	else if (1)
		perform_dda_norm_2(data, ray, ok);
}
