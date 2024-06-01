/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:17:28 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/29 13:17:39 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d_bonus.h"
#include "../../lib/test.h"

void	check_extension(t_data *data, char *path)
{
	int	i;

	i = ft_strlen(path);
	if (i < 4)
		(ft_dprintf(2, "Error, invalid map file\n"), end(data));
	i -= 4;
	if (ft_strcmp(path + i, ".cub") != 0)
		(ft_dprintf(2, "Error, invalid extention\n"), end(data));
}

char	*str_full_space(t_data *data, char *to_cpy, int size)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		end(data);
	i = ft_strlen(to_cpy);
	ft_strlcpy(str, to_cpy, i);
	while (i < size)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

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
		(ft_dprintf(2, "Error, wrong config format\n"), clean_exit(data, 0));
}
