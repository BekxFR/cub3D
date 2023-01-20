


// void	ft_draw_ratio(t_v *v, t_data sprite, int y, int x)
// {
// 	double		i;
// 	double		j;
// 	int			color;
// 	double		ratio;

// 	j = 0;
// 	ratio = ((double)sprite.w / (double)(((v->m.y) * v->m.x)));
// 	y = y - (((v->m.y) * v->m.x) / 2);
// 	x = x - (((v->m.y) * v->m.x) / 2);
// 	while (j < (double)((v->m.y) * v->m.x))
// 	{
// 		i = 0;
// 		while (i < (double)((v->m.y) * v->m.x))
// 		{
// 			color = ft_get_color(&sprite, i * ratio, j * ratio);
// 			if (color != 0x000000FF)
// 				ft_my_mlx_pixel_put(&v->ig, (y + i), (x + j), color);
// 			i++;
// 		}
// 		j++;
// 	}
// }


/*
	static int i = 0;
	static int tmp_degree = 0;

	if (tmp_degree != v->m.degree)
	{	
		i = 0;
		tmp_degree = v->m.degree;
	}
	if (v->m.py > 0)
	{
		if (i == 0 && i++ > -1)
		{
			int tmp_ppx = v->m.ppx + find_wall_x(v->m.degree);
			tmp_ppx = ((tmp_ppx + (XSIZE / 2)) / XSIZE);
			int tmp_ppy = v->m.ppy + find_wall_y(v->m.degree);
			tmp_ppy = ((tmp_ppy + (XSIZE / 2)) / XSIZE);
			if (v->m.map[tmp_ppy][tmp_ppx] == '1')
				return (0);
			v->m.ppy += find_end_y(v->m.degree);
			v->m.ppx += find_end_x(v->m.degree);
		}
*/

/* 
void	ft_paint_player_pixel(t_v *v, int y, int x)
{
	int	i;
	int	j;
	int ref;
	int	dif;
	int	dif2;

	i = 0;
	ref = 0;
	dif = 32;
	dif2 = 32;
	while (i < XSIZE)
	{
		j = 0;
		while (j < XSIZE)
		{
			if (j != 0)
			{
				if ((i > ((XSIZE / 3) - 1) && i < (((XSIZE / 3) * 2) + 1)) && (j > ((XSIZE / 3) - 1) && j < (((XSIZE / 3) * 2) + 2)))
				{
					if (i % 2 == 0 && ref == i)
					{
						dif++;
						dif2--;
						ref = 0;
					}
					if (j >= dif2 && j <= dif)
					{
						ft_my_mlx_pixel_put(&v->ig, y + i, x + j, ft_rgb_to_int(0, 255, 255, 255));
					}
				}
			}
			j++;
		}
		i++;
		ref = i;
	}
}
 */


// void	ft_draw_pix_line_angle_right(t_v *v, int y, int x, int degree)
// {
// 	(void)y;
// 	// int degree = 270;
// 	double resultx = find_end_x(degree);
// 	double resulty = find_end_y(degree);
// 	double endx = (x + resultx);
// 	double endy = (y + resulty); // + pca on renvoie - ou + indifferement
// 	double deltax = endx - x ;
// 	double deltay = endy - y;
// 	double pixelx = x + (XSIZE / 2);
// 	double pixely = y + (XSIZE / 2);
// 	// exit(0);
// 	int pixels = sqrt((deltax * deltax) + (deltay * deltay));
// 	deltax /= pixels;
// 	deltay /= pixels;
// 	while (1)
// 	{
// 		if (v->m.map[((int)pixely) / XSIZE][(int)pixelx / XSIZE] == '1' || v->m.map[(int)pixely / XSIZE][((int)pixelx) / XSIZE] == '1')
// 			break ;
// 		ft_my_mlx_pixel_put(&v->ig, pixely, pixelx, ft_rgb_to_int(0, 50, 150, 250));
// 		pixelx += deltax;
// 		pixely += deltay;
// 		// --pixels;
// 	}
// }

// void	ft_draw_pix_line_angle_left(t_v *v, int y, int x, int degree)
// {
// 	(void)y;
// 	// int degree = 270;
// 	double resultx = find_end_x(degree);
// 	double resulty = find_end_y(degree);
// 	double endx = (x + resultx);
// 	double endy = (y + resulty); // + pca on renvoie - ou + indifferement
// 	double deltax = endx - x ;
// 	double deltay = endy - y;
// 	double pixelx = x + (XSIZE / 2);
// 	double pixely = y + (XSIZE / 2);
// 	// exit(0);
// 	int pixels = sqrt((deltax * deltax) + (deltay * deltay));
// 	deltax /= pixels;
// 	deltay /= pixels;
// 	while (1)
// 	{
// 		if (v->m.map[((int)pixely) / XSIZE][(int)pixelx / XSIZE] == '1' || v->m.map[(int)pixely / XSIZE][((int)pixelx) / XSIZE] == '1')
// 			break ;
// 		ft_my_mlx_pixel_put(&v->ig, pixely, pixelx, ft_rgb_to_int(0, 50, 150, 250));
// 		pixelx += deltax;
// 		pixely += deltay;
// 		// --pixels;
// 	}
// }



// void	ft_draw_pix_line_dir(t_v *v, int y, int x, int degree)
// {
// 	(void)y;
// 	// int degree = 270;
// 	double resultx = find_end_x(degree);
// 	double resulty = find_end_y(degree);
// 	double endx = (x + resultx);
// 	double endy = (y + resulty); // + pca on renvoie - ou + indifferement
// 	double deltax = endx - x ;
// 	double deltay = endy - y;
// 	double pixelx = x + (XSIZE / 2);
// 	double pixely = y + (XSIZE / 2);
// 	// exit(0);
// 	int pixels = sqrt((deltax * deltax) + (deltay * deltay));
// 	deltax /= pixels;
// 	deltay /= pixels;
// 	while (1)
// 	{
// 		if (v->m.map[((int)pixely) / XSIZE][(int)pixelx / XSIZE] == '1' || v->m.map[(int)pixely / XSIZE][((int)pixelx) / XSIZE] == '1')
// 			break ;
// 		ft_my_mlx_pixel_put(&v->ig, pixely, pixelx, ft_rgb_to_int(0, 50, 150, 250));
// 		pixelx += deltax;
// 		pixely += deltay;
// 		// --pixels;
// 	}
// }