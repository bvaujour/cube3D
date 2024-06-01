/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:19:33 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/23 10:53:41 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	get_texture_index_norm2(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			data->i.index = WEST;
		else
			data->i.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			data->i.index = SOUTH;
		else
			data->i.index = NORTH;
	}
}

void	get_texture_index_norm(t_data *data, t_ray *ray, int ok)
{
	if (ray->hit == 10 && !ok)
		data->i.index = BARREL3;
	else if (ray->hit == 11)
		data->i.index = BARREL4;
	else if (ray->hit == 12)
		data->i.index = BARREL5;
	else if (ray->hit == 13)
		data->i.index = BARREL6;
	else if (ray->hit == 14)
		data->i.index = ARROW;
	else if (ray->hit == 15)
		data->i.index = SASL;
	else if (ray->hit == 16)
		data->i.index = SASR;
	else if (1)
		get_texture_index_norm2(data, ray);
}

void	update_texture_pixels_norm(t_data *data, int x, t_texnorm *norm)
{
	data->i.y = (int)data->i.pos
		& (data->textures2[data->i.index].height - 1);
	data->i.pos += data->i.step;
	norm->color = data->textures2[data->i.index]
		.addr[data->textures2[data->i.index].height
		* data->i.y + data->i.x];
	if ((unsigned int)norm->color == 0xff000000)
		norm->trp = true;
	if (data->i.index == NORTH || data->i.index == EAST)
		norm->color = (norm->color >> 1) & 8355711;
	if (norm->color > 0)
		data->texture_pixels[norm->y][x] = norm->color;
}
