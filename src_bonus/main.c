/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:33:25 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/23 13:13:10 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d_bonus.h"
#include "../lib/test.h"

int	main(int ac, char **av)
{
	t_data	data;

	srand(time(NULL));
	if (ac != 2)
		return (ft_dprintf(2,
				"Cub3d_bonus takes just a maps_bonus/path.cub argument\n"));
	init_data(&data);
	get_info(&data, av[1]);
	parse_info(&data);
	parse_map(&data);
	check_put_textures(&data.i);
	init_player_direction(&data);
	data.test = 0;
	init_mlx(&data);
	init_textures(&data);
	listen_for_input(&data);
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_loop(data.mlx_ptr);
	clean_exit(&data, 0);
	return (0);
}
