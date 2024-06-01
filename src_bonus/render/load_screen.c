/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanitas <vanitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:59:40 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/09 15:06:05 by vanitas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

int	push(t_data *data, int to, int speed)
{
	static time_t	t0 = 0;
	static int		i = 0;

	if (data->anim.pos_x > to && data->anim.pos_x >= 0 && data->anim.pos_x
		<= data->width - data->anim.walkr->width)
	{
		data->anim.bg = new_img(data, data->width, data->height, NULL);
		if ((get_time() - t0) > 75)
		{
			t0 = get_time();
			i++;
		}
		put_img_to_img(&data->anim.bg, &data->anim.push[i % 10],
			data->anim.pos_x, data->anim.pos_y);
		put_img_to_img(&data->anim.bg, &data->anim.cube, data->anim.cube_pos_x,
			data->anim.cube_pos_y);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->anim.bg.img_ptr, 0, 0);
		data->anim.pos_x -= speed;
		data->anim.cube_pos_x -= speed;
		mlx_destroy_image(data->mlx_ptr, data->anim.bg.img_ptr);
		return (0);
	}
	return (1);
}

int	walk(t_data *data, int to, int speed)
{
	static time_t	t0 = 0;
	static int		i = 0;

	if (data->anim.pos_x != to && data->anim.pos_x >= 0 && data->anim.pos_x
		<= data->width - data->anim.walkr->width)
	{
		data->anim.bg = new_img(data, data->width, data->height, NULL);
		if ((get_time() - t0) > 75)
		{
			t0 = get_time();
			i++;
		}
		put_img_to_img(&data->anim.bg, &data->anim.walkr[i % 10],
			data->anim.pos_x, data->anim.pos_y);
		put_img_to_img(&data->anim.bg, &data->anim.cube, data->anim.cube_pos_x,
			data->anim.cube_pos_y);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->anim.bg.img_ptr, 0, 0);
		data->anim.pos_x += speed;
		mlx_destroy_image(data->mlx_ptr, data->anim.bg.img_ptr);
		return (0);
	}
	return (1);
}

int	bounce(t_data *data, int v_y)
{
	static int		i = 1;
	static int		j = 0;
	static time_t	t0 = 0;

	if (data->anim.exc_pos_y > data->anim.exc_pos_y + i * v_y + i * i / 4)
	{
		if ((get_time() - t0) > 35)
		{
			t0 = get_time();
			j++;
		}
		bounce_norm(data, v_y, &i, &j);
		i++;
		return (0);
	}
	data->anim.exc_pos_y = data->height / 4;
	return (1);
}

int	chute(t_data *data)
{
	static time_t	t0 = 0;
	static int		i = 0;

	if (data->anim.exc_pos_y < data->anim.cube_pos_y + data->anim.cube.height)
	{
		if ((get_time() - t0) > 35)
		{
			t0 = get_time();
			i++;
		}
		data->anim.bg = new_img(data, data->width, data->height, NULL);
		put_img_to_img(&data->anim.bg, &data->anim.cube, data->anim.cube_pos_x,
			data->anim.cube_pos_y);
		put_img_to_img(&data->anim.bg, &data->anim.runl[i % 6],
			data->anim.pos_x, data->anim.pos_y);
		reverse_put_img_to_img(&data->anim.bg, &data->anim.exc,
			data->anim.exc_pos_x, data->anim.exc_pos_y);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->anim.bg.img_ptr, 0, 0);
		mlx_destroy_image(data->mlx_ptr, data->anim.bg.img_ptr);
		data->anim.pos_x -= 5;
		data->anim.exc_pos_y += 10;
		return (0);
	}
	return (1);
}

void	load_screen(t_data *data)
{
	data->game_launched = false;
	if (data->anim.step == 0)
		data->anim.step += walk(data, data->width
				- data->anim.walkr[0].width * 1.2, 2);
	else if (data->anim.step == 1)
		data->anim.step += push(data, data->width / 2
				+ data->anim.cube.width / 2, 1);
	else if (data->anim.step == 2)
		data->anim.step += chute(data);
	else if (data->anim.step == 3)
		data->anim.step += bounce(data, -data->height / 100);
	else if (data->anim.step == 4)
		data->anim.step += fall2(data, -data->width / 36, 0);
}
