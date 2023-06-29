/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:10:24 by mmorue            #+#    #+#             */
/*   Updated: 2023/06/29 18:33:40 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_hook(void *param)
{
	t_main	*main;

	main = param;
	player_get_move(main);
	player_get_rotation(main);
	player_get_action(main);
}

int	main(int argc, char **argv)
{
	t_main		main;
	t_map		map;
	t_cooldown	cooldown;
	t_raycast	raycast;
	t_texture	text;
	t_rgb		sol;
	t_rgb		ciel;
	/* ========= PARSING ========= */
	
	if (argc != 2)
		return (ft_errormap("wrong number of args"));
	if (check_ber(argv[1]) == 0)
		return (0);
	main.text = &text;
	main.ciel = &ciel;
	main.sol = &sol;
	ft_bzero(main.text, sizeof(t_texture));
	get_file(&main, argv[1]);
	ft_pars_raw_map(main.clean_file, &main);
	
	/* ========= RAYCAST ========= */
	map.map = main.map_tab;
	map = init_map(map);
	main.map = &map;
//
	get_main(&main);
	ft_mlx_init_build(&main);
	init_main(&main);
	display_mini_map(&main);
//
	display_mini_map_player(&main);
	init_ray_view(&main);
	init_grid(&main);
	grid_mlx(&main);
	cooldown = init_cooldown();
	main.cooldown = &cooldown;
	main.ray = &raycast;
	ray_set_player_pose(&main);
//
	mlx_loop_hook(main.mlx, ft_hook, &main);
	mlx_loop(main.mlx);
	mlx_terminate(main.mlx);
	ftm_free_all();
	return (0);
}

//int i = 0;
//while (text.no[i])
//	printf("%s\n", text.no[i++]);
//i = 0;
//while (text.so[i])
//	printf("%s\n", text.so[i++]);
//i = 0;
//while (text.we[i])
//	printf("%s\n", text.we[i++]);
//i = 0;
//while (text.ea[i])
//	printf("%s\n", text.ea[i++]);		
//i = 0;
//while (text.f[i])
//	printf("%s\n", text.f[i++]);
//i = 0;
//while (text.c[i])
//	printf("%s\n", text.c[i++]);
//i = 0;
//while (main.map_tab[i])
//	printf("%s\n", main.map_tab[i++]);
//i = 0;
//while (main.clean_file[i])
//	printf("%s\n", main.clean_file[i++]);		
