/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:46:40 by mablatie          #+#    #+#             */
/*   Updated: 2024/01/29 13:58:56 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	clean_norm(t_data *data, int i)
{
	if (i < 4 && data->all_enemies_anim.shiplr[i].img_ptr)
		mlx_destroy_image(data->mlx_ptr,
			data->all_enemies_anim.shiplr[i].img_ptr);
	if (i < 6 && data->all_enemies_anim.ter_walk[i].img_ptr)
		mlx_destroy_image(data->mlx_ptr,
			data->all_enemies_anim.ter_walk[i].img_ptr);
	if (i < 6 && data->all_enemies_anim.dino_roar[i].img_ptr)
		mlx_destroy_image(data->mlx_ptr,
			data->all_enemies_anim.dino_roar[i].img_ptr);
	if (i < 5 && data->all_enemies_anim.dino_walk[i].img_ptr)
		mlx_destroy_image(data->mlx_ptr,
			data->all_enemies_anim.dino_walk[i].img_ptr);
	if (data->all_enemies_anim.dino_attack[i].img_ptr)
		mlx_destroy_image(data->mlx_ptr,
			data->all_enemies_anim.dino_attack[i].img_ptr);
	if (data->player.reload[i].img_ptr)
		mlx_destroy_image(data->mlx_ptr,
			data->player.reload[i].img_ptr);
	if (i < 10 && data->time_out[i].img_ptr)
		mlx_destroy_image(data->mlx_ptr,
			data->time_out[i].img_ptr);
}

static void	clean_norm_3(t_data *data)
{
	if (data->mars.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->mars.img_ptr);
	if (data->moon.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->moon.img_ptr);
	if (data->earth.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->earth.img_ptr);
	if (data->player.hud.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->player.hud.img_ptr);
	if (data->player.bullets.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->player.bullets.img_ptr);
	if (data->player.death.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->player.death.img_ptr);
	if (data->puce.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->puce.img_ptr);
	if (data->heal.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->heal.img_ptr);
	if (data->player.obj1.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->player.obj1.img_ptr);
}

void	clean_norm_2(t_data *data)
{
	if (data->all_enemies_anim.ter_attack.img_ptr)
		mlx_destroy_image(data->mlx_ptr,
			data->all_enemies_anim.ter_attack.img_ptr);
	if (data->load.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->load.img_ptr);
	if (data->enemies)
		free(data->enemies);
	if (data->win_screen.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->win_screen.img_ptr);
	clean_norm_3(data);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		mlx_loop_end(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free_textures(&data->i);
}

int	quit_cub3d(t_data *data)
{
	clean_exit(data, 0);
	return (0);
}
