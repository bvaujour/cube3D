/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_protect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:09:01 by bvaujour          #+#    #+#             */
/*   Updated: 2024/01/23 13:05:16 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"
#include "../../lib/test.h"

static int	check_file(char *todup, t_data *data)
{
	int		fd;
	char	*trim;

	trim = ft_strtrim(todup, " ", 0);
	if (!trim)
		(ft_dprintf(2, "Error, allocation\n"), free(trim), clean_exit(data, 1));
	fd = open(trim, O_RDONLY);
	if (fd != -1)
		return (close(fd), free(trim), 0);
	else
		return (free(trim), 1);
}

void	ft_safe_trim(t_data *data, char **str, char *charset)
{
	*str = ft_strtrim(*str, charset, 1);
	if (!*str)
		error_alloc(data);
}

char	*ft_safe_dup_init(t_data *data, char *todup)
{
	char	*duped;

	if (check_file(todup, data))
		(ft_dprintf(2, "Error, XPM file not found\n"), end(data));
	duped = ft_strdup(todup);
	if (!duped)
		error_alloc(data);
	return (duped);
}

char	*ft_safe_dup(t_data *data, char *todup)
{
	char	*duped;

	duped = ft_strdup(todup);
	if (!duped)
		error_alloc(data);
	return (duped);
}
