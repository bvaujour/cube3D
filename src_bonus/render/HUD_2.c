/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HUD_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanitas <vanitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:32:57 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/09 14:35:43 by vanitas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	put_face(t_data *data, t_img *img)
{
	static int		i = 0;
	static time_t	t0 = 0;

	put_img_to_img(img, &data->player.face[i], data->width / 2.35
		- data->player.face[i].width / 2, data->height
		- data->player.face[i % 6].height - 16);
	if (get_time() - t0 > 300)
	{
		t0 = get_time();
		i += 1;
	}
	i %= 5;
}

void	print_life(t_data *data, t_img *img)
{
	int	x;
	int	y;
	int	drawstart;
	int	drawend;

	drawstart = data->width / 1.505;
	drawend = data->width / 1.024;
	y = data->height - data->player.hud.height / 1.7;
	while (++y < data->height - data->player.hud.height / 2)
	{
		x = drawstart;
		while (++x < drawend)
			if (x > drawstart + data->player.stats.hp
				* (drawend - drawstart) / 100)
				set_image_pixel(img, x, y, 0x000000);
	}
}

void	print_stamina(t_data *data, t_img *img)
{
	int	x;
	int	y;
	int	drawstart;
	int	drawend;

	drawstart = data->width / 1.52;
	drawend = data->width - data->width / 56;
	upgrade_stamina(data);
	y = data->height - data->height / 22;
	while (++y < data->height - data->height / 52)
	{
		x = drawstart;
		while (++x < drawend)
			if (x > drawstart + data->player.stats.stamina
				* (drawend - drawstart) / 100)
				set_image_pixel(img, x, y, 0x000000);
	}
}

void	draw_circle(int center_x, int center_y, t_img *img)
{
	int	radius;
	int	x;
	int	y;

	radius = 3;
	x = center_x - radius;
	while (x <= center_x + radius)
	{
		y = center_y - radius;
		while (y <= center_y + radius)
		{
			if ((x - center_x) * (x - center_x) + (y - center_y)
				* (y - center_y) <= radius * radius)
				set_image_pixel(img, x, y, 0xFF0000);
			y++;
		}
		x++;
	}
}

void	minimap(t_data *data, t_img *image)
{
	int	x;
	int	y;

	draw_circle(round(data->player.pos_x * data->width / 4 / data->i.map_w),
		round(data->player.pos_y * data->height / 4 / data->i.map_h), image);
	y = -1;
	while (++y < data->height / 4)
	{
		x = -1;
		while (++x < data->width / 4)
		{
			if (data->i.map[(y * data->i.map_h) / (data->height
						/ 4)][(x * data->i.map_w) / (data->width / 4)] == '1')
				set_image_pixel(image, x, y, 0xFFFFFFFF);
			else if (data->i.map[(y * data->i.map_h) / (data->height
						/ 4)][(x * data->i.map_w) / (data->width / 4)] == 'D')
				set_image_pixel(image, x, y, 0xFF0000);
			else if (data->i.map[(y * data->i.map_h) / (data->height
						/ 4)][(x * data->i.map_w) / (data->width / 4)] == 'H')
				set_image_pixel(image, x, y, 0x00FF00);
			x++;
		}
		y++;
	}
}
