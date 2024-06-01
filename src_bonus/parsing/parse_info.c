/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanitas <vanitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:26:26 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/09 17:04:30 by vanitas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"
#include "../../lib/test.h"

static void	check_colors_ciel(t_data *data)
{
	char	**tab;
	int		i;

	i = -1;
	tab = ft_split(data->i.ciel, ',');
	if (!tab)
		(ft_dprintf(2, "Error, allocation\n"), end(data));
	while (tab[++i])
		if (!isdigitstr(tab[i]) || ft_atoi(tab[i]) < 0 || ft_atoi(tab[i]) > 255)
			(ft_freetab((void **)tab),
				(ft_dprintf(2, "Error, color format\n"), end(data)));
	if (i != 3)
		(ft_freetab((void **)tab),
			(ft_dprintf(2, "Error, color format\n"), end(data)));
	data->i.r_ciel = ft_atoi(tab[0]);
	data->i.g_ciel = ft_atoi(tab[1]);
	data->i.b_ciel = ft_atoi(tab[2]);
	ft_freetab((void **)tab);
}
// TITLE("begin of check_color_ciel");

static void	check_colors_floor(t_data *data)
{
	char	**tab;
	int		i;

	i = -1;
	tab = ft_split(data->i.floor, ',');
	if (!tab)
		(ft_dprintf(2, "Error, allocation\n"), end(data));
	while (tab[++i])
		if (!isdigitstr(tab[i]) || ft_atoi(tab[i]) < 0 || ft_atoi(tab[i]) > 255)
			(ft_freetab((void **)tab),
				(ft_dprintf(2, "Error, color format\n"), end(data)));
	if (i != 3)
		(ft_freetab((void **)tab),
			(ft_dprintf(2, "Error, color format\n"), end(data)));
	data->i.r_floor = ft_atoi(tab[0]);
	data->i.g_floor = ft_atoi(tab[1]);
	data->i.b_floor = ft_atoi(tab[2]);
	ft_freetab((void **)tab);
}
// TITLE("begin of check_color_floor");

void	parse_info(t_data *data)
{
	check_colors_floor(data);
	check_colors_ciel(data);
}
// TITLE("begin of parse_info");