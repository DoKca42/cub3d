/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:48:24 by loculy            #+#    #+#             */
/*   Updated: 2023/06/21 00:47:19 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_coor	get_case_player(t_main *main)
{
	t_coor	case_coor;

	case_coor.x = main->map->current.x / MAP_RES;
	case_coor.y = main->map->current.y / MAP_RES;
	case_coor.x = case_coor.x * MAP_RES;
	case_coor.y = case_coor.y * MAP_RES;
	return (case_coor);
}

int	interact_door(t_main *main, t_door *door, int cldwn)
{
	if (is_wall_collision(0, 0, main->map->current, door->coor))
		return (cldwn);
	if (door->open == 0)
		door->open = 1;
	else
		door->open = 0;
	return (1);
}

void	check_doors(t_main *main, t_map	*map)
{
	t_coor	case_coor;
	int		cldwn;
	int		i;

	i = -1;
	cldwn = 0;
	case_coor = get_case_player(main);
	while (++i < map->door_size)
	{
		if (case_coor.x - MAP_RES == map->door[i].coor.x
			&& case_coor.y == map->door[i].coor.y)
			cldwn = interact_door(main, &(map->door[i]), cldwn);
		else if (case_coor.x + MAP_RES == map->door[i].coor.x
			& case_coor.y == map->door[i].coor.y)
			cldwn = interact_door(main, &(map->door[i]), cldwn);
		else if (case_coor.x == map->door[i].coor.x
			&& case_coor.y - MAP_RES == map->door[i].coor.y)
			cldwn = interact_door(main, &(map->door[i]), cldwn);
		else if (case_coor.x == map->door[i].coor.x
			&& case_coor.y + MAP_RES == map->door[i].coor.y)
			cldwn = interact_door(main, &(map->door[i]), cldwn);
	}
	if (cldwn == 1)
		main->cooldown->door = get_time(main) + 150;
}

void	player_get_action(t_main *main)
{
	t_map	*map;

	map = main->map;
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_E))
		if (get_time(main) >= main->cooldown->door)
			check_doors(main, map);
}