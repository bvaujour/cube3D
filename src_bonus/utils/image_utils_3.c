/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanitas <vanitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:42:01 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/09 16:45:15 by vanitas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	set_image_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	if (color == (int)0xFF000000)
	{
		return ;
	}
	pixel = y * (image->line_length / 4) + x;
	image->addr[pixel] = color;
}

int	get_pixel_img(t_img *img, int x, int y)
{
	int	pixel_index;
	int	color;

	pixel_index = y * img->line_length / (img->bits_per_pixel / 8) + x;
	color = img->addr[pixel_index];
	return (color);
}

void	put_img_to_img_scaled(t_img *dst, t_img *src)
{
	int		i;
	int		j;
	float	x;
	float	y;

	i = 0;
	x = 0;
	while (i < dst->width)
	{
		j = 0;
		y = 0;
		while (j < dst->height)
		{
			set_image_pixel(dst, i, j, get_pixel_img(src, (int)x, (int)y));
			j++;
			y += (float)src->height / dst->height;
		}
		i++;
		x += (float)src->width / dst->width;
	}
}

void	reverse_put_img_to_img(t_img *dst, t_img *src, int x, int y)
{
	int	i;
	int	j;

	j = src->height - 1;
	while (j > 0 && j - src->height + y > 0)
	{
		i = src->width - 1;
		while (i > 0 && i - src->height + x > 0)
		{
			set_image_pixel(dst, i - src->height + x, j - src->height + y,
				get_pixel_img(src, i, j));
			i--;
		}
		j--;
	}
}

void	the_put_img(t_img *dst, t_img *src, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < src->height)
	{
		i = 0;
		while (i < src->width)
		{
			if (x + i > 0 && y + j > 0 && x + i < dst->width
				&& y + j < dst->height)
				set_image_pixel(dst, x + i, y + j, get_pixel_img(src, i, j));
			i++;
		}
		j++;
	}
}
