/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:02:32 by fasharif          #+#    #+#             */
/*   Updated: 2023/06/14 17:03:32 by fasharif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*test(long *n, long *i, int *k, char *p)
{
	if ((*n) < 0)
	{
		(*i)++;
		(*k)++;
	}
	p = (char *)malloc(sizeof(char) * ((*k) + 1));
	if (!p)
		return (NULL);
	if ((*n) < 0)
	{
		p[0] = '-';
		(*n) *= -1;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	long	i;
	long	m;
	int		k;
	char	*p;

	k = 1;
	i = n;
	m = n;
	p = NULL;
	while (i >= 10 || i <= -10)
	{
		i = i / 10;
		k++;
	}
	i = 0;
	p = test(&m, &i, &k, p);
	if (p == NULL)
		return (NULL);
	p[k] = '\0';
	while (i < k)
	{
		p[--k] = m % 10 + 48;
		m = m / 10;
	}
	return (p);
}
