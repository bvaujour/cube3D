/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:40:16 by mablatie          #+#    #+#             */
/*   Updated: 2024/01/23 14:42:50 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d_bonus.h"
#include "../lib/test.h"

void	end_norm(t_data *data)
{
	int	i;

	i = 0;
	if (data->config)
	{
		while (data->config[i])
			free(data->config[i++]);
		free(data->config);
	}
	i = 0;
	if (data->i.map)
	{
		while (data->i.map[i])
			free(data->i.map[i++]);
		free(data->i.map);
	}
}
