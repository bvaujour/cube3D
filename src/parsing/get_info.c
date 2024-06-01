/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:01:21 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/29 13:15:40 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"
#include "../../lib/test.h"

static void	get_map(t_data *data, char **cpy)
{
	while (*cpy && only_blank(*cpy))
		cpy++;
	while (*cpy)
	{
		ft_safe_trim(data, cpy, "\n");
		data->i.map = ft_add_to_tab(data->i.map, ft_strdup(*cpy));
		if (!data->i.map)
			error_alloc(data);
		cpy++;
	}
}

static void	get_texture(t_data *data)
{
	char	**cpy;

	cpy = data->config;
	while (*cpy && (!data->i.no || !data->i.so || !data->i.ea
			|| !data->i.we || !data->i.floor || !data->i.ciel))
	{
		ft_safe_trim(data, cpy, "\n ");
		get_texture2(data, *cpy);
		cpy++;
	}
	get_map(data, cpy);
}

static void	get_config(t_data *data, char *path)
{
	int		fd;
	char	*str;

	str = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		(ft_dprintf(2, "Error, can't open config file\n"), end(data));
	str = get_next_line(fd);
	if (!str)
		(get_next_line(-99), close(fd),
			ft_dprintf(2, "Error, Empty or corrupted map file\n"), end(data));
	while (str)
	{
		data->config = ft_add_to_tab(data->config, ft_strdup(str));
		if (!data->config)
			(get_next_line(-99), close(fd),
				(ft_dprintf(2, "Error, allocation\n"), end(data)));
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}

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

void	get_info(t_data *data, char *path)
{
	check_extension(data, path);
	get_config(data, path);
	get_texture(data);
	ft_safe_trim(data, &data->i.no, " ");
	ft_safe_trim(data, &data->i.so, " ");
	ft_safe_trim(data, &data->i.ea, " ");
	ft_safe_trim(data, &data->i.we, " ");
	ft_safe_trim(data, &data->i.floor, " ");
	ft_safe_trim(data, &data->i.ciel, " ");
}
