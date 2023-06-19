/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:58:59 by fasharif          #+#    #+#             */
/*   Updated: 2023/06/14 17:03:32 by fasharif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	test_map_put_photo(t_vars *vars)
{
	if (vars->s[vars->tb_i][vars->tb_j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->wall, vars->tb_y, vars->tb_z);
	if (vars->s[vars->tb_i][vars->tb_j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->free, vars->tb_y, vars->tb_z);
	if (vars->s[vars->tb_i][vars->tb_j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->gold, vars->tb_y, vars->tb_z);
	if (vars->s[vars->tb_i][vars->tb_j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->me, vars->tb_y, vars->tb_z);
	if (vars->s[vars->tb_i][vars->tb_j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->exit, vars->tb_y, vars->tb_z);
}

int	render(t_vars *vars)
{
	vars->tb_i = 0;
	vars->tb_z = -50;
	while (vars->s[vars->tb_i])
	{
		vars->tb_j = 0;
		vars->tb_z = vars->tb_z + 50;
		vars->tb_y = 0;
		while (vars->s[vars->tb_i][vars->tb_j])
		{
			test_map_put_photo(vars);
			vars->tb_y = vars->tb_y + 50;
			vars->tb_j += 1;
		}
		vars->tb_i += 1;
	}
	return (0);
}
