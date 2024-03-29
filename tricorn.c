/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kganeriw <kganeriw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:54:04 by kganeriw          #+#    #+#             */
/*   Updated: 2024/02/09 19:10:54 by kganeriw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	tricorn_init(t_data *data)
{
	data->width = WIDTH;
	data->height = HEIGHT;
	data->minreal = -2.0;
	data->maxreal = 2.0;
	data->min_i = -2.0;
	data->max_i = 2.0;
	data->color = 0xd7afd7;
	data->zoom = 200;
	data->max_n = 200;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Tricorn");
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->data = (int *)mlx_get_data_addr(data->img_ptr, &data->bpp, 
			&data->size_l, &data->endian);
	tricorn(data);
}

int	tricorn_n(double cr, double ci, double max_n)
{
	int		i;
	double	zr;
	double	zi;
	double	temp;

	zr = cr;
	zi = ci;
	i = 0;
	while (zr * zr + zi * zi <= 4 && i < max_n)
	{
		temp = -2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = temp;
		i++;
	}
	return (i);
}

void	tricorn(t_data *data)
{
	int	x;
	int	y;
	int	n;

	x = 100;
	while (x < data->width)
	{
		y = 100;
		while (y < data->height)
		{
			data->cre = find_real(x, data) * data->zoom * 0.008;
			data->cmi = find_imaginary(y, data) * data->zoom * 0.008;
			n = tricorn_n(data->cre, data->cim, data->max_n);
			data->data[y * WIDTH + x] = data->color * n;
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
