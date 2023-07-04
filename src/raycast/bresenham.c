/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:22:19 by loculy            #+#    #+#             */
/*   Updated: 2023/07/04 15:59:44 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void bresenham(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
 
    dx=x1-x0;
    dy=y1-y0;
     
    x=x0;
    y=y0;
     
    p=2*dy-dx;
     
    while(x<x1)
    {
        if(p>=0)
        {
           mlx_put_pixel(get_main(0)->map->ray_lines, (uint32_t)x, (uint32_t)y, ft_pixel(255, 225, 70, 255));
            y=y+1;
            p=p+2*dy-2*dx;
        }
        else
        {
            mlx_put_pixel(get_main(0)->map->ray_lines, (uint32_t)x, (uint32_t)y, ft_pixel(255, 225, 70, 255));
            p=p+2*dy;
        }
    x=x+1;
    }
}