/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:49:45 by loculy            #+#    #+#             */
/*   Updated: 2023/07/05 17:55:56 by loculy           ###   ########.fr       */
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

int	get_mini(t_dblcoor verti, t_dblcoor horiz)
{
	int	step_vt;
	int	step_hz;

	step_vt = 0;
	step_hz = 0;
	step_vt = get_max(get_abs(verti.x), get_abs(verti.y));
	step_hz = get_max(get_abs(horiz.x), get_abs(horiz.y));
	if (step_vt < step_hz)
		return (0);
	else
		return (1);
}

t_dblcoor	convert_pose(t_dblcoor pose, t_dblcoor new)
{
	t_dblcoor	out;

	out.x = new.x + pose.x;
	out.y = new.y + pose.y;
	return (out);
}

void	raycast(t_main *main)
{
	//t_dblcoor	pose;
	//t_dblcoor	new;
	t_map	*map;

	map = main->map;
	//pose = get_dblcenter_player(main);
	fill_color_image(map->ray_lines, ft_pixel(255, 255, 255, 0));
	fill_color_image(map->view, ft_pixel(255, 255, 255, 0));
	raycast_flastlight_new(main, map->current.direc);
	//deg_to_rad(map->current.direc)
	//printf(">> %d", map->current.direc);
	//new = raycast_flastlight(pose, 210, main);
	//printf(">> %f, %f\n", calculateAngle(pose.x, pose.y, new.x, new.y, new.x , pose.y), new.y);
	//draw_line(main->ray->x, main->ray->y, new.x, new.y);
	//printf(">> %d\n", get_max(new.x, new.y));
}
