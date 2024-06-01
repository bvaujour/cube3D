/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HUD.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:47:37 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/16 18:30:06 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"

void	second(t_data *data, t_img *chrono, int time)
{
	char	*path;
	int		sec[2];
	t_img	img_nb;

	sec[0] = ((time % 60000) / 10000);
	sec[1] = (((time % 60000) / 1000) % 10);
	path = ft_strjoin("textures/nombres/", ft_itoa(sec[0]), 2);
	path = ft_strjoin(path, ".xpm", 1);
	img_nb = new_img(data, chrono->width / 4, chrono->height, path);
	second_norm(data, chrono, time, &img_nb);
	free(path);
	path = ft_strjoin("textures/nombres/", ft_itoa(sec[1]), 2);
	path = ft_strjoin(path, ".xpm", 1);
	img_nb = new_img(data, chrono->width / 4, chrono->height, path);
	if (time < 60000)
		change_color(&img_nb, 0x000000, 0x7F0000, 0);
	else
		change_color(&img_nb, 0x000000, 0x007F00, 0);
	put_img_to_img(chrono, &img_nb, img_nb.width * 2, 0);
	mlx_destroy_image(data->mlx_ptr, img_nb.img_ptr);
	free(path);
}

void	minute(t_data *data, t_img *chrono, int time)
{
	t_img	img_nb;
	int		min;
	char	*path;

	min = time / 60000;
	path = ft_strjoin("textures/nombres/", ft_itoa(min), 2);
	path = ft_strjoin(path, ".xpm", 1);
	img_nb = new_img(data, chrono->width / 4, chrono->height, path);
	if (time < 60000)
		change_color(&img_nb, 0x000000, 0x7F0000, 0);
	else
		change_color(&img_nb, 0x000000, 0x007F00, 0);
	put_img_to_img(chrono, &img_nb, 0, 0);
	mlx_destroy_image(data->mlx_ptr, img_nb.img_ptr);
	img_nb = new_img(data, chrono->width / 4, chrono->height,
			"textures/nombres/doublecoma.xpm");
	if (time < 60000)
		change_color(&img_nb, 0x000000, 0x7F0000, 0);
	else
		change_color(&img_nb, 0x000000, 0x007F00, 0);
	put_img_to_img(chrono, &img_nb, chrono->width / 8, 0);
	mlx_destroy_image(data->mlx_ptr, img_nb.img_ptr);
	free(path);
}

void	micro(t_data *data, t_img *chrono, int time)
{
	t_img	img_nb;
	char	*path;

	img_nb = new_img(data, chrono->width / 4, chrono->height,
			"textures/nombres/coma.xpm");
	if (time < 60000)
		change_color(&img_nb, 0x000000, 0x7F0000, 0);
	else
		change_color(&img_nb, 0x000000, 0x007F00, 0);
	put_img_to_img(chrono, &img_nb, img_nb.width * 2 + img_nb.width / 2, 0);
	mlx_destroy_image(data->mlx_ptr, img_nb.img_ptr);
	path = ft_strjoin("textures/nombres/", ft_itoa((time % 1000) / 100), 2);
	path = ft_strjoin(path, ".xpm", 1);
	img_nb = new_img(data, chrono->width / 4, chrono->height, path);
	if (time < 60000)
		change_color(&img_nb, 0x000000, 0x7F0000, 0);
	else
		change_color(&img_nb, 0x000000, 0x007F00, 0);
	put_img_to_img(chrono, &img_nb, img_nb.width * 3, 0);
	mlx_destroy_image(data->mlx_ptr, img_nb.img_ptr);
	free(path);
}

void	count_down(t_data *data, t_img *img)
{
	t_img	chrono;
	int		time;

	time = data->time_limit - (get_time() - data->t0);
	if (time <= 0)
	{
		data->player.stats.hp = -1000;
		return ;
	}
	chrono = new_img(data, data->width / 10, data->height / 30, NULL);
	minute(data, &chrono, time);
	second(data, &chrono, time);
	micro(data, &chrono, time);
	put_img_to_img(img, &chrono, data->width - chrono.width, data->height / 30);
	mlx_destroy_image(data->mlx_ptr, chrono.img_ptr);
}

void	user_interface(t_data *data, t_img *img)
{
	if (data->player.reloading == false)
		weapon(data, img);
	else
		reload(data, img);
	put_img_to_img(img, &data->player.hud, 0, data->height
		- data->player.hud.height);
	put_face(data, img);
	minimap(data, img);
	print_stamina(data, img);
	print_life(data, img);
	spark(data, img);
	crosshair(data, img);
	bullets(data, img);
	chipset(data, img);
	hit_react(data, img);
	count_down(data, img);
	objective(data, img);
}
