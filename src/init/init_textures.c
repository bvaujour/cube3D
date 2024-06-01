/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanitas <vanitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:59:29 by vanitas           #+#    #+#             */
/*   Updated: 2023/11/17 17:58:07 by vanitas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static int	*xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1, sizeof * buffer * data->i.size * data->i.size);
	if (!buffer)
		clean_exit(data, err_msg(ERR_MALLOC));
	y = 0;
	while (y < data->i.size)
	{
		x = 0;
		while (x < data->i.size)
		{
			buffer[y * data->i.size + x] = tmp.addr[y * data->i.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx_ptr, tmp.img_ptr);
	return (buffer);
}

void	init_textures(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		clean_exit(data, err_msg(ERR_MALLOC));
	data->textures[NORTH] = xpm_to_img(data, data->i.no);
	data->textures[SOUTH] = xpm_to_img(data, data->i.so);
	data->textures[EAST] = xpm_to_img(data, data->i.ea);
	data->textures[WEST] = xpm_to_img(data, data->i.we);
}
