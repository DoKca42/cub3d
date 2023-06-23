/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seya <seya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:33:20 by loculy            #+#    #+#             */
/*   Updated: 2023/06/24 00:04:50 by seya             ###   ########.fr       */
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

void	ft_player_move(t_main *main, t_inpt input)
{
	//t_map	*map;

	//map = main->map;
	if (input.up == 1)
		player_move_wall(main, 0, 0, -input.speed);
	if (input.down == 1)
		player_move_wall(main, 1, 0, input.speed);
	if (input.right == 1)
		player_move_wall(main, 2, input.speed, 0);
	if (input.left == 1)
		player_move_wall(main, 3, -input.speed, 0);
	if (input.up + input.down + input.right + input.left > 0)
	{
		ray_set_player_pose(main);
		raycast(main);
		//raycast_get_collision(ray_get_yn_xn(main), main);
		//printf("xn: %f - yn: %f\n", main->ray->x + main->ray->xn, main->ray->y + main->ray->yn);
		//draw_line(main->ray->x, main->ray->y, main->ray->x + main->ray->xn, main->ray->y + main->ray->yn);
	}
}
