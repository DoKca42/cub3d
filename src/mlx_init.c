#include "cub3d.h"

int	ft_mlx_init_build(t_main *main)
{
	main->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	return (1);
}