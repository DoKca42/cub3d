/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_orientation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 23:56:29 by loculy            #+#    #+#             */
/*   Updated: 2023/06/30 05:03:18 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*	1:SUD | 2:NORTH | 3:WEST | 4:EST */
int	get_hit_orient(double x, double y, t_coor wall)
{
	if (x >= (double)wall.x && x <= (double)wall.x + MAP_RES
		&& (y == (double)wall.y + MAP_RES))
		return (1);
	if (x >= (double)wall.x && x <= (double)wall.x + MAP_RES
		&& (y == (double)wall.y))
		return (2);
	if (y >= (double)wall.y && y <= (double)wall.y + MAP_RES
		&& (x == (double)wall.x + MAP_RES))
		return (3);
	if (y >= (double)wall.y && y <= (double)wall.y + MAP_RES
		&& (x == (double)wall.x))
		return (4);
	return (0);
}

t_hit	get_hit_texture_box(t_main *main, t_dblcoor val)
{
	int		i;
	t_hit	box;
	t_map	*map;

	i = 0;
	map = main->map;
	box.x = 15;
	while (i < map->wall_size)
	{
		if (is_ray_collision(val.x, val.y, map->wall[i]) == 1)
		{
			box.orientation = get_hit_orient(val.x, val.y, map->wall[i]);
			return (box);
		}
		i++;
	}
	return (box);
}

int	get_hit_texture_spbox(t_main *main, t_dblcoor val)
{
	int		i;
	t_map	*map;

	i = 0;
	map = main->map;
	while (i < map->wall_size)
	{
		if (is_ray_collision(val.x, val.y, map->wall[i]) == 1)
		{
			return (get_hit_orient(val.x, val.y, map->wall[i]));
		}
		i++;
	}
	return (0);
}