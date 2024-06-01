/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanitas <vanitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:01:54 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/09 15:08:19 by vanitas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	init_cat_stats(t_data *data)
{
	data->anim.pos_x = 0;
	data->anim.pos_y = data->height / 4 - data->anim.walkr[0].height;
	data->anim.cube_pos_x = data->width - data->anim.walkr[0].width
		- data->anim.cube.width;
	data->anim.cube_pos_y = data->height / 4 - data->anim.cube.height;
	data->anim.exc_pos_x = data->width / 2 + data->anim.cube.width / 1.4;
	data->anim.exc_pos_y = 0;
}

void	clean_anim(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 10)
	{
		if (i < 5 && data->player.gun[i].img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->player.gun[i].img_ptr);
		if (i < 6 && data->anim.runl[i].img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->anim.runl[i].img_ptr);
		if (data->anim.dead[i].img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->anim.dead[i].img_ptr);
		if (data->anim.push[i].img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->anim.push[i].img_ptr);
		if (data->anim.walkr[i].img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->anim.walkr[i].img_ptr);
		if (data->anim.idler[i].img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->anim.idler[i].img_ptr);
	}
	mlx_destroy_image(data->mlx_ptr, data->anim.blank.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->anim.start.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->anim.settings.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->anim.exit.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->anim.cube.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->anim.exc.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->anim.jumpl.img_ptr);
}

int	fall2(t_data *data, int jump_x, int jump_y)
{
	static int		i = 0;
	static int		gravity = 4;

	if (data->anim.pos_y + i * i / gravity <= data->height / 2
		- data->anim.walkr[0].height)
	{
		data->anim.pos_x += jump_x;
		data->anim.pos_y -= jump_y;
		data->anim.bg = new_img(data, data->width, data->height, NULL);
		put_img_to_img(&data->anim.bg, &data->anim.cube, data->anim.cube_pos_x,
			data->anim.cube_pos_y);
		reverse_put_img_to_img(&data->anim.bg, &data->anim.exc,
			data->anim.exc_pos_x, data->anim.exc_pos_y);
		put_img_to_img(&data->anim.bg, &data->anim.jumpl,
			data->anim.pos_x, data->anim.pos_y + i * i / gravity);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->anim.bg.img_ptr, 0, 0);
		mlx_destroy_image(data->mlx_ptr, data->anim.bg.img_ptr);
		data->anim.pos_y += i * i / gravity;
		i++;
		usleep(8000);
		return (0);
	}
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	return (1);
}

time_t	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	bounce_norm(t_data *data, int v_y, int *i, int *j)
{
	data->anim.bg = new_img(data, data->width, data->height, NULL);
	put_img_to_img(&data->anim.bg, &data->anim.cube, data->anim.cube_pos_x,
		data->anim.cube_pos_y);
	put_img_to_img(&data->anim.bg, &data->anim.idler[(*j) % 10],
		data->anim.pos_x, data->anim.pos_y);
	reverse_put_img_to_img(&data->anim.bg, &data->anim.exc,
		data->anim.exc_pos_x, data->anim.exc_pos_y
		+ (*i) * v_y + (*i) * (*i) / 4);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->anim.bg.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->anim.bg.img_ptr);
	usleep(5000);
}
