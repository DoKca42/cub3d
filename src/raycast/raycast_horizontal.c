/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_horizontal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:36:25 by loculy            #+#    #+#             */
/*   Updated: 2023/06/28 20:23:25 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_dblcoor	line_raycast_hori(t_main *main, float rad)
{
	float		a_tan;
	t_dblcoor	val;
	float		rx;
	float		ry;

	a_tan = -1 / tan(rad);
	if (rad < PI)
	{
		ry = get_case_coor(get_center_player(main)).y;
		rx = (main->ray->y - ry) * a_tan - main->ray->x;
	}
	else
	{
		ry = get_case_coor(get_center_player(main)).y + MAP_RES;
		rx = (main->ray->y - ry) * a_tan - main->ray->x;
	}
	val.x = -rx;
	val.y = ry;
	if (raycast_get_collision(val, main))
		return (val);
	else
		return (line_raycast_hori_next(main, rad, val));
}

t_dblcoor	line_raycast_hori_next(t_main *main, float rad, t_dblcoor val)
{
	float	rx;
	float	ry;
	float	a_tan;

	a_tan = -1 / tan(rad);
	while (raycast_get_collision(val, main) == 0 && val.x >= 0
		&& val.x <= main->map->width * MAP_RES)
	{
		if (rad < PI)
		{
			ry = val.y - MAP_RES;
			rx = (val.y - ry) * a_tan - val.x;
		}
		else
		{
			ry = val.y + MAP_RES;
			rx = (val.y - ry) * a_tan - val.x;
		}
		val.x = -rx;
		val.y = ry;
	}
	return (val);
}
