/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_dir_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:01:34 by fasharif          #+#    #+#             */
/*   Updated: 2023/06/14 17:03:32 by fasharif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_2(t_vars *vars)
{
	ft_putstr("you out\n");
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

void	test_right(t_vars *vars)
{
	if ((vars->s[vars->ind_i][vars->ind_j + 1] == 'E' && vars->collect == 0)
		|| vars->s[vars->ind_i][vars->ind_j + 1] == 'N')
		exit_1(vars, 0, vars->s[vars->ind_i][vars->ind_j + 1]);
	else if (vars->s[vars->ind_i][vars->ind_j + 1] != 'E')
		move_right(vars);
}

void	test_down(t_vars *vars)
{
	if ((vars->s[vars->ind_i + 1][vars->ind_j] == 'E' && vars->collect == 0)
		|| vars->s[vars->ind_i + 1][vars->ind_j] == 'N')
		exit_1(vars, 0, vars->s[vars->ind_i + 1][vars->ind_j]);
	else if (vars->s[vars->ind_i + 1][vars->ind_j] != 'E')
		move_down(vars);
}

void	test_left(t_vars *vars)
{
	if ((vars->s[vars->ind_i][vars->ind_j - 1] == 'E' && vars->collect == 0)
		|| vars->s[vars->ind_i][vars->ind_j - 1] == 'N')
		exit_1(vars, 0, vars->s[vars->ind_i][vars->ind_j - 1]);
	else if (vars->s[vars->ind_i][vars->ind_j - 1] != 'E')
		move_left(vars);
}

void	test_up(t_vars *vars)
{
	if ((vars->s[vars->ind_i - 1][vars->ind_j] == 'E' && vars->collect == 0)
		|| vars->s[vars->ind_i - 1][vars->ind_j] == 'N')
		exit_1(vars, 0, vars->s[vars->ind_i - 1][vars->ind_j]);
	else if (vars->s[vars->ind_i - 1][vars->ind_j] != 'E')
		move_up(vars);
}
