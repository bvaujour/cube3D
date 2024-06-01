/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:37:29 by mablatie          #+#    #+#             */
/*   Updated: 2024/01/23 14:39:47 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"
#include "../lib/test.h"

void	end_norm(t_data *data)
{
	int	i;

	i = -1;
	if (data->config)
	{
		while (data->config[++i])
			free(data->config[i]);
		free(data->config);
	}
	if (data->i.map)
	{
		i = -1;
		while (data->i.map[++i])
			free(data->i.map[i]);
		free(data->i.map);
	}
}
