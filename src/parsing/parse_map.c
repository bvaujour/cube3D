/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:44:33 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/18 13:48:12 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"
#include "../../lib/test.h"

static int	allowed_char(t_data *data, char *str)
{
	int	i;
	int	nb_hero;

	nb_hero = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'N' && str[i] != 'S'
			&& str[i] != 'E' && str[i] != 'W' && str[i] != ' ')
			error_map(data);
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
		{
			nb_hero++;
			data->player.dir = str[i];
		}
		i++;
	}
	return (nb_hero);
}

static void	check_char(t_data *data)
{
	int	i;
	int	nb_hero;

	nb_hero = 0;
	i = 0;
	while (data->i.map[i])
	{
		nb_hero += allowed_char(data, data->i.map[i]);
		i++;
	}
	if (nb_hero != 1)
		error_map(data);
}

// static void	replace_player_wall(t_data *data)

void	parse_map(t_data *data)
{
	check_char(data);
	island(data);
}
