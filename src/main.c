#include "cub3d.h"

static void	ft_hook(void *param)
{
	t_main	*main;

	main = param;
	player_getmove(main);
}

int	main(int argc, char **argv)
{
	t_main	main;
	t_map	map;

	/* ========= PARSING ========= */
	/*
	if (argc != 2)
		return (ft_errormap("wrong number of args"));
	if (check_ber(argv[1]) == 0)
		return (0);
	get_file(&main, argv[1]);
	ft_pars_raw_map(main.raw_map);
	*/
	/* ========= RAYCAST ========= */
	map.map = ftm_malloc(6 * sizeof(char *));
    map.map[0] = ft_strdup("111111\n");
    map.map[1] = ft_strdup("100011\n");
    map.map[2] = ft_strdup("100N01\n");
    map.map[3] = ft_strdup("101001\n");
    map.map[4] = ft_strdup("111111");
    //map.map[0] = ft_strdup("000000\n");
	//map.map[1] = ft_strdup("000010\n");
	//map.map[2] = ft_strdup("000N00\n");
	//map.map[3] = ft_strdup("000000\n");
	//map.map[4] = ft_strdup("000000");
    map.map[5] = 0;
    map = init_map(map);
	main.map = &map;

	ft_mlx_init_build(&main);
	display_mini_map(&main);
	display_mini_map_player(&main);

	//printf("----- PLAYER -----\nx: %d\ny: %d\norientation %d\n\n", map.start.x, map.start.y, map.start.orientation);

	mlx_loop_hook(main.mlx, ft_hook, &main);
	mlx_loop(main.mlx);
	mlx_terminate(main.mlx);
	(void)argc;
	(void)argv;
	ftm_free_all();
	return (0);
}
