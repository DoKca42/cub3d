/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:15:25 by loculy            #+#    #+#             */
/*   Updated: 2023/07/04 13:14:33 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_dblcoor	line_raycast_new_dda_incr(t_main *main, float rad, int step, t_dblcoor val)
{
	t_dblcoor	dcoor;
	t_dblcoor	tmp;
	float		xdda;
	float		ydda;
	int			i;
	float		y_case;
	float		x_case;

	dcoor.x = main->ray->x;
	dcoor.y = main->ray->y;
	xdda = val.x / (float)step;
	ydda = val.y / (float)step;
	y_case = get_case_coor(get_center_player(main)).y;
	if (!(rad < PI))
		y_case += MAP_RES;
	x_case = get_case_coor(get_center_player(main)).x;
	if (!((rad > PI / 2) && (rad < (PI / 2) * 3)))
		x_case += MAP_RES;
	i = 0;
	while (i < step && dcoor.y >= 0)
	{
		if ((int)dcoor.y == y_case)
		{
			tmp.y = (int)dcoor.y;
			tmp.x = dcoor.x;
			//if (get_hit_texture_spbox(main, dcoor) == 1 || get_hit_texture_spbox(main, dcoor) == 2)
			if (raycast_get_collision(tmp, main) == 1)
			{
				//if ((int)dcoor.y == 100 && (int)dcoor.x == 150)
				//	printf("%f %f\n", dcoor.x, dcoor.y);
				return (tmp);
			}
			else
			{
				if (rad < PI)
					y_case -= MAP_RES;
				else
					y_case += MAP_RES;
			}
		}
		if ((int)dcoor.x == x_case)
		{
			tmp.x = (int)dcoor.x;
			tmp.y = dcoor.y;
			//if (get_hit_texture_spbox(main, dcoor) == 4 || get_hit_texture_spbox(main, dcoor) == 3)
			if (raycast_get_collision(tmp, main) == 1)
				return (tmp);
			else
			{
				if ((rad > PI / 2) && (rad < (PI / 2) * 3))
					x_case -= MAP_RES;
				else
					x_case += MAP_RES;
			}
		}
		dcoor.x += xdda;
		dcoor.y += ydda;
		i++;
	}
	return (dcoor);
}

t_dblcoor	line_raycast_new_dda(t_main *main, float rad, t_dblcoor	max)
{
	int			dx;
	int			dy;
	int			step;
	t_dblcoor	dcoor;

	dx = max.x - main->ray->x;
	dy = max.y - main->ray->y;
	step = get_max(get_abs(dx), get_abs(dy));
	printf(">>%d, %f/%f «» %f/%f\n", step, max.x, main->ray->x, max.y, main->ray->y);
	dcoor.x = dx;
	dcoor.y = dy;
	return (line_raycast_new_dda_incr(main, rad, step, dcoor));
}

t_dblcoor	line_raycast_new(t_main *main, float rad)
{
	t_dblcoor	val;
	t_dblcoor	a;
	t_dblcoor	b;
	int			max;

	a.x = 0;
	a.y = 0;
	b.x = main->map->width * MAP_RES;
	b.y = main->map->height * MAP_RES;
	max = distance_diff(a, b);
	val.x = main->ray->x + cos(rad) * max;
	val.y = main->ray->y - sin(rad) * max;
	draw_line((int)main->ray->x / 2, (int)main->ray->y / 2, (int)main->ray->x / 2
		+ cos(rad) * 25, (int)main->ray->y / 2 - sin(rad) * 25);
	return (line_raycast_new_dda(main, rad, val));
}

void	raycast_flastlight_new(t_main *main, float angle)
{
	int			i;
	t_dblcoor	val;
	float		step;
	float		temp;

	step = 0.0234375;
	i = 0;
	angle += step * 1280;
	while (i < 2560)
	{
		temp = angle;
		if (angle < 0)
			temp += 359;
		else if (angle >= 360)
			temp = angle - 360;
		val = line_raycast_new(main, deg_to_rad(temp));
		if (i % 10 == 0)
		{
			draw_rectangle(main, i, height_distance(distance_from_main(main, val), temp), val);
			//printf(">>%d = %f - x:%f y:%f\n", i, temp, val.x, val.y);
		}
		//if (i > 2200)
		//	printf(">>%d = %f - %f %f\n", i, temp, val.x, val.y);
		angle -= step;
		i++;
	}
}
