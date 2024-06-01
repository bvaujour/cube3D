/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanitas <vanitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:44:29 by mablatie          #+#    #+#             */
/*   Updated: 2024/01/15 15:25:47 by vanitas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	pos_neg(void)
{
	if (rand() % 2)
		return (-1);
	return (1);
}

void	protect_textures(t_data *data)
{
	if (!data->textures2[DOOR].img_ptr || !data->textures2[DOOR_OPEN0].img_ptr
		|| !data->textures2[DOOR_OPEN1].img_ptr)
		clean_exit(data, 0);
}
