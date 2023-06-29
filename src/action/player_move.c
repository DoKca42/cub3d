/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:33:20 by loculy            #+#    #+#             */
/*   Updated: 2023/06/29 21:29:05 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	update_player(t_main *main, int x, int y)
{
	t_map	*map;

	map = main->map;
	map->img_player->instances[0].x += x;
	map->img_player->instances[0].y += y;
	map->current.y += y;
	map->current.x += x;
}

void	set_mv(t_main *main, int x, int y)
{
	t_map	*map;

	map = main->map;
	map->img_player->instances[0].x = x;
	map->img_player->instances[0].y = y;
	map->current.y = y;
	map->current.x = x;
}

void	ft_player_rotation(t_main *main)
{
	ray_set_player_pose(main);
	raycast(main);
}

void	ft_player_move(t_main *main, t_inpt input)
{
	t_map	*map;
	float	pdx;
	float	pdy;

	map = main->map;
	if (input.down == 1)
	{
		pdy = -sin(deg_to_rad(map->current.direc)) * input.speed;
		pdx = (cos(deg_to_rad(map->current.direc)) * input.speed);
		player_move_wall(main, map->current.direc, -pdx, -pdy);
	}
	if (input.up == 1)
	{
		pdy = -sin(deg_to_rad(map->current.direc)) * input.speed;
		pdx = (cos(deg_to_rad(map->current.direc)) * input.speed);
		player_move_wall(main, map->current.direc, pdx, pdy);
	}
	if (input.right == 1)
	{
		pdy = cos(deg_to_rad(map->current.direc)) * input.speed;
		pdx = (sin(deg_to_rad(map->current.direc)) * input.speed);
		player_move_wall(main, map->current.direc, pdx, pdy);
	}
	if (input.left == 1)
	{
		pdy = cos(deg_to_rad(map->current.direc)) * input.speed;
		pdx = (sin(deg_to_rad(map->current.direc)) * input.speed);
		player_move_wall(main, map->current.direc, -pdx, -pdy);
	}
}
