/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_vertical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:19:18 by loculy            #+#    #+#             */
/*   Updated: 2023/06/28 20:22:16 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_dblcoor	line_raycast_verti(t_main *main, float rad)
{
	float		a_tan;
	t_dblcoor	val;
	float		rx;
	float		ry;
	float		dx;

	a_tan = -1 / tan(rad);
	if (((rad > PI / 2) && (rad < (PI / 2) * 3)))
	{
		dx = get_case_coor(get_center_player(main)).x;
		ry = (dx) * (tan(rad)) + main->ray->y;
		rx = -(dx);
	}
	else
	{
		dx = get_case_coor(get_center_player(main)).x + MAP_RES;
		ry = -(dx) * (tan(rad)) + main->ray->y;
		rx = -(dx);
	}
	val.x = -rx;
	val.y = ry;
	if (raycast_get_collision(val, main))
		return (val);
	else
		return (line_raycast_verti_next(main, rad, val));
}

t_dblcoor	line_raycast_verti_next(t_main *main, float rad, t_dblcoor val)
{
	float		a_tan;
	float		rx;
	float		ry;
	float		dx;

	a_tan = -1 / tan(rad);
	while (raycast_get_collision(val, main) == 0 && val.y >= 0
		&& val.y <= main->map->height * MAP_RES)
	{
		if (((rad > PI / 2) && (rad < (PI / 2) * 3)))
		{
			dx = val.x - MAP_RES;
			ry = (dx) * (tan(rad)) + val.y;
			rx = -(dx);
		}
		else
		{
			dx = val.x + MAP_RES;
			ry = -(dx) * (tan(rad)) + val.y;
			rx = -(dx);
		}
		val.x = -rx;
		val.y = ry;
	}
	return (val);
}
