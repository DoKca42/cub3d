/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:49:45 by loculy            #+#    #+#             */
/*   Updated: 2023/06/21 19:08:58 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ray_set_player_pose(t_main *main)
{
	t_dblcoor	player;

	player = get_dblcenter_player(main);
	main->ray->x = player.x;
	main->ray->y = player.y;
}

t_dblcoor	ray_get_yn_xn(t_main *main)
{
	t_dblcoor	n_pose;
	t_coor		case_coor;

	main->map->current.direc = 75;
	case_coor = get_case_coor(get_center_player(main));
	ray_set_player_pose(main);

	main->ray->yn = (double)case_coor.y - main->ray->y;
	main->ray->xn = -main->ray->yn / tan(deg_to_rad(main->map->current.direc));
	n_pose.y = main->ray->yn;
	n_pose.x = main->ray->xn;
	return (n_pose);
}
