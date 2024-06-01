/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:38:58 by mablatie          #+#    #+#             */
/*   Updated: 2023/12/19 18:06:32 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	err_msg(char *str)
{
	ft_dprintf(2, str);
	return (0);
}

void	error_alloc(t_data *data)
{
	ft_dprintf(2, "Allocation Error\n");
	end(data);
}

void	error_map(t_data *data)
{
	ft_dprintf(2, "Error map format\n");
	end(data);
}
