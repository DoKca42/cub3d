/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_raw_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:34:49 by mmorue            #+#    #+#             */
/*   Updated: 2023/06/21 17:43:24 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
int	strlen_doubletab(char **tab)
{
	int k;

	k = 0;
	while(tab[k])
		k++;
	return (k);
}
void skip_space(char *raw_map, int *i)
{
	while(raw_map[*i] == ' ' || raw_map[*i] == '\n' || raw_map[*i] == '\t')
		*i = *i + 1;
}

char	**check_routine(char *raw_map, char **texture, char *to_compare)
{
	if(!texture)
	{
		texture = ft_split(raw_map, ' ');
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

int check_color_format(char *raw_map, int *i, t_texture *text)
{
	int		k;
	int		size;
	char	*color_tab;
	size = 0;
	k = *i;
	(void)text;
	if (raw_map[k + 1] != ' ')
		ft_errormap("Wrong color format");
	k++;
	while (raw_map[k] == ' ')
		k++;
	color_tab = &raw_map[k];
	printf("%s", color_tab);
	return (0);
}
int check_char(char *raw_map, int *i, t_texture *text)
{
	if (raw_map[*i] == '\0')
		return (0);
	else if (raw_map[*i] != 'N' && raw_map[*i] != 'S' && raw_map[*i] != 'W' && raw_map[*i] != 'E' && raw_map[*i] != 'F' && raw_map[*i] != 'C' && raw_map[*i] != '1' && raw_map[*i] != ' ' && raw_map[*i] != '\n' && raw_map[*i] != '\t')
		ft_errormap("Wrong format of file");
	else if (raw_map[*i] == 'N' || raw_map[*i] == 'S' || raw_map[*i] == 'W' || raw_map[*i] == 'E')
		check_valide_format(raw_map, i, text);
	else if (raw_map[*i] == 'F' || raw_map[*i] == 'C')
		check_color_format(raw_map, i, text); // flag
	return (0); // flag
}

int check_valide_texture(t_texture *text)
{
	if (!text->NO || !text->WE || !text->SO || !text->EA || !text->F || !text->C)
		return (0);
	else
		return (1);
}
void ft_pars_raw_map(char **raw_map, t_texture *text)
{
	int i;
	int k;
	i = 0;
	k = 0;
	text->NO = NULL;
	text->SO = NULL;
	text->EA = NULL;
	text->WE = NULL;
	text->F = NULL;
	text->C = NULL;
	while(raw_map[k])
	{
		while(raw_map[k][i] != 0 && raw_map[k][i] != '1' && raw_map[k][i] != '0')
		{
			skip_space(raw_map[k], &i);
			if(check_char(raw_map[k], &i, text) == 0)
				break;
			i++;
		}
		if(raw_map[k][i] == '1' || raw_map[k][i] == '0')
			break;
		i = 0;
		k++;
	}
	printf("%d\n", k);
	if (check_valide_texture(text) == 0)
		ft_errormap("Wrong file format");
	//k = 0;
	//while(text->NO[k])
	//{
	//	printf("%s\n", text->NO[k]);
	//	printf("%s\n", text->NO[k]);
	//	printf("%s\n", text->NO[k]);
	//	printf("%s\n", text->NO[k]);
	//}
}
