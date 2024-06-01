/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:07:52 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/16 19:25:04 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"
#include "../../lib/test.h"

void	screen_shake(t_data *data)
{
	int			i;
	int			j;
	t_vector	base;

	i = (rand() % 8) * pos_neg();
	j = (rand() % 8) * pos_neg();
	mlx_mouse_get_pos(data->mlx_ptr, data->mlx_win, &base.x, &base.y);
	mlx_mouse_move(data->mlx_ptr, data->mlx_win, base.x + i, base.y + j);
}

void	set_frame_image_pixel(t_data *data, t_img *image, int x, int y)
{
	if (data->player.teleporting > 0 && rand()
		% (6 - data->player.teleporting) == 0)
		set_image_pixel(image, x, y, 0xFFFFFF);
	else if (data->texture_pixels[y][x] > 0)
		set_image_pixel(image, x, y, data->texture_pixels[y][x]);
	else if (y < data->height / 2 && get_pixel_img(image, x, y) == 0x000000)
		set_image_pixel(image, x, y, data->i.hex_ceiling);
	else if (y >= data->height / 2)
		set_image_pixel(image, x, y, data->i.hex_floor);
	if (data->player.hited >= 1 && data->player.hited <= 10)
	{
		if (rand() % data->player.hited == 0)
			set_image_pixel(image, x, y, 0xFF0000);
		else if (rand() % data->player.hited == 1)
			set_image_pixel(image, x, y, 0x101010);
	}
}

void	draw_stars(t_data *data, t_img *img)
{
	static int	pos = 0;
	int			i;
	int			pole;

	pole = 315;
	i = -1;
	pos += data->player.orient;
	while (++i < 200)
	{
		if ((data->stars[i].x - 3 * pos) % data->width < 0)
			set_image_pixel(img, (data->stars[i].x + data->width - 3 * pos)
				% data->width, data->stars[i].y, 0xFFFFFF);
		else
			set_image_pixel(img, (data->stars[i].x - 3 * pos)
				% data->width, data->stars[i].y, 0xFFFFFF);
	}
	the_put_img(img, &data->moon, (5 * data->width / 4 - 8.2 * pos),
		data->height / 6);
	the_put_img(img, &data->earth, (5 * data->width / 4 - 8 * pos),
		data->height / 8);
	the_put_img(img, &data->mars, (data->width / 4 - 6 * pos), 0);
	if (pos > pole)
		pos = -pole;
	if (pos < -pole)
		pos = pole;
}

void	portal(t_data *data)
{
	static int	incr = 1;
	int			portal_dist;

	portal_dist = 3;
	data->player.teleporting += incr;
	if (data->player.teleporting == 5)
	{
		if (is_valid_pos_in_map(data, data->player.pos_x - data->player.dir_x
				* portal_dist, data->player.pos_y - data->player.dir_y
				* portal_dist) && is_valid_pos_wall_collision(data,
				data->player.pos_x - data->player.dir_x * portal_dist,
				data->player.pos_y - data->player.dir_y * portal_dist))
		{
			data->player.pos_x = data->player.pos_x
				- data->player.dir_x * portal_dist;
			data->player.pos_y = data->player.pos_y
				- data->player.dir_y * portal_dist;
		}
		incr = -1;
	}
	else if (data->player.teleporting == 0)
		incr = 1;
}

void	render_frame_norm(t_data *data, t_img *image)
{
	if (data->player.teleporting)
		portal(data);
	if (data->win == false)
		user_interface(data, image);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, image->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, image->img_ptr);
	data->enemies = order_enemy(data, data->enemies, data->nb_enemies);
}
