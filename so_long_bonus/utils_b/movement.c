/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:01:58 by fasharif          #+#    #+#             */
/*   Updated: 2023/06/14 17:03:32 by fasharif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	change_indice(char *c, char *v)
{
	*c = '0';
	*v = 'P';
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit_1(vars, keycode, 0);
	if (keycode == 2)
		if ((vars->s[vars->ind_i][vars->ind_j + 1] != 'P'
			&& vars->s[vars->ind_i][vars->ind_j + 1] != '1'))
			test_right(vars);
	if (keycode == 1)
		if ((vars->s[vars->ind_i + 1][vars->ind_j] != 'P'
			&& vars->s[vars->ind_i + 1][vars->ind_j] != '1'))
			test_down(vars);
	if (keycode == 0)
		if ((vars->s[vars->ind_i][vars->ind_j - 1] != 'P'
			&& vars->s[vars->ind_i][vars->ind_j - 1] != '1'))
			test_left(vars);
	if (keycode == 13)
		if ((vars->s[vars->ind_i - 1][vars->ind_j] != 'P'
			&& vars->s[vars->ind_i - 1][vars->ind_j] != '1'))
			test_up(vars);
	mlx_clear_window(vars->mlx, vars->win);
	key_hooken(vars);
	render(vars);
	return (0);
}
