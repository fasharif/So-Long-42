/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:59:23 by fasharif          #+#    #+#             */
/*   Updated: 2023/06/14 17:03:32 by fasharif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	test_1(char **p, int j, int *i)
{
	*i = 0;
	while (p[*i])
	{
		if (j != ft_strlen(p[*i]))
			return (0);
		*i += 1;
	}
	return (1);
}

static int	test_2(char **p, int i)
{
	int	k;

	k = 0;
	while (p[0][k] == '1' && p[i - 1][k] == '1')
		k++;
	return (k);
}

static int	test_3(char **p, int j)
{
	int	i;

	i = 0;
	while (p[i])
	{
		if (p[i][0] != '1' || p[i][j - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	test_4(char **p)
{
	int	i;
	int	j;

	i = 0;
	while (p[i])
	{
		j = 0;
		while (p[i][j])
		{
			if (p[i][j] != '0' && p[i][j] != '1' && p[i][j] != 'C'
					&& p[i][j] != 'E' && p[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	test_map(char **p)
{
	int	i;
	int	j;
	int	w;

	w = 0;
	if (!p)
		return (0);
	j = ft_strlen(p[0]);
	if (test_1(p, j, &i) == 0)
		return (0);
	if (test_2(p, i) != j)
		return (0);
	if (test_3(p, j) == 0)
		return (0);
	if (test_4(p) == 0)
		return (0);
	w = w + find_c(p, 'C');
	w = w + find_c(p, 'P');
	w = w + find_c(p, 'E');
	if (w != 3)
		return (0);
	return (1);
}
