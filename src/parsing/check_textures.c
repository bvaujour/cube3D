/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:08:42 by vanitas           #+#    #+#             */
/*   Updated: 2023/12/19 17:55:25 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

// static int	check_valid_rgb(int *rgb)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 3)
// 	{
// 		if (rgb[i] < 0 || rgb[i] > 255)
// 			return (err_msg_val(rgb[i], ERR_TEX_RGB_VAL, FAILURE));
// 		i++;
// 	}
// 	return (SUCCESS);
// }

static unsigned long	convert_rgb_to_hex(unsigned int red,
	unsigned int green, unsigned int blue)
{
	unsigned long	result;
	int				r;
	int				g;
	int				b;

	r = red;
	g = green;
	b = blue;
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (result);
}

int	check_put_textures(t_info *i)
{
	if (!i->no || !i->so || !i->we || !i->ea)
		return (err_msg(ERR_TEX_MISSING), 1);
	if (!i->floor || !i->ciel)
		return (err_msg(ERR_COLOR_MISSING), 1);
	i->hex_floor = convert_rgb_to_hex(i->r_floor, i->g_floor, i->b_floor);
	i->hex_ceiling = convert_rgb_to_hex(i->r_ciel, i->g_ciel, i->b_ciel);
	return (0);
}
