/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hitbox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:36:39 by loculy            #+#    #+#             */
/*   Updated: 2023/06/20 21:18:00 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_wall_collision(int x, int y, t_player current, t_coor wall)
{
	t_player	move;

	move = current;
	move.x += x;
	move.y += y;
	if ((!(move.x + PLAYER_RES < wall.x) && !(move.x > wall.x + MAP_RES))
		&& (!(move.y + PLAYER_RES < wall.y)
			&& !(move.y > wall.y + MAP_RES)))
		return (1);
	return (0);
}

int	player_move_wall(t_main *main, int type, int x, int y)
{
	int		i;
	t_map	*map;

	i = 0;
	map = main->map;
	while (i < map->wall_size)
	{
		if (is_wall_collision(x, y, map->current, map->wall[i]))
		{
			if (type == 0)
				set_mv(main, map->current.x, map->wall[i].y + MAP_RES + 1);
			else if (type == 1)
				set_mv(main, map->current.x, map->wall[i].y - PLAYER_RES - 1);
			else if (type == 2)
				set_mv(main, map->wall[i].x - PLAYER_RES - 1, map->current.y);
			else if (type == 3)
				set_mv(main, map->wall[i].x + MAP_RES + 1, map->current.y);
			return (1);
		}
		i++;
	}
	update_player(main, x, y);
	return (0);
}
