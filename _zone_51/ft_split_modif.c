/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_modif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:31:38 by mmorue            #+#    #+#             */
/*   Updated: 2023/06/22 15:36:19 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		check_char_tab_split(char c, char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

static	void	*free_nb(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (0);
}

static	int	count_word(char const *str, char *c)
{
	int	i;
	int	k;
	int	count;

	i = 0;
	k = 1;
	count = 0;
	while (str[i])
	{
		if (check_char_tab(str[i], c) == 0 && k == 1)
		{
			count++;
			k = 0;
		}
		else if (check_char_tab(str[i], c) == 1)
			k = 1;
		i++;
	}
	return (count);
}

static char	**fill_tab(char **tab, char const *str, char *c)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	j = 0;
	nb = 0;
	while (str[i])
	{	
		if (check_char_tab(str[i], c) == 0 && str[i] != '\0')
		{
			while (check_char_tab(str[i], c) == 0 && str[i] != '\0')
				tab[nb][j++] = str[i++];
			tab[nb][j] = '\0';
			nb++;
			j = 0;
		}
		if (str[i])
		i++;
	}
	tab[nb] = NULL;
	return (tab);
}

static char	**size_tab(char **tab, char const *str, char *c)
{
	int	i;
	int	size;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (check_char_tab(str[i], c) == 0 && str[i] != '\0')
		{
			size = 0;
			while (check_char_tab(str[i], c) == 0 && str[i] != '\0')
			{
				size++;
				i++;
			}
			tab[nb] = malloc((size + 1) * sizeof(char));
			if (!tab[nb])
				return (free_nb(tab));
			nb++;
		}
		if (str[i])
			i++;
	}
	return (tab);
}


char	**ft_split(char const *str, char *c)
{	
	char	**tab;
	int		i;
	int		size;
	int		nb;

	i = 0;
	nb = 0;
	size = 0;
	if (str == 0)
		return (0);
	tab = malloc((count_word(str, c) + 1) * sizeof(str));
	if (!tab)
		return (0);
	if (size_tab(tab, str, c) == 0)
		return (0);
	return (fill_tab(tab, str, c));
}

//int	main(void)
//{	
//	int	i;
//	char c[3];
//
//	c[0] = ' ';
//	c[1] = ',';
//	c[2] = '\0';
//	i = 0;
//	char	tab[] = "      test    ok   sal,ok,oui";
//
//	char	**balek = ft_split(tab, c);
//	while (balek[i])
//		printf("%s\n",balek[i++]);
//	return (0);
//}
