/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:34:11 by vanitas           #+#    #+#             */
/*   Updated: 2023/12/19 18:06:01 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	init_texture_pixels(t_data *data)
{
	int	i;

	if (data->texture_pixels)
		free_tab((void **)data->texture_pixels);
	data->texture_pixels = ft_calloc(data->height + 1,
			sizeof * data->texture_pixels);
	if (!data->texture_pixels)
		clean_exit(data, err_msg(ERR_MALLOC));
	i = 0;
	while (i < data->height)
	{
		data->texture_pixels[i] = ft_calloc(data->width + 1,
				sizeof * data->texture_pixels);
		if (!data->texture_pixels[i])
			clean_exit(data, err_msg(ERR_MALLOC));
		i++;
	}
}

static void	get_texture_index(t_data *data, t_ray *ray)
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

void	update_texture_pixels(t_data *data, t_info *i, t_ray *ray, int x)
{
	int	y;
	int	color;

	get_texture_index(data, ray);
	i->x = (int)(ray->wall_x * i->size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		i->x = i->size - i->x - 1;
	i->step = 1.0 * i->size / ray->line_height;
	i->pos = (ray->draw_start - data->height / 2 + ray->line_height / 2)
		* i->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		i->y = (int)i->pos & (i->size - 1);
		i->pos += i->step;
		color = data->textures[i->index][i->size * i->y + i->x];
		if (i->index == NORTH || i->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			data->texture_pixels[y][x] = color;
		y++;
	}
}
