/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanitas <vanitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:33:25 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/09 17:45:55 by vanitas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"
#include "../lib/test.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_dprintf(2, "Cub3d takes just a maps/path.cub argument\n"));
	init_data(&data);
	get_info(&data, av[1]);
	parse_info(&data);
	parse_map(&data);
	init_player_direction(&data);
	check_put_textures(&data.i);
	init_mlx(&data);
	init_textures(&data);
	render_images(&data);
	listen_for_input(&data);
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_loop(data.mlx_ptr);
	clean_exit(&data, 0);
	return (0);
}
