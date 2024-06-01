/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanitas <vanitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:19:52 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/08 14:22:09 by vanitas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

static void	restore_stamina(t_data *data)
{
	data->player.stats.stamina += 0.4;
	if (data->player.stats.stamina > 100)
		data->player.stats.stamina = 100;
}

void	upgrade_stamina(t_data *data)
{
	static float	base_ms = 0;
	static time_t	t = 0;
	static bool		is_out = 0;

	if (is_out == true && time(NULL) - t - 3 == 0)
	{
		is_out = false;
		data->player.stats.sprint = 0;
		data->player.stats.ms = base_ms;
	}
	if (data->player.stats.sprint && is_out == false)
	{
		data->player.stats.stamina -= 0.6;
		if (data->player.stats.stamina < 0)
		{
			data->player.stats.ms /= 2.5;
			base_ms = data->player.stats.ms;
			data->player.stats.ms = 0.01;
			data->player.stats.stamina = 0;
			is_out = true;
			t = time(NULL);
		}
	}
	else if (!data->player.stats.sprint && is_out == false)
		restore_stamina(data);
}
