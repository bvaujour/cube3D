/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:14:14 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/29 14:07:49 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

int	open_door(t_data *data, char *a)
{
	static time_t	t0 = 0;
	static char		*b = NULL;

	if (data->door == false && a != NULL && b == NULL)
	{
		data->door = true;
		b = a;
	}
	if (b != NULL && get_time() - t0 > 20 && *b < 'H')
	{
		*b += 1;
		t0 = get_time();
		return (1);
	}
	if (b && *b == 'H')
	{
		data->door = false;
		b = NULL;
	}
	return (0);
}

int	close_door(t_data *data, char *a)
{
	static time_t	t0 = 0;
	static char		*b = NULL;

	if (data->door == false && a != NULL && b == NULL)
	{
		data->door = true;
		b = a;
	}
	if (b != NULL && get_time() - t0 > 20 && *b > 'D')
	{
		*b -= 1;
		t0 = get_time();
		return (1);
	}
	if (b && *b == 'D')
	{
		data->door = false;
		b = NULL;
	}
	return (0);
}

int	explosion(char *a)
{
	static time_t	t0 = 0;
	static char		*b = NULL;

	if (a != NULL && b == NULL)
		b = a;
	if (b != NULL && get_time() - t0 > 80 && *b < 'T')
	{
		*b += 1;
		t0 = get_time();
		return (1);
	}
	if (b && *b == 'T')
	{
		*b = '0';
		b = NULL;
	}
	return (0);
}

void	new_img_norm_2(t_data *data, t_img *to_feet, char *path, t_img *new)
{
	init_img_clean(to_feet);
	to_feet->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&to_feet->width, &to_feet->height);
	if (!to_feet->img_ptr)
	{
		mlx_destroy_image(data->mlx_ptr, new->img_ptr);
		(ft_dprintf(2, "xpm failure\n"), clean_exit(data, 5));
	}
	to_feet->addr = (int *)mlx_get_data_addr(to_feet->img_ptr,
			&to_feet->bits_per_pixel, &to_feet->line_length, &to_feet->endian);
	put_img_to_img_scaled(new, to_feet);
	mlx_destroy_image(data->mlx_ptr, to_feet->img_ptr);
}
