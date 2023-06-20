/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:50:28 by loculy            #+#    #+#             */
/*   Updated: 2023/06/20 18:12:58 by loculy           ###   ########.fr       */
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

void	player_getmove(t_main *main)
{
	t_inpt	input;

	ft_player_init_input(&input, main);
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_D)
		|| mlx_is_key_down((void *)main->mlx, MLX_KEY_RIGHT))
		input.right = 1;
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_A)
		|| mlx_is_key_down((void *)main->mlx, MLX_KEY_LEFT))
		input.left = 1;
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_W)
		|| mlx_is_key_down((void *)main->mlx, MLX_KEY_UP))
		input.up = 1;
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_S)
		|| mlx_is_key_down((void *)main->mlx, MLX_KEY_DOWN))
		input.down = 1;
	if (input.up + input.down + input.left + input.right > 1)
		input.speed = input.speed - (input.speed / 3.5);
	if (input.up + input.down + input.left + input.right > 0)
		ft_player_move(main, input);
}
