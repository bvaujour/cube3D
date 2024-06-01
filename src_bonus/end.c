/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:38:00 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/23 14:42:08 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d_bonus.h"
#include "../lib/test.h"

int	err_msg(char *str)
{
	ft_dprintf(2, str);
	return (0);
}

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

void	free_textures(t_info *i)
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

void	end(t_data *data)
{
	int	i;

	i = 0;
	free(data->wall_dist);
	end_norm(data);
	if (data->i.mapcopy)
	{
		while (data->i.mapcopy[i])
			free(data->i.mapcopy[i++]);
		free(data->i.mapcopy);
	}
	if (data->i.island)
	{
		i = 0;
		while (data->i.island[i])
			free(data->i.island[i++]);
		free(data->i.island);
	}
	exit(0);
}

void	clean_exit(t_data *data, int code)
{
	int	i;

	if (!data)
		exit(code);
	if (data->anim.alloced == true)
		clean_anim(data);
	if (data->mlx_win && data->mlx_ptr)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	i = 0;
	while (i < 21)
	{
		if (data->textures2[i].img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->textures2[i].img_ptr);
		if (i < 5 && data->player.face[i].img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->player.face[i].img_ptr);
		i++;
	}
	i = -1;
	while (++i < 11)
		clean_norm(data, i);
	clean_norm_2(data);
	if (data->texture_pixels)
		free_tab((void **)data->texture_pixels);
	end(data);
}
