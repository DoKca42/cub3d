/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:05:14 by loculy            #+#    #+#             */
/*   Updated: 2023/06/20 13:12:23 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_map_size(char **map)
{
	int	size;
	int	y;
	int	x;

	y = 0;
	size = 0;
	if (!map)
		return (0);
	while (map[y] && map[y] != 0)
	{
		x = 0;
		while (map[y] != 0 && map[y][x] != 0)
		{
			size++;
			x++;
		}
		y++;
	}
	return (size);
}

int	get_map_hitbox_size(char **map)
{
	int	size;
	int	y;
	int	x;

	y = 0;
	size = 0;
	if (!map)
		return (0);
	while (map[y] && map[y] != 0)
	{
		x = 0;
		while (map[y] != 0 && map[y][x] != 0)
		{
			if (map[y][x] == '1')
				size++;
			x++;
		}
		y++;
	}
	return (size);
}
