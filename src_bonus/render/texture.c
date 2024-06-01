/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:34:11 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/19 18:59:17 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	init_texture_pixels(t_data *data)
{
	int	i;

	if (data->texture_pixels)
		free_tab((void **)data->texture_pixels);
	data->texture_pixels = ft_calloc(data->height + 1, sizeof(int *));
	if (!data->texture_pixels)
		clean_exit(data, err_msg(ERR_MALLOC));
	i = 0;
	while (i < data->height)
	{
		data->texture_pixels[i] = ft_calloc(data->width + 1, sizeof(int));
		if (!data->texture_pixels[i])
			clean_exit(data, err_msg(ERR_MALLOC));
		i++;
	}
}

static void	get_texture_index(t_data *data, t_ray *ray)
{
	int	ok;

	ok = 0;
	if (ray->hit == 2)
		data->i.index = DOOR;
	else if (ray->hit == 3)
		data->i.index = DOOR_OPEN0;
	else if (ray->hit == 4)
		data->i.index = DOOR_OPEN1;
	else if (ray->hit == 5)
		data->i.index = DOOR_OPEN2;
	else if (ray->hit == 6)
		data->i.index = DOOR_OPEN3;
	else if (ray->hit == 7)
		data->i.index = BARREL0;
	else if (ray->hit == 8)
		data->i.index = BARREL1;
	else if (ray->hit == 9)
	{
		data->i.index = BARREL2;
		ok = 1;
	}
	else if (1)
		get_texture_index_norm(data, ray, ok);
}

static void	calcul_texture_pixels(t_data *data, t_info *i, t_ray *ray)
{
	get_texture_index(data, ray);
	i->x = (int)(ray->wall_x * data->textures2[i->index].width);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		i->x = data->textures2[i->index].width - i->x - 1;
	i->step = 1.0 * data->textures2[i->index].width / ray->line_height;
	i->pos = (ray->draw_start - data->height / 2
			+ ray->line_height / 2) * i->step;
}

void	update_texture_pixels(t_data *data, t_ray *ray, int x)
{
	t_texnorm	norm;

	norm.trp = false;
	calcul_texture_pixels(data, &data->i, ray);
	norm.y = ray->draw_start - 1;
	while (++norm.y < ray->draw_end)
		update_texture_pixels_norm(data, x, &norm);
	if (norm.trp == true)
	{
		perform_dda(data, ray);
		calculate_line_height(ray, data, &data->player);
		update_texture_pixels(data, ray, x);
	}
}
