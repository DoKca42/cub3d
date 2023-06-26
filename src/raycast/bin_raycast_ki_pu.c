/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_raycast_ki_pu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:49:45 by loculy            #+#    #+#             */
/*   Updated: 2023/06/26 17:42:42 by loculy           ###   ########.fr       */
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

double calculateAngle(double xA, double yA, double xB, double yB, double xC, double yC) {
    double ABx, ABy, ACx, ACy;
    double dotProduct, normAB, normAC, angle;

    // Calcul des vecteurs AB et AC
    ABx = xB - xA;
    ABy = yB - yA;
    ACx = xC - xA;
    ACy = yC - yA;

    // Calcul du produit scalaire AB · AC
    dotProduct = (ABx * ACx) + (ABy * ACy);

    // Calcul des normes ||AB|| et ||AC||
    normAB = sqrt(ABx * ABx + ABy * ABy);
    normAC = sqrt(ACx * ACx + ACy * ACy);

    // Calcul de l'angle θ en radians
    angle = acos(dotProduct / (normAB * normAC));

    // Conversion de l'angle en degrés si nécessaire
    angle = angle * 180.0 / M_PI;

    return angle;
}

t_dblcoor	raycast_next_verti(t_dblcoor pose, int angle, t_main *main)
{
	t_dblcoor	val;
	int			i;

	i = 0;
	val = ray_vertical(pose, angle);
	val = convert_pose(val, pose);
	if (raycast_get_collision(val, main))
		return (val);
		/*
	while (raycast_get_collision(val, main) != 1 && i < 150)
	{
		val.y = val.y - (MAP_RES / cos(deg_to_rad(angle)));
		if (angle > 90 && angle < 270)
			val.x -= (double)MAP_RES;
		else
			val.x += (double)MAP_RES;
		i++;
	}*/
	return (val);
}

t_dblcoor	raycast_next_horiz(t_dblcoor pose, int angle, t_main *main)
{
	t_dblcoor	val;
	int			i;

	i = 0;
	val = ray_horizontal(pose, angle);
	val = convert_pose(val, pose);
	if (raycast_get_collision(val, main))
		return (val);
	/*
	while (raycast_get_collision(val, main) != 1 && i < 150)
	{
		val.x = val.x + (MAP_RES / tan(deg_to_rad(angle)));
		if (angle > 0 && angle < 180)
			val.y -= (double)MAP_RES;
		else
			val.y += (double)MAP_RES;
		i++;
	}*/
	return (val);
}

t_dblcoor	raycast_get_line(t_dblcoor pose, int angle, t_main *main)
{
	t_dblcoor	horiz;
	t_dblcoor	verti;

	//printf("VERTI = ");
	verti = raycast_next_verti(pose, angle, main);
	horiz = raycast_next_horiz(pose, angle, main);
	
	//printf("HORIZ = ");
	if (get_mini(verti, horiz) == 0)
		return (verti);
	else 
		return (horiz);
	//return (get_dblcenter_player(main));
}

void	raycast(t_main *main)
{
	t_dblcoor	pose;
	t_dblcoor	new;

	pose = get_dblcenter_player(main);
	new = raycast_get_line(pose, 210, main);
	//printf(">> %f, %f\n", calculateAngle(pose.x, pose.y, new.x, new.y, new.x , pose.y), new.y);
	draw_line(main->ray->x, main->ray->y, new.x, new.y);
	//printf(">> %d\n", get_max(new.x, new.y));
}
