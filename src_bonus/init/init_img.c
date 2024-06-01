/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 01:30:12 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/29 14:16:36 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	init_img_nullifier_loop(t_data *data, int i)
{
	if (i < 11)
	{
		init_img_clean(&data->all_enemies_anim.dino_attack[i]);
		init_img_clean(&data->player.reload[i]);
	}
	if (i < 10)
	{
		init_img_clean(&data->anim.dead[i]);
		init_img_clean(&data->anim.walkr[i]);
		init_img_clean(&data->anim.idler[i]);
		init_img_clean(&data->anim.push[i]);
		init_img_clean(&data->time_out[i]);
	}
	if (i < 6)
	{
		init_img_clean(&data->all_enemies_anim.ter_walk[i]);
		init_img_clean(&data->anim.runl[i]);
		init_img_clean(&data->all_enemies_anim.dino_roar[i]);
		init_img_clean(&data->player.face[i]);
	}
}

void	init_img_nullifier_2(t_data *data)
{
	init_img_clean(&data->anim.blank);
	init_img_clean(&data->anim.exc);
	init_img_clean(&data->anim.start);
	init_img_clean(&data->anim.settings);
	init_img_clean(&data->anim.jumpl);
	init_img_clean(&data->all_enemies_anim.ter_attack);
	init_img_clean(&data->player.hud);
	init_img_clean(&data->player.bullets);
	init_img_clean(&data->player.death);
	init_img_clean(&data->mars);
	init_img_clean(&data->moon);
	init_img_clean(&data->earth);
	init_img_clean(&data->puce);
	init_img_clean(&data->heal);
	init_img_clean(&data->player.obj1);
	init_img_clean(&data->win_screen);
	init_img_clean(&data->load);
}

void	init_img_nullifier(t_data *data)
{
	int	i;

	i = 0;
	init_img_nullifier_2(data);
	while (i < 21)
	{
		init_img_clean(&data->textures2[i]);
		init_img_nullifier_loop(data, i);
		if (i < 5)
		{
			init_img_clean(&data->player.gun[i]);
			init_img_clean(&data->all_enemies_anim.dino_walk[i]);
		}
		if (i < 4)
			init_img_clean(&data->all_enemies_anim.shiplr[i]);
		i++;
	}
}

void	set_anim(t_data *data, t_anim *intro)
{
	int	size;

	size = 15;
	data->anim.step = 0;
	intro->exc = new_img(data, data->width / 28, data->height / 8,
			"textures/exc2.xpm");
	intro->start = new_img(data, data->width / 7, data->height / 18,
			"textures/start.xpm");
	intro->settings = new_img(data, data->width / 4.7, data->height / 18,
			"textures/settings.xpm");
	intro->exit = new_img(data, data->width / 7, data->height / 18,
			"textures/exit.xpm");
	intro->cube = new_img(data, data->width / 2, data->height / 8,
			"textures/cube2.xpm");
	set_anim_2(data, intro, size);
	set_anim_3(data, intro, size);
	set_anim_4(data, intro, size);
	set_anim_5(data, intro, size);
	set_anim_6(data, intro, size);
}

void	init_fight(t_data *data)
{
	static time_t	end = 0;

	data->player.orient = data->player.rotate;
	if (data->win == 1 && get_time() - end > 7000)
		data->win = 2;
	data->player.aiming_at = NULL;
	if (data->win == false && data->player.pos_x >= data->ship[0].pos_x - 8
		&& data->player.pos_y >= data->ship[0].pos_y - 8
		&& data->player.chipset >= 3)
	{
		end = get_time();
		data->win = 1;
	}
	if (data->win == 1)
	{
		data->ship[0].fly += 5;
		data->ship[0].stats.ms += 0.05;
	}
}
