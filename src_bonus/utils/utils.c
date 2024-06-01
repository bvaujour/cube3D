/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanitas <vanitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:34:51 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/09 16:50:07 by vanitas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"
#include "../../lib/test.h"

int	only_blank(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	if (str[i])
		return (0);
	return (1);
}

char	first_occur(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (str[i]);
}

char	last_occur(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
		i--;
	return (str[i]);
}

int	longest_str(char *str)
{
	static int	longest = 0;
	int			i;

	i = ft_strlen(str);
	if (longest < i)
		longest = i;
	return (longest);
}

int	isdigitstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
