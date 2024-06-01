/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:38:00 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/23 14:39:27 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"
#include "../lib/test.h"

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

static void	free_textures(t_info *i)
{
	if (i->no)
		free(i->no);
	if (i->so)
		free(i->so);
	if (i->we)
		free(i->we);
	if (i->ea)
		free(i->ea);
	if (i->floor)
		free(i->floor);
	if (i->ciel)
		free(i->ciel);
}

int	end(t_data *data)
{
	int	i;

	i = 0;
	end_norm(data);
	if (data->i.island)
	{
		while (data->i.island[i])
			free(data->i.island[i++]);
		free(data->i.island);
	}
	if (data->textures)
		free_tab((void **)data->textures);
	if (data->texture_pixels)
		free_tab((void **)data->texture_pixels);
	return (free_textures(&data->i), exit(0), 0);
}

void	clean_exit(t_data *data, int code)
{
	if (!data)
		exit(code);
	if (data->mlx_win && data->mlx_ptr)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		mlx_loop_end(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	end(data);
	exit(code);
}

int	quit_cub3d(t_data *data)
{
	clean_exit(data, 0);
	return (0);
}
