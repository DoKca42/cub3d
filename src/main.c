/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:46:27 by loculy            #+#    #+#             */
/*   Updated: 2023/07/06 14:35:43 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_hook(void *param)
{
	t_main	*main;
	int		update;

	update = 0;
	main = param;
	update += player_get_move(main);
	update += player_get_rotation(main);
	update += player_get_action(main);
	get_fire(main);
	get_reload(main, 0);
	if (update > 0)
		ft_player_rotation(main);
}

void display_ground_sky(t_main *main)
{
	int		i;

	i = -1;
	mlx_image_t **ground_sky;

	ground_sky = ftm_malloc(2 * sizeof(mlx_image_t));
	while(++i < 2)
	{
		ground_sky[i] = mlx_new_image(main->mlx, WIDTH , HEIGHT / 2);
		mlx_image_to_window(main->mlx, ground_sky[i], 0, i * (HEIGHT / 2));
	}
	fill_color_image(ground_sky[0], ft_pixel(ft_atoi(main->text->f[0]), ft_atoi(main->text->f[1]), ft_atoi(main->text->f[2]), 255));
	fill_color_image(ground_sky[1], ft_pixel(ft_atoi(main->text->c[0]), ft_atoi(main->text->c[1]), ft_atoi(main->text->c[2]), 255));
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
	
	get_main(&main);
	ft_mlx_init_build(&main);
	init_main(&main);
	
	display_mini_map(&main);

	display_mini_map_player(&main);
	init_ray_view(&main);	
	cooldown = init_cooldown();
	main.cooldown = &cooldown;
	main.ray = &raycast;
	ray_set_player_pose(&main);
	
	load_texture(&main);
	hand_display(&main, 0);
	
	wall_textures_load(&main);
	mlx_loop_hook(main.mlx, ft_hook, &main);
	mlx_loop(main.mlx);
	mlx_terminate(main.mlx);
	ftm_free_all();
	return (0);
}