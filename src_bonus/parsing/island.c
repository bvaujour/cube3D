/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   island.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:59:47 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/23 13:43:27 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"
#include "../../lib/test.h"

static void	fill(t_data *data, char **tab, t_vector size, t_vector cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0
		|| cur.x >= size.x || tab[cur.y][cur.x] == 'F'
		|| tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == '2')
		return ;
	if (tab[cur.y][cur.x] != ' ' && tab[cur.y][cur.x] != '1'
		&& tab[cur.y][cur.x] != '2')
	{
		ft_dprintf(2, "Error, the map is not closed\n");
		clean_exit(data, 0);
	}
	tab[cur.y][cur.x] = 'F';
	fill(data, tab, size, (t_vector){cur.x - 1, cur.y});
	fill(data, tab, size, (t_vector){cur.x + 1, cur.y});
	fill(data, tab, size, (t_vector){cur.x, cur.y - 1});
	fill(data, tab, size, (t_vector){cur.x, cur.y + 1});
}

static void	flood(t_data *data)
{
	t_vector	start;
	t_vector	limit;

	start.x = 0;
	start.y = 0;
	limit.x = ft_strlen(data->i.island[0]);
	limit.y = data->i.island_y;
	fill(data, data->i.island, limit, start);
}
// TITLE("begin of flood fill"); // debug

static void	water(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->i.map[++i])
		data->i.island_x = longest_str(data->i.map[i]) + 2;
	data->i.island_y = i + 2;
	data->i.island = malloc(sizeof(char *) * (data->i.island_y + 1));
	if (!data->i.island)
		(ft_dprintf(2, "Error, allocation\n"), end(data));
	i = -1;
	while (++i < data->i.island_y)
	{
		j = -1;
		data->i.island[i] = malloc(sizeof(char) * (data->i.island_x + 1));
		if (!data->i.island[i])
			(ft_dprintf(2, "Error, allocation\n"), end(data));
		while (++j < data->i.island_x)
			data->i.island[i][j] = ' ';
		data->i.island[i][j] = '\0';
	}
	data->i.island[i] = NULL;
}
// TITLE("begin of water"); // debug

static void	put_earth(char *earth, char *water)
{
	int	i;

	i = 0;
	while (earth[i])
	{
		water[i + 1] = earth[i];
		i++;
	}
}
// TITLE("begin of put_earth"); // debug

void	island(t_data *data)
{
	int	i;

	i = 0;
	water(data);
	while (data->i.map[i])
	{
		put_earth(data->i.map[i], data->i.island[i + 1]);
		i++;
	}
	flood(data);
}
// TITLE("begin of island"); // debug