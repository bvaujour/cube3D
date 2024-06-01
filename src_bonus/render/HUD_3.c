/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HUD_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanitas <vanitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:33:08 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/09 15:00:41 by vanitas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	weapon(t_data *data, t_img *img)
{
	static int		i = 0;
	static int		incr = 1;
	static time_t	t0 = 0;

	if (data->player.is_firing == 4)
		data->player.is_firing = 0;
	the_put_img(img, &data->player.gun[data->player.is_firing],
		data->width / 2 + data->player.gun[0].width / 3 + 2 * i,
		data->height + data->player.gun[0].height / 17
		- data->player.hud.height / 1.2 - data->player.gun[0].height + i);
	if (get_time() - t0 > 40)
	{
		i += incr;
		t0 = get_time();
		if (data->player.is_firing != 0)
		{
			incr = data->height / 36;
			data->player.is_firing++;
		}
	}
	weapon_norm(data, &i, &incr);
}

void	reload(t_data *data, t_img *img)
{
	static int		i = 0;
	static time_t	t0 = 0;

	the_put_img(img, &data->player.reload[i], data->width / 2,
		data->height - data->player.reload[i].height);
	if (get_time() - t0 > 100)
	{
		i++;
		t0 = get_time();
	}
	if (i == 11)
	{
		i = 0;
		data->player.reloading = false;
		data->player.nb_bullets = 6;
	}
}

void	crosshair(t_data *data, t_img *img)
{
	t_img	new;

	new = new_img(data, 64, 64, "textures/crosshair.xpm");
	put_img_to_img(img, &new, data->width / 2 - new.width / 2,
		data->height / 2 - new.height / 2);
	mlx_destroy_image(data->mlx_ptr, new.img_ptr);
}

void	spark(t_data *data, t_img *img)
{
	t_img	spark;
	int		spark_size;
	char	*path;

	if (data->player.is_firing)
	{
		if (data->player.aiming_at)
			spark_size = (int)(100 - data->player.aiming_at->distance);
		else
			spark_size = 50 - data->wall_dist[data->width / 2] * 3;
		if (spark_size <= 5)
			spark_size = 5;
		path = ft_safe_dup(data, "textures/spark");
		path = ft_safe_join(data, path, ft_itoa(rand() % 3), 3);
		path = ft_safe_join(data, path, ".xpm", 1);
		spark = new_img(data, spark_size, spark_size, path);
		put_img_to_img(img, &spark, data->width / 2 - spark.width / 2
			+ pos_neg() * data->player.is_firing * 2, data->height / 2
			- spark.height / 2 + pos_neg() * data->player.is_firing * 2);
		mlx_destroy_image(data->mlx_ptr, spark.img_ptr);
		free(path);
	}
}

void	bullets(t_data *data, t_img *img)
{
	int	nb;
	int	dist_w;

	nb = 0;
	dist_w = 0;
	while (nb < data->player.nb_bullets - 3)
	{
		put_img_to_img(img, &data->player.bullets, (data->width / 2)
			+ data->width / 12.173913043 + dist_w, data->height
			- data->height / 11.25);
		dist_w += data->width / 70;
		nb++;
	}
	dist_w = 0;
	while (nb < data->player.nb_bullets)
	{
		put_img_to_img(img, &data->player.bullets, (data->width / 2)
			+ data->width / 12.173913043 + dist_w, data->height
			- data->height / 22.5);
		dist_w += data->width / 70;
		nb++;
	}
}
