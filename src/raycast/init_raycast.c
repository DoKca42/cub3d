/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:49:45 by loculy            #+#    #+#             */
/*   Updated: 2023/06/22 14:33:52 by loculy           ###   ########.fr       */
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

t_dblcoor	ray_horizontal(t_dblcoor pose, int direc)
{
	t_dblcoor	n_pose;
	t_coor		case_coor;

	case_coor = get_case_dbcoor(pose);
	n_pose.y = (double)case_coor.y - pose.y;
	n_pose.x = -(n_pose.y) / tan(deg_to_rad(direc));
	return (n_pose);
}

t_dblcoor	ray_vertical(t_dblcoor pose, int direc)
{
	t_dblcoor	n_pose;
	t_coor		case_coor;
	double		dx;

	case_coor = get_case_dbcoor(pose);
	dx = pose.x - (double)case_coor.x - MAP_RES;
	n_pose.y = (dx) * tan(deg_to_rad(direc));
	n_pose.x = -(dx);
	return (n_pose);
}

t_dblcoor	convert_pose(t_dblcoor pose, t_dblcoor new)
{
	t_dblcoor	out;

	out.x = new.x + pose.x;
	out.y = new.y + pose.y;
	return (out);
}

t_dblcoor	raycast_next(t_dblcoor pose, int angle, t_main *main, int type)
{
	t_dblcoor	val;
	int			i;

	i = 0;
	(void)type;
	while (i < 5)
	{
		if (type == 0)
			val = ray_horizontal(pose, angle);
		else
			val = ray_vertical(pose, angle);
		//printf(">> %f, %f, %f, %f === ", pose.x, pose.y, val.x, val.y);
		if (raycast_get_collision(convert_pose(val, pose), main) == 1)
		{
			//printf("GOOD\n");
			return (convert_pose(val, pose));
		}
		
		pose = convert_pose(pose, val);
		if (type == 0)
			pose.y -= 1;
		i++;
	}
	pose.x = 0;
	pose.y = 0;
	return (pose);
}

t_dblcoor	raycast_get_line(t_dblcoor pose, int angle, t_main *main)
{
	t_dblcoor	horiz;
	t_dblcoor	verti;

	//printf("VERTI = ");
	verti = raycast_next(pose, angle, main, 1);
	//printf("HORIZ = ");
	horiz = raycast_next(pose, angle, main, 0);
	if (verti.x != 0 && get_mini(verti, horiz) == 0)
		return (verti);
	else if (horiz.x != 0)
		return (horiz);
	return (get_dblcenter_player(main));
}

void	raycast(t_main *main)
{
	t_dblcoor	pose;
	t_dblcoor	new;

	pose = get_dblcenter_player(main);
	new = raycast_get_line(pose, 75, main);
	draw_line(main->ray->x, main->ray->y, new.x, new.y);
	///printf(">> %d\n", get_max(new.x, new.y));
	//if (get_mini(verti, horiz) == 0)
	//	draw_line(main->ray->x, main->ray->y, main->ray->x + verti.x, main->ray->y + verti.y);
	//else
	//	draw_line(main->ray->x, main->ray->y, main->ray->x + horiz.x, main->ray->y + horiz.y);
	//horiz = ray_horizontal(pose, 75);
}
