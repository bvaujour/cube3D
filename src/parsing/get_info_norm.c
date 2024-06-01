/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:14:09 by mablatie          #+#    #+#             */
/*   Updated: 2024/01/29 13:14:52 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"
#include "../../lib/test.h"

void	get_texture2(t_data *data, char *cpy)
{
	if (ft_strlen(cpy) > 1 && !ft_strncmp(cpy, "NO", 2) && !data->i.no)
		data->i.no = ft_safe_dup_init(data, cpy + 2);
	else if (ft_strlen(cpy) > 1 && !ft_strncmp(cpy, "SO", 2)
		&& !data->i.so)
		data->i.so = ft_safe_dup_init(data, cpy + 2);
	else if (ft_strlen(cpy) > 1 && !ft_strncmp(cpy, "EA", 2)
		&& !data->i.ea)
		data->i.ea = ft_safe_dup_init(data, cpy + 2);
	else if (ft_strlen(cpy) > 1 && !ft_strncmp(cpy, "WE", 2)
		&& !data->i.we)
		data->i.we = ft_safe_dup_init(data, cpy + 2);
	else if (ft_strlen(cpy) > 0 && !ft_strncmp(cpy, "F", 1)
		&& !data->i.floor)
		data->i.floor = ft_safe_dup(data, cpy + 1);
	else if (ft_strlen(cpy) > 0 && !ft_strncmp(cpy, "C", 1)
		&& !data->i.ciel)
		data->i.ciel = ft_safe_dup(data, cpy + 1);
	else if (ft_strlen(cpy) != 0)
		(ft_dprintf(2, "Error, wrong config format\n"), end(data));
}
