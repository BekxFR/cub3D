/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:10:11 by chillion          #+#    #+#             */
/*   Updated: 2023/01/20 18:06:58 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_draw_line_dir3d(t_v *v, int y, int x, double degree, double i, double *tab)
{
	(void)y;
	double pi = 3.1415926535897932384626433832;
	// int degree = 270;
	double resultx = find_end_x(degree + i); //arrondi
	double resulty = find_end_y(degree + i); //arrondi
	double pixelx = x + (XSIZE / 2);
	double pixely = y + (XSIZE / 2);
	// printf("endx=%Lf, endy=%Lf, deltax=%Lf, deltay=%Lf, pixelx=%Lf et pixely=%Lf\n", endx, endy, deltax, deltay, pixelx, pixely);
	// exit(0);
	int pixels = sqrt((resultx * resultx) + (resulty * resulty));
	resultx /= pixels;
	resulty /= pixels;
	// printf("degree %Lf, i %Lf, (degree + i) %Lf\n", degree, i, (degree + i));
	double view = 30 - i; ;
	if (view < 0)
		view *= -1;
	while (1)
	{
		if (v->m.map[(int)pixely / XSIZE][(int)pixelx / XSIZE] == '1')
		{
			*tab = ((y - pixely) * sin((90) * pi / 180) / sin((180 - 90 - (view)) * pi / 180));	// taille avec fish eye
			// il faut peut etre stocker pixely du centre. comment faire ? lancer un rayon a angle 0 et le garder
			*tab = *tab * cos((view) * pi / 180);  // correction fish eye
			// printf("*tab %d\n", *tab);
			return ;
		}
		ft_my_mlx_pixel_put(&v->ig, pixely, pixelx, ft_rgb_to_int(0, 50, 150, 250));
		pixelx += resultx;
		pixely += resulty;
	}
	// mlx_put_image_to_window(v->mlx, v->win, v->ig.img, 0, 0);
	printf("c3\n");

}

void	ft_draw_line_circle3d(t_v *v, int y, int x)
{
	if (v->ig2.img)
		mlx_destroy_image(v->mlx, v->ig2.img);
	v->ig2.img = mlx_new_image(v->mlx, 320, 200);
	if (!v->ig2.img)
		ft_stop_all(v, 1);
	v->ig2.ad = mlx_get_data_addr(v->ig2.img, &v->ig2.bpp, &v->ig2.llen, &v->ig2.en);
	int right = v->m.degree + 30;
	double left = v->m.degree - 30;
	double i = 0.0;
	int index = 0;
	
	double tab[320];
	if (left < 0)
		left = 360 + left;
	if (right > 360)
		right = right - 360;
	while(index <= 320)
	{
		ft_draw_line_dir3d(v, y, x, left,  i, &tab[index]);
		// printf("tab[%d] : %f\n", index, tab[index]);
		i = i + 0.1875;
		index++;
		if ((left + i) > 360)
			left = -30;
	}
	// printf("c1\n");
	int z = 0;
	index = 0;
	while(index <= 320)
	{
		// printf("TEST\n");
		// printf("tab[index]: %f\n", tab[index]);
		// printf("(double)(64 / tab[index] * 277) %f\n",  (double)(64 / tab[index] * 277));
		// printf("END\n");
		tab[index] = ((double)(64 / tab[index] * 277)); // a l echelle
		while(z <= tab[index])
		{
			// printf("z %i, index %i\n", z, index);
			// printf("c1bis ((200 / 2) - (tab[index] / 2) + z) %f,  (index + 100) %d\n", ((200 / 2) - (tab[index] / 2) + z), (index + 100));
			ft_my_mlx_pixel_put(&v->ig2, ((tab[index] / 2) + z), (index + 2), ft_rgb_to_int(0, 255, 0, 255));
			// printf("c1ter\n");
			z++;
		}
		// break ;
		z = 0;
		index++;
	}
	// mlx_put_image_to_window(v->mlx, v->win, v->ig2.img, ((v->m.x) * XSIZE / 2), 0);
}