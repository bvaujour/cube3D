/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:05:32 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/18 14:18:32 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

static int	key_press_handler_bis(int key, t_data *data)
{
	key_press_handler_bis_2(key, data);
	if (key == 32 && !data->player.teleporting)
		data->player.teleporting = 1;
	else if (key == XK_w || key == XK_Up)
		data->player.move_y = 1;
	else if (key == XK_a)
		data->player.move_x = -1;
	else if (key == XK_s || key == XK_Down)
		data->player.move_y = -1;
	else if (key == XK_d)
		data->player.move_x = 1;
	else if (key == 114 && data->player.nb_bullets < 6
		&& data->player.is_firing == 0 && data->player.reloading == false)
		data->player.reloading = true;
	return (0);
}

static int	key_press_handler(int key, t_data *data)
{
	if (key == 65436)
		data->test -= 0.1;
	else if (key == 65433)
		data->test += 0.1;
	else if (key == 65430)
		data->test -= 1;
	else if (key == 65437)
		data->test += 1;
	else if (key == XK_Escape && data->anim.step == 5)
		quit_cub3d(data);
	else if (data->anim.step != 5)
	{
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		data->anim.step = 5;
	}
	else if (key == XK_Left)
		data->player.rotate -= 3;
	else if (key == XK_Right)
		data->player.rotate += 3;
	else
		key_press_handler_bis(key, data);
	return (0);
}

static int	handle_mouse_bis(int button, t_data *data)
{
	if (!data->game_launched && data->mouse.y > data->height / 2
		+ 2 * data->height / 9 - data->anim.start.height * 1.3 && data->mouse.y
		< data->height / 2 + 2 * data->height / 9 - data->anim.start.height
		* 1.3 + data->anim.exit.height && data->mouse.x > data->width / 2
		- data->anim.start.width && data->mouse.x < data->width / 2
		- data->anim.start.width + data->anim.exit.width)
		quit_cub3d(data);
	else if (data->game_launched && button == 1 && data->player.is_firing == 0)
		fire(data);
	else if (data->game_launched && button == 3)
		handle_mouse_bis_2(data);
	return (0);
}

static int	handle_mouse(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (data->anim.step != 5)
	{
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		data->anim.step = 5;
	}
	if (!data->game_launched && data->mouse.y > data->height / 2
		- data->anim.start.height * 1.3 && data->mouse.y < data->height
		/ 2 - data->anim.start.height * 1.3 + data->anim.start.height
		&& data->mouse.x > data->width / 2 - data->anim.start.width
		&& data->mouse.x < data->width / 2)
		data->game_launched = true;
	else if (!data->game_launched && data->mouse.y > data->height / 2
		+ data->height / 9 - data->anim.start.height * 1.3
		&& data->mouse.y < data->height / 2 + data->height / 9
		- data->anim.start.height * 1.3 + data->anim.settings.height
		&& data->mouse.x > data->width / 2 - data->anim.start.width
		&& data->mouse.x < data->width / 2 - data->anim.start.width
		+ data->anim.settings.width)
		printf("hello\n");
	else
		handle_mouse_bis(button, data);
	return (0);
}

void	listen_for_input(t_data *data)
{
	mlx_mouse_hook(data->mlx_win, handle_mouse, data);
	mlx_hook(data->mlx_win, ClientMessage, NoEventMask, quit_cub3d, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, key_press_handler, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask,
		key_release_handler, data);
}
