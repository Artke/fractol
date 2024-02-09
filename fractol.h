/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kganeriw <kganeriw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:10:10 by kganeriw          #+#    #+#             */
/*   Updated: 2024/02/09 20:21:49 by kganeriw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx_fractol/mlx.h"
# include	"./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>

# define HEIGHT 1000
# define WIDTH 1000

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			fractol;
	int			color;
	int			width;
	int			height;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	double		center_x;
	double		center_y;
	double		minreal;
	double		maxreal;
	double		min_i;
	double		max_i;
	double		cre;
	double		cim;
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
	double		zoom;
	double		max_n;
	int			random;
}				t_data;

// Extras
int			fract_select(int argc, char **argv, t_data *data);
int			julia_select(char **argv, t_data *data);

// Mandelbrot

void		mandelbrot_init(t_data *data);
int			find_n(double cr, double ci, double max_n);
void		mandelbrot(t_data *data);
double		find_real(int x, t_data *data);
double		find_imaginary(int y, t_data *data);

// Julia
void		julia_init1(t_data *data);
void		julia_init2(t_data *data);
void		julia_init3(t_data *data);
int			julia_n(t_data *data);
void		julia(t_data *data);

// Tricorn
void		tricorn_init(t_data *data);
int			tricorn_n(double cr, double ci, double max_n);
void		tricorn(t_data *data);

// bonus

void		ft_zoom(t_data *data);
void		ft_dezoom(t_data *data);
int			mouse_hook(int mouse_hook, int x, int y, t_data *data);
int			keys(int key, t_data *data);
void		move_fractol(t_data *data, double dx, double dy);
int			close_button_hook(t_data *data);
void		movement(int key, t_data *data);

#endif