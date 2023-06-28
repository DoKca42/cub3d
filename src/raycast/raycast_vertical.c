/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_vertical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:19:18 by loculy            #+#    #+#             */
/*   Updated: 2023/06/28 19:07:25 by loculy           ###   ########.fr       */
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
	rx = -main->ray->x;
	ry = main->ray->y;
	if (((rad > PI / 2) && (rad < (PI / 2) * 3)))
	{
		dx = get_case_coor(get_center_player(main)).x;
		ry = (dx) * (tan(rad)) + main->ray->y;
		rx = -(dx);
		printf("GAUCHE\n");
	}
	else
	{
		
		dx = get_case_coor(get_center_player(main)).x + MAP_RES;
		ry = -(dx) * (tan(rad)) + main->ray->y;
		rx = -(dx);
		printf("DROITE\n");
	}
	val.x = -rx;
	val.y = ry;
	//if (raycast_get_collision(val, main))
	return (val);
	//else
	//	return (line_raycast_hori_next(main, rad, val));
}
