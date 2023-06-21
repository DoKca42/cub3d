#include "cub3d.h"

//static void	ft_hook(void *param)
//{
//	t_main	*main;
//
//	main = param;
//	player_get_move(main);
//	player_get_action(main);
//}

int	main(int argc, char **argv)
{
	t_main		main;
	//t_map		map;
	//t_cooldown	cooldown;
	t_texture	text;

	if (argc != 2)
		return (ft_errormap("wrong number of args"));
	if (check_ber(argv[1]) == 0)
		return (0);
	main.text = &text;
	get_file(&main, argv[1]);
	ft_pars_raw_map(main.clean_file, main.text);
	/* ========= RAYCAST ========= */
	//main.map = &map;
//
	//ft_mlx_init_build(&main);
	//display_mini_map(&main);
	//display_mini_map_player(&main);
	//cooldown = init_cooldown();
	//main.cooldown = &cooldown;
//
	////printf("----- PLAYER -----\nx: %d\ny: %d\norientation %d\n\n", map.start.x, map.start.y, map.start.orientation);
//
	//mlx_loop_hook(main.mlx, ft_hook, &main);
	//mlx_loop(main.mlx);
	//mlx_terminate(main.mlx);
	ftm_free_all();
	return (0);
}
