/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:33:20 by loculy            #+#    #+#             */
/*   Updated: 2023/06/21 18:51:59 by loculy           ###   ########.fr       */
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
	t_map	*map;

	map = main->map;
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
		ray_get_yn_xn(main);
		printf("xn: %f - yn: %f\n", main->ray->xn, main->ray->yn);
	}
}
