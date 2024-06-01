/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   island.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:59:47 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/23 19:36:07 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"
#include "../../lib/test.h"

static void	fill(t_data *data, char **tab, t_vector size, t_vector cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0
		|| cur.x >= size.x || tab[cur.y][cur.x] == 'F'
			|| tab[cur.y][cur.x] == '1')
		return ;
	if (tab[cur.y][cur.x] != ' ' && tab[cur.y][cur.x] != '1')
	{
		ft_dprintf(2, "Error, the map is not closed\n");
		end(data);
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
	limit.y = data->i.map_line + 2;
	fill(data, data->i.island, limit, start);
}

static void	water(t_data *data)
{
	int	i;
	int	j;
	int	longest;

	i = -1;
	while (data->i.map[++i])
		longest = longest_str(data->i.map[i]) + 2;
	data->i.map_line = i;
	data->i.map_h = i;
	data->i.map_w = longest - 1;
	data->i.island = malloc(sizeof(char *) * (i + 3));
	if (!data->i.island)
		error_alloc(data);
	i = -1;
	while (++i < data->i.map_line + 2)
	{
		j = -1;
		data->i.island[i] = malloc(sizeof(char) * (longest + 1));
		if (!data->i.island[i])
			return (error_alloc(data));
		while (++j < longest)
			data->i.island[i][j] = ' ';
		data->i.island[i][j] = '\0';
	}
	data->i.island[i] = NULL;
}

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

void	island(t_data *data)
{
	int	i;

	i = 0;
	water(data);
	while (data->i.map[i])
	{
		printf("%s\n", data->i.map[i]);
		put_earth(data->i.map[i], data->i.island[i + 1]);
		i++;
	}
	i = 0;
	while (data->i.island[i])
	{
		printf("%s\n", data->i.island[i]);
		i++;
	}
	flood(data);
}
