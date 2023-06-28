/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_vertical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:19:18 by loculy            #+#    #+#             */
/*   Updated: 2023/06/28 23:13:33 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_dblcoor	line_raycast_verti(t_main *main, float rad)
{
	float		a_tan;
	t_dblcoor	val;
	float		rx;
	float		ry;

	a_tan = -1 / tan(rad);
	if ((int)(rad * 180 / PI) == 90)
	{
		ry = get_case_coor(get_center_player(main)).y;
		rx = -main->ray->x;
	}
	else if (((rad > PI / 2) && (rad < (PI / 2) * 3)))
	{
		rx = -get_case_coor(get_center_player(main)).x;
		ry = -rx * tan(rad);
	}
	else
	{
		rx = -(get_case_coor(get_center_player(main)).x + MAP_RES);
		ry = rx * tan(rad);
		
	}
	val.x = -rx;
	val.y = ry;
	draw_line_red((int)main->ray->x, (int)main->ray->y, (int)val.x, (int)val.y, ft_pixel(255, 2, 2, 255));
	if (raycast_get_collision(val, main))
		return (val);
	else
		return (line_raycast_verti_next(main, rad, val));
	//return (val);
}

t_dblcoor	line_raycast_verti_next(t_main *main, float rad, t_dblcoor val)
{
	float		a_tan;
	float		rx;
	float		ry;
	t_dblcoor	tmp;
	int	i = 0;

	tmp = val;
	a_tan = -1 / tan(rad);
	while (raycast_get_collision(val, main) == 0 && val.y >= 0
		&& val.y <= main->map->height * MAP_RES && i < 1)
	{
		if ((int)(rad * 180 / PI) == 90)
		{
			ry = val.y - MAP_RES;
			rx = val.x;
		}
		else if (((rad > PI / 2) && (rad < (PI / 2) * 3)))
		{
			rx = val.x - MAP_RES;
			ry = main->ray->x - rx * tan(rad);
			printf(">> %f %f %f\n", tan(rad), val.x * tan(rad), tmp.y);
			draw_line_red((int)tmp.x, (int)tmp.y, (int)rx, (int)tmp.y, ft_pixel(255, 2, 255, 255));
		}
		else
		{
			rx = val.x + MAP_RES;
			ry = -val.x * tan(rad);
			draw_line_red((int)tmp.x, (int)tmp.y, (int)rx, (int)tmp.y, ft_pixel(255, 2, 255, 255));
			
		}
		val.x = rx;
		val.y = ry;
		i++;
	}
	return (val);
}
