/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:50:28 by loculy            #+#    #+#             */
/*   Updated: 2023/06/27 16:22:30 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_player_init_input(t_inpt *input, t_main *main)
{
	input->right = 0;
	input->left = 0;
	input->up = 0;
	input->down = 0;
	input->speed = PLY_SPEED * ft_delta_time(main);
}

void	player_get_move(t_main *main)
{
	t_inpt	input;

	ft_player_init_input(&input, main);
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_D))
		input.right = 1;
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_A))
		input.left = 1;
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_W))
		input.up = 1;
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_S))
		input.down = 1;
	if (input.up + input.down + input.left + input.right > 1)
		input.speed = input.speed - (input.speed / 3.5);
	if (input.up + input.down + input.left + input.right > 0)
		ft_player_move(main, input);
}

void	player_get_rotation(t_main *main)
{
	t_map	*map;

	map = main->map;
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_LEFT))
	{
		map->current.direc += 4;
		ft_player_rotation(main);
	}
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_RIGHT))
	{
		map->current.direc -= 4;
		ft_player_rotation(main);
	}
	mlx_mouse(main);
}

void	mlx_mouse(t_main *main)
{
	int		mx;
	int		my;
	t_map	*map;

	map = main->map;
	mlx_get_mouse_pos(main->mlx, &mx, &my);
	if (!(mx < 0 && mx > WIDTH))
	{
		if (mx < WIDTH / 2 - 5)
		{
			map->current.direc += 4;
			ft_player_rotation(main);
			printf("gauche\n");
		}
		else if (mx > WIDTH / 2 + 5)
		{
			map->current.direc -= 4;
			ft_player_rotation(main);
			printf("droite\n");
		}
		mlx_set_mouse_pos(main->mlx, WIDTH / 2, HEIGHT / 2);
	}
	//printf(">> mouse: x:%d |	windows: x:%d \n", mx, wx);
}
