/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:34:11 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/29 14:08:14 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	put_img_to_img(t_img *dst, t_img *src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < src->width)
	{
		j = 0;
		while (j < src->height)
		{
			set_image_pixel(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}

void	change_color(t_img *img, int color_to_change, int new_color, int darken)
{
	int	x;
	int	y;

	y = -1;
	if (darken)
		new_color = (new_color >> 1) & 0x7f7f7f;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
			if (get_pixel_img(img, x, y) == color_to_change)
				set_image_pixel(img, x, y, new_color);
	}
}

t_img	new_img_xpm(t_data *data, char *path)
{
	t_img	new;

	init_img_clean(&new);
	new.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&new.width, &new.height);
	if (!new.img_ptr)
		clean_exit(data, 5);
	new.addr = (int *)mlx_get_data_addr(new.img_ptr,
			&new.bits_per_pixel, &new.line_length, &new.endian);
	return (new);
}

static void	new_img_norm(t_data *data, int width, int height, t_img *new)
{
	init_img_clean(new);
	new->img_ptr = mlx_new_image(data->mlx_ptr, width, height);
	if (!new->img_ptr)
		(ft_dprintf(2, "xpm failure\n"), clean_exit(data, 5));
	new->addr = (int *)mlx_get_data_addr(new->img_ptr, &new->bits_per_pixel,
			&new->line_length, &new->endian);
	new->width = width;
	new->height = height;
}

t_img	new_img(t_data *data, int width, int height, char *path)
{
	t_img	new;
	t_img	to_feet;
	int		x;
	int		y;

	y = -1;
	new_img_norm(data, width, height, &new);
	while (++y < new.height)
	{
		x = -1;
		while (++x < new.width)
			new.addr[y * (new.line_length / 4) + x] = 0xFF000000;
	}
	if (path)
		new_img_norm_2(data, &to_feet, path, &new);
	return (new);
}
