/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanitas <vanitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:26:26 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/09 16:55:25 by vanitas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"
#include "../../lib/test.h"

// static void	check_texture(t_data *data)
// {
// 	int	fd;

// 	fd = open(data->i.no, O_RDONLY);
// 	if (fd == -1)
// 		end(data);
// 	close(fd);
// 	fd = open(data->i.so, O_RDONLY);
// 	if (fd == -1)
// 		end(data);
// 	close(fd);
// 	fd = open(data->i.ea, O_RDONLY);
// 	if (fd == -1)
// 		end(data);
// 	close(fd);
// 	fd = open(data->i.we, O_RDONLY);
// 	if (fd == -1)
// 		end(data);
// 	close(fd);
// }

static void	check_colors_ciel(t_data *data)
{
	char	**tab;
	int		i;

	i = -1;
	tab = ft_split(data->i.ciel, ',');
	if (!tab)
		error_alloc(data);
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

static void	check_colors_floor(t_data *data)
{
	char	**tab;
	int		i;

	i = -1;
	tab = ft_split(data->i.floor, ',');
	if (!tab)
		error_alloc(data);
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

void	parse_info(t_data *data)
{
	check_colors_floor(data);
	check_colors_ciel(data);
}
