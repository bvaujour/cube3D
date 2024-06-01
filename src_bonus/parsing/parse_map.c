/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:44:33 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/19 19:19:31 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"
#include "../../lib/test.h"

static int	allowed_char(t_data *data, char *str)
{
	int	i;
	int	nb_hero;

	nb_hero = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != '2' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != '3' && str[i] != '4'
			&& str[i] != 'E' && str[i] != 'W' && str[i] != ' ' && str[i] != 'D'
			&& str[i] != 'L' && str[i] != 'M' && str[i] != 'Z' && str[i] != 'X')
			(ft_dprintf(2, "Error, format map\n"), clean_exit(data, 0));
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
		{
			nb_hero++;
			data->player.dir = str[i];
		}
		else if (str[i] == 'Z' || str[i] == 'X')
			data->nb_enemies++;
		i++;
	}
	return (nb_hero);
}
// TITLE("begin of allowed_char");

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
		(ft_dprintf(2, "Error, format map\n"), clean_exit(data, 0));
}
// TITLE("begin of check_char"); // debug

void	parse_map(t_data *data)
{
	check_char(data);
	island(data);
}
// TITLE("begin of parse map"); // debug