/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:54:00 by ngastana          #+#    #+#             */
/*   Updated: 2024/09/17 18:34:33 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static int	ft_wordlen(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static int	ft_wordnum(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			word++;
		while (s[i] != c && s[i])
			i++;
	}
	return (word);
}

static char	**ft_free(char **tab, int j)
{
	while (j-- > 0)
		free(tab[j]);
	free(tab);
	return (NULL);
}

static char	**ft_tab_maker(const char *s, char **tab, char c)
{
	int	len;
	int	j;

	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = ft_wordlen(s, c);
			tab[j] = ft_substr(s, 0, len);
			if (!tab[j])
				return (ft_free(tab, j));
			s += len;
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (0);
	tab = (char **)malloc((ft_wordnum(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (0);
	return (ft_tab_maker(s, tab, c));
}
