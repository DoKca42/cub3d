/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:05:14 by loculy            #+#    #+#             */
/*   Updated: 2023/06/22 10:48:39 by loculy           ###   ########.fr       */
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
		while (map[y] != 0 && map[y][x] != 0 && map[y][x] != '\n')
		{
			size++;
			x++;
		}
		y++;
	}
	return (size);
}

int	get_map_hitbox_size(char **map, char c)
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
		while (map[y] != 0 && map[y][x] != 0 && map[y][x] != '\n')
		{
			if (map[y][x] == c)
				size++;
			x++;
		}
		y++;
	}
	return (size);
}

t_coor	get_map_maxsize(char **map)
{
	t_coor	size;

	size.y = 0;
	size.x = 0;
	if (!map)
		return (size);
	while (map[size.y] && map[size.y] != 0)
	{
		if (ft_strlen_(map[size.y]) > size.x)
			size.x = ft_strlen_(map[size.y]);
		size.y++;
	}
	return (size);
}

t_main	*get_main(void *input)
{
	static t_main	*main;

	if (input != 0)
	{
		main = (t_main *)input;
	}
	return (main);
}
