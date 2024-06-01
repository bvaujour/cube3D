/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HUD_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanitas <vanitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:33:24 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/09 14:58:22 by vanitas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	hit_react(t_data *data, t_img *img)
{
	static time_t	t0 = 0;

	if (!data->player.hited)
		return ;
	screen_shake(data);
	if (data->player.punched)
		put_img_to_img(img, &data->all_enemies_anim.ter_attack, 0, 0);
	if (get_time() - t0 > 70)
		data->player.hited++;
	if (data->player.hited == 11)
	{
		data->player.punched = 0;
		data->player.hited = 0;
	}
}

void	chipset(t_data *data, t_img *img)
{
	t_img	num;
	char	*path;

	if (data->player.chipset > 3)
		data->player.chipset = 3;
	path = ft_strjoin(ft_itoa(data->player.chipset), ".xpm", 1);
	path = ft_strjoin("textures/nombres/", path, 2);
	num = new_img(data, data->width / 30, data->height / 18, path);
	if (data->player.chipset < 3)
		change_color(&num, 0x000000, 0xFFFFFF, 0);
	else
		change_color(&num, 0x000000, 0x29a73c, 0);
	put_img_to_img(img, &num, data->width / 9, data->height
		- num.height - data->height / 60);
	mlx_destroy_image(data->mlx_ptr, num.img_ptr);
	free(path);
}

void	objective(t_data *data, t_img *img)
{
	put_img_to_img(img, &data->player.obj1, 3, data->height / 4);
}

void	second_norm(t_data *data, t_img *chrono, int time, t_img *img_nb)
{
	if (time < 60000)
		change_color(img_nb, 0x000000, 0x7F0000, 0);
	else
		change_color(img_nb, 0x000000, 0x007F00, 0);
	put_img_to_img(chrono, img_nb, img_nb->width, 0);
	mlx_destroy_image(data->mlx_ptr, img_nb->img_ptr);
}

void	weapon_norm(t_data *data, int *i, int *incr)
{
	if (*i > data->player.gun[0].height / 17 && !data->player.is_firing)
	{
		*i = data->player.gun[0].height / 17;
		*incr = -1;
	}
	else if (*i < 0 && !data->player.is_firing)
	{
		*i = 0;
		*incr = 1;
	}
}
