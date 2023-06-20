#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_main	main;
	//t_map	map;
//
	//
	//map.map = ftm_malloc(6 * sizeof(char *));
    //map.map[0] = ft_strdup("111111");
    //map.map[1] = ft_strdup("100011");
    //map.map[2] = ft_strdup("100N01");
    //map.map[3] = ft_strdup("101001");
    //map.map[4] = ft_strdup("111111");
    //map.map[5] = 0;
    //map = init_map(map);
	//main.map = map;
	//i = 0;
	////while (i < map.hitbox_size)
	////{
	////	printf("x : %d | y : %d\n", map.hitbox[i].x, map.hitbox[i].y);
	////	i++;
	////}
	//ft_mlx_init_build(&main);
	//display_mini_map(&main);
	//mlx_loop(main.mlx);
	//mlx_terminate(main.mlx);
	//(void)argc;
	//(void)argv;
	if (argc != 2)
		return (ft_errormap("wrong number of args"));
	if (check_ber(argv[1]) == 0)
		return (0);
	get_file(&main, argv[1]);
	ft_pars_raw_map(main.raw_map);
	ftm_free_all();
	return (0);
}
