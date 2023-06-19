/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:05:00 by loculy            #+#    #+#             */
/*   Updated: 2023/06/19 11:29:05 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "stdio.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"
# include "../memory_manager/memory_manager.h"
# include "../lib/ft_rprintf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"

# define TEXT_RES 64
# define WIDTH 2560
# define HEIGHT 1440
# define TOOLBAR 130

# define PL_HTB_W 64
# define PL_HTB_H 64

# define PL_MOVE 4
/*
typedef struct s_memng
{
	void			*mem;
	int				type;
	int				fd;
	struct s_memng	*next;
}	t_memng;


t_memng	*ft_memnew_manager(void *mem, int type, int fd);
void	ft_memadd_back_manager(t_memng **lst, t_memng *new);
void	*ftm_malloc(size_t sz, t_memng **mng);
void	ftm_free(void *mem, t_memng **mng);
int		ftm_open(char *pathname, int flags, t_memng **mng);
void	ftm_close(int fd, t_memng **mng);
void	ftm_free_all(t_memng **mng);
*/
#endif