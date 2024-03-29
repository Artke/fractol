/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kganeriw <kganeriw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:08:25 by kganeriw          #+#    #+#             */
/*   Updated: 2024/02/09 20:16:35 by kganeriw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_fractol(t_data *data, double dx, double dy)
{
	double	range_real;
	double	range_image;

	range_image = data->maxreal - data->minreal;
	range_image = data->max_i - data->min_i;
	data->minreal += dx * range_real;
	data->maxreal += dx * range_real;
	data->min_i += dy * range_image;
	data->max_i += dy * range_image;
}

void	move_julia(t_data *data, double dx, double dy)
{
	double	old_center_x;
	double	old_center_y;

	old_center_x = data->center_x;
	old_center_y = data->center_y;
	data->center_x += dx / (data->zoom);
	data->center_y += dy / (data->zoom);
}

void	movement(int key, t_data *data)
{
	if (data->fractol == 0 || data->fractol == 2)
	{
		if (key == 13)
			move_fractol(data, 0, 0.1);
		else if (key == 2)
			move_fractol(data, -0.1, 0);
		else if (key == 1)
			move_fractol(data, 0, -0.1);
		else if (key == 0)
			move_fractol(data, 0.1, 0);
	}
	else if (data->fractol == 1)
	{
		if (key == 1)
			move_julia(data, 0, -0.1);
		else if (key == 2)
			move_julia(data, -0.1, 0);
		else if (key == 13)
			move_julia(data, 0, 0.1);
		else if (key == 0)
			move_julia(data, 0.1, 0);
	}
}

int	close_button_hook(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data);
	exit(0);
	return (0);
}
