


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