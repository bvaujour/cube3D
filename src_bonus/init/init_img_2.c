/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanitas <vanitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:27:09 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/24 12:19:01 by vanitas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	set_anim_2(t_data *data, t_anim *intro, int size)
{
	intro->dead[0] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/dead0.xpm");
	intro->dead[1] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/dead1.xpm");
	intro->dead[2] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/dead2.xpm");
	intro->dead[3] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/dead3.xpm");
	intro->dead[4] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/dead4.xpm");
	intro->dead[5] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/dead5.xpm");
	intro->dead[6] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/dead6.xpm");
	intro->dead[7] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/dead7.xpm");
	intro->dead[8] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/dead8.xpm");
	intro->dead[9] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/dead9.xpm");
}

void	set_anim_3(t_data *data, t_anim *intro, int size)
{
	intro->walkr[0] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/walkr0.xpm");
	intro->walkr[1] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/walkr1.xpm");
	intro->walkr[2] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/walkr2.xpm");
	intro->walkr[3] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/walkr3.xpm");
	intro->walkr[4] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/walkr4.xpm");
	intro->walkr[5] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/walkr5.xpm");
	intro->walkr[6] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/walkr6.xpm");
	intro->walkr[7] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/walkr7.xpm");
	intro->walkr[8] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/walkr8.xpm");
	intro->walkr[9] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/walkr9.xpm");
}

void	set_anim_4(t_data *data, t_anim *intro, int size)
{
	intro->idler[0] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/idle0.xpm");
	intro->idler[1] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/idle1.xpm");
	intro->idler[2] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/idle2.xpm");
	intro->idler[3] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/idle3.xpm");
	intro->idler[4] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/idle4.xpm");
	intro->idler[5] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/idle5.xpm");
	intro->idler[6] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/idle6.xpm");
	intro->idler[7] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/idle7.xpm");
	intro->idler[8] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/idle8.xpm");
	intro->idler[9] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/idle9.xpm");
}

void	set_anim_5(t_data *data, t_anim *intro, int size)
{
	intro->push[0] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/push0.xpm");
	intro->push[1] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/push1.xpm");
	intro->push[2] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/push2.xpm");
	intro->push[3] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/push3.xpm");
	intro->push[4] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/push4.xpm");
	intro->push[5] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/push5.xpm");
	intro->push[6] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/push6.xpm");
	intro->push[7] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/push7.xpm");
	intro->push[8] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/push8.xpm");
	intro->push[9] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/push9.xpm");
}

void	set_anim_6(t_data *data, t_anim *intro, int size)
{
	intro->runl[0] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/runl1.xpm");
	intro->runl[1] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/runl2.xpm");
	intro->runl[2] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/runl3.xpm");
	intro->runl[3] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/runl4.xpm");
	intro->runl[4] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/runl5.xpm");
	intro->runl[5] = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/runl6.xpm");
	intro->jumpl = new_img(data, data->width / size, data->width / size,
			"textures/cat/anim/jumpl.xpm");
	intro->blank.img_ptr = mlx_new_image(data->mlx_ptr, intro->idler[0].width,
			intro->idler[0].height * 4);
	if (!intro->blank.img_ptr)
		clean_exit(data, 1);
	intro->blank.addr = (int *)mlx_get_data_addr(intro->blank.img_ptr,
			&intro->blank.bits_per_pixel, &intro->blank.line_length,
			&intro->blank.endian);
	intro->blank.width = intro->idler[0].width;
	intro->blank.height = intro->idler[0].height * 4;
	intro->alloced = true;
}
