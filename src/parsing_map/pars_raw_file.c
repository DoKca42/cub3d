/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_raw_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seya <seya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:34:49 by mmorue            #+#    #+#             */
/*   Updated: 2023/06/27 23:10:15 by seya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**check_routine(char *raw_map, char **texture, char *to_compare)
{
	char tab[3];

	tab[0] = ' ';
	tab[1] = '\t';
	tab[2] = '\0';
	if (!texture)
	{
		texture = ft_split_modif(raw_map, tab);
		if (ft_strcmp(texture[0], to_compare) != 0 || strlen_doubletab(texture) != 2)
			ft_errormap("Wrong texture format");
	}
	else
		ft_errormap("Double texture");
	return (texture);
}

int check_valide_format(char *raw_map, int *i, t_texture *text)
{
	if(raw_map[*i] == 'N')
		text->NO = check_routine(raw_map, text->NO, "NO");
	if(raw_map[*i] == 'S')
		text->SO = check_routine(raw_map, text->SO, "SO");
	if(raw_map[*i] == 'W')
		text->WE = check_routine(raw_map, text->WE, "WE");
	if(raw_map[*i] == 'E')
		text->EA = check_routine(raw_map, text->EA, "EA");
	return (0); // flag
}

char **check_color_format(char *raw_map, int *i, char **rgb)
{
	int		k;
	char	*color_tab;
	char	tab[4];

	tab[0] = ' ';
	tab[1] = ',';
	tab[2] = '\t';
	tab[3] = '\0';
	k = *i;

	if (raw_map[k + 1] != ' ' && raw_map[k + 1] != '\t')
		ft_errormap("Wrong color format");
	k++;
	while (raw_map[k] == ' ' || raw_map[k] == '\t')
		k++;
	color_tab = &raw_map[k];
	check_color_char(color_tab);
	rgb = ft_split_modif(color_tab, tab);
	if (strlen_doubletab(rgb) != 3)
		ft_errormap("Wrong color format");
	return (rgb);
}



int check_char(char *raw_map, int *i, t_main *main)
{
	if (raw_map[*i] == '\0')
		return (0);
	else if (raw_map[*i] != 'N' && raw_map[*i] != 'S' && raw_map[*i] != 'W' && raw_map[*i] != 'E' && raw_map[*i] != 'F' && raw_map[*i] != 'C' && raw_map[*i] != '1' && raw_map[*i] != ' ' && raw_map[*i] != '\n' && raw_map[*i] != '\t')
		ft_errormap("Wrong format of file");
	else if (raw_map[*i] == 'N' || raw_map[*i] == 'S' || raw_map[*i] == 'W' || raw_map[*i] == 'E')
		check_valide_format(raw_map, i, main->text);
	else if (raw_map[*i] == 'F')
	{
		main->text->F = check_color_format(raw_map, i, main->text->F);
		convert_color(main->text->F, main->sol);
	}
	else if (raw_map[*i] == 'C')
	{
		main->text->C = check_color_format(raw_map, i, main->text->C);
		convert_color(main->text->C, main->ciel);
	}
	return (0); // flag
}

void ft_pars_raw_map(char **raw_map, t_main *main)
{
	int i;
	int k;
	int start_map;

	i = 0;
	k = 0;
	while(raw_map[k] != 0)
	{
		while(raw_map[k][i] != 0 && raw_map[k][i] != '1' && raw_map[k][i] != '0')
		{
			skip_space(raw_map[k], &i);
			if(check_char(raw_map[k], &i, main) == 0)
				break;
			i++;
		}
		if(raw_map[k][i] == '1' || raw_map[k][i] == '0')
			break;
		i = 0;
		k++;
	}
	if (check_valide_texture(main->text) == 0 || raw_map[k] == 0)
		ft_errormap("Wrong file format");
	start_map = k;
	while(raw_map[k] && check_char_for_map(raw_map[k]) == 1)
		k++;
	if(raw_map[k] != 0)
		ft_errormap("Wrong file format");
	main->map_tab = ftm_malloc((k - start_map + 1) * sizeof(char *));
	main->map_tab[k - start_map] = 0;
	i = 0;
	while(start_map < k)
	{
		main->map_tab[i] = ft_strdup_(raw_map[start_map]);
		start_map++;
		i++;
	}
	//k = -1;
	//while(main->map_tab[++k])
	//	printf("%s\n", main->map_tab[k]);

	//printf("%d\n", k);
	//k = -1;
	//while(main->text->F[++k] != 0)
	//	printf("%s\n", main->text->F[k]);
	//k = -1;
	//while(main->text->C[++k])
	//	printf("%s\n", main->text->C[k]);
	//k = -1;
	//while(text->NO[++k])
	//{
	//	printf("%s\n", text->NO[k]);
	//	printf("%s\n", text->SO[k]);
	//	printf("%s\n", text->EA[k]);
	//	printf("%s\n", text->WE[k]);
	//}
	//k = -1;
	//k = -1;
	//while(text->F[++k])
	//	printf("%s\n", text->F[k]);
	//k = -1;
	//while(text->F[++k])
	//	printf("%s\n", text->C[k]);
}
