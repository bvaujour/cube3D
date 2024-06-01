/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanitas <vanitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:39:30 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/09 14:13:16 by vanitas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

t_sprite	*order_enemy(t_data *data, t_sprite *enemies, int nb_enemies)
{
	t_sprite	*new;
	t_order		norm;

	norm.i = -1;
	while (++norm.i < nb_enemies - 1)
		if (enemies[norm.i].distance < enemies[norm.i + 1].distance)
			break ;
	if (norm.i == nb_enemies - 1)
		return (enemies);
	new = malloc(sizeof(t_sprite) * nb_enemies);
	if (!new)
		clean_exit(data, 0);
	norm.i = -1;
	norm.j = -1;
	norm.count = 0;
	order_enemy_norm(enemies, new, nb_enemies, &norm);
	free(enemies);
	return (new);
}

double	calculate_sprite_distance(t_data *data, double sprite_x,
	double sprite_y)
{
	double	delta_x;
	double	delta_y;
	double	dist;

	delta_x = sprite_x - data->player.pos_x;
	delta_y = sprite_y - data->player.pos_y;
	dist = delta_x * delta_x + delta_y * delta_y;
	return (dist);
}

void	chase_player(t_data *data, t_sprite *enemy)
{
	int	length;

	length = sqrt(enemy->dir_x * enemy->dir_x + enemy->dir_y * enemy->dir_y);
	if (length != 0)
	{
		enemy->dir_x /= length;
		enemy->dir_y /= length;
	}
	validate_enemies_move(data, enemy, enemy->dir_x, enemy->dir_y);
}

void	attack(t_data *data, t_sprite *enemy)
{
	if (enemy->dir_x >= -enemy->range && enemy->dir_x <= enemy->range
		&& enemy->dir_y >= -enemy->range && enemy->dir_y <= enemy->range)
	{
		enemy->in_range = true;
		if (enemy->attacking == true
			&& get_time() - enemy->last_move < enemy->stats.as)
			return ;
		enemy->steptime = get_time();
		enemy->last_move = get_time();
		enemy->attacking = true;
		if (enemy->c == 'Z')
		{
			update_health_point(data, &data->player.stats, -enemy->stats.dmg);
			data->player.punched = 1;
		}
		else if (enemy->c == 'X')
		{
			enemy->steptick = 0;
			enemy->motion = data->all_enemies_anim.dino_attack;
			enemy->stats.ms = 0.05;
		}
	}
	else
		enemy->in_range = false;
}

void	roar(t_sprite *enemy)
{
	if (enemy->steptick == 1)
		enemy->incr = -1;
	else if (enemy->steptick == 0)
		enemy->incr = 1;
	if (get_time() - enemy->steptime > (rand() % 100) + 100)
	{
		enemy->steptick += enemy->incr;
		enemy->steptime = get_time();
	}
}
