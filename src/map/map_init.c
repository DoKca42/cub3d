/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:03:31 by loculy            #+#    #+#             */
/*   Updated: 2023/06/20 13:54:15 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_coor	map_add_hitbox(int x, int y)
{
	t_coor	coor;

	coor.x = x;
	coor.y = y;
	return (coor);
}

t_map	init_map_hitbox(t_map map)
{
	int		i;
	int		y;
	int		x;

	map.hitbox_size = get_map_hitbox_size(map.map);
	if (map.hitbox_size == 0)
		return (map);
	map.hitbox = ftm_malloc((map.hitbox_size) * sizeof(t_coor));
	i = 0;
	y = 0;
	while (map.map[y] && map.map[y] != 0)
	{
		x = 0;
		while (map.map[y] != 0 && map.map[y][x] != 0)
		{
			if (map.map[y][x] == '1')
				map.hitbox[i++] = map_add_hitbox(x, y);
			x++;
		}
		y++;
	}
	return (map);
}

t_map	init_map(t_map map)
{
	map = init_map_hitbox(map);
	map = init_map_player(map);
	return (map);
}
