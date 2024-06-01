/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:56:06 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/24 12:54:47 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"
#include "../../lib/test.h"

static void	render_frame(t_data *data)
{
	t_img	image;
	int		x;
	int		y;

	image.img_ptr = NULL;
	init_img(data, &image, data->width, data->height);
	draw_stars(data, &image);
	x = -1;
	while (++x < data->nb_enemies)
		update_enemies(data, &data->enemies[x]);
	x = -1;
	while (++x < 100)
		update_ship(data, &data->ship[x]);
	(update_item(data, &data->chipset), update_item(data, &data->greenherb));
	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
			set_frame_image_pixel(data, &image, x, y);
	}
	render_frame_norm(data, &image);
}

void	render_raycast(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		ft_bzero(data->texture_pixels[i], (data->width + 1) * sizeof(int));
		i++;
	}
	floorcasting(data);
	raycasting(&data->player, data);
	render_frame(data);
}

void	refresh(t_data *data, int i, int a)
{
	static int	save = 0;

	if (a == 0)
		a = save;
	if (save == 0)
		a = 1;
	refresh_norm(data);
	if (a == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->anim.walkr[i % 10].img_ptr, data->anim.pos_x,
			data->anim.pos_y);
	else if (a == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->anim.idler[i % 10].img_ptr, data->anim.pos_x,
			data->anim.pos_y + data->height / 9);
	else if (a == 3)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->anim.dead[i % 10].img_ptr, data->anim.pos_x,
			data->anim.pos_y + data->height / 4.5);
	save = a;
}

void	menu(t_data *data)
{
	static time_t	t0 = 0;
	static int		i = 0;

	data->anim.pos_x = data->width / 3.473945409;
	data->anim.pos_y = data->height / 2.686567164;
	data->anim.cube_pos_x = data->width / 3.79403794;
	data->anim.cube_pos_y = data->height / 7.96460177;
	data->anim.exc_pos_x = data->width / 1.166666667;
	data->anim.exc_pos_y = data->height / 4;
	if (get_time() - t0 > 50)
	{
		i++;
		t0 = get_time();
	}
	menu_norm(data, &i);
}

int	render(t_data *data)
{
	mlx_mouse_get_pos(data->mlx_ptr, data->mlx_win,
		&data->mouse.x, &data->mouse.y);
	if (!data->game_launched)
	{
		if (data->anim.step != 5)
			load_screen(data);
		else
			menu(data);
		data->t0 = get_time();
	}
	else if (data->win == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->win_screen.img_ptr, 0, 0);
	else if (data->player.stats.hp > 0)
	{
		init_fight(data);
		(move_player(data), open_door(data, NULL), close_door(data, NULL));
		(explosion(NULL), mouse_rotate(data), render_raycast(data));
	}
	else if (data->player.stats.hp == -1000)
		time_s_out(data);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->player.death.img_ptr, 0, 0);
	return (0);
}
