/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_en_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:02:18 by fasharif          #+#    #+#             */
/*   Updated: 2023/06/14 17:03:32 by fasharif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_righten(t_vars *vars)
{
	change_indiceen(&(vars->s[vars->ind_ien][vars->ind_jen]),
		&(vars->s[vars->ind_ien][vars->ind_jen + 1]));
	vars->ind_jen += 1;
}

void	move_downen(t_vars *vars)
{
	change_indiceen(&(vars->s[vars->ind_ien][vars->ind_jen]),
		&(vars->s[vars->ind_ien + 1][vars->ind_jen]));
	vars->ind_ien += 1;
}

void	move_leften(t_vars *vars)
{
	change_indiceen(&(vars->s[vars->ind_ien][vars->ind_jen]),
		&(vars->s[vars->ind_ien][vars->ind_jen - 1]));
	vars->ind_jen -= 1;
}

void	move_upen(t_vars *vars)
{
	change_indiceen(&(vars->s[vars->ind_ien][vars->ind_jen]),
		&(vars->s[vars->ind_ien - 1][vars->ind_jen]));
	vars->ind_ien -= 1;
}
