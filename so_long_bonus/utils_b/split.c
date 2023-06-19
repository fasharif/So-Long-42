/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:02:11 by fasharif          #+#    #+#             */
/*   Updated: 2023/06/14 17:03:32 by fasharif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	bigstr(char const *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!s)
		return (0);
	while (*s && *s == c)
		s++;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) || (s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static int	smalstr(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char const	*skip(char const *s, char c)
{
	while (s && *s == c)
		s++;
	return (s);
}

static char	**fret(char **p)
{
	free (p);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		len;
	int		j;
	int		i;
	int		k;

	j = bigstr(s, c);
	i = 0;
	p = (char **)malloc(sizeof(char *) * (j + 1));
	if (!p || !s)
		return (NULL);
	while (i < j)
	{
		s = skip(s, c);
		len = smalstr(s, c);
		p[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!p[i])
			return (fret(p));
		k = 0;
		while (k < len)
			p[i][k++] = *s++;
		p[i++][k] = '\0';
	}
	p[i] = NULL;
	return (p);
}
