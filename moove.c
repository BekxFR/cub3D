
#include "cub3d.h"

void	moove_player(int dir, t_v *v)
{
	if (dir == 'W')
		dir = ft_check_player_up(v);
	if (dir == 'S')
		dir = ft_check_player_down(v);
	if (dir == 'D')
		dir = ft_check_player_right(v);
	if (dir == 'A')
		dir = ft_check_player_left(v);
	if (dir == 'K')
		dir = ft_moove_ray_right(v);
	if (dir == 'H')
		dir = ft_moove_ray_left(v);
	if (dir == 1)
		mlx_put_image_to_window(v->mlx, v->win, v->ig.img, 0, 0);
}

int	ft_keypress_event(int key, t_v *v)
{
	ft_printf("1v->m.py=%d et v->m.px=%d\n", v->m.py, v->m.px);
	if (key == 119) // || key == 65362)
		moove_player('W', v);
	if (key == 115) //|| key == 65364)
		moove_player('S', v);
	if (key == 100)
		moove_player('D', v);
	if (key == 97)
		moove_player('A', v);
	if (key == 65363)
		moove_player('K', v);
	if (key == 65361)
		moove_player('H', v);
	if (key == 65307)
		ft_close_event(v);
	return (0);
}

double find_wall_x(double degree)
{
	// degree to gradian : 350° × π/180 = 6,109rad
	/* entre 0 et 180 on renvoie +x et entre 180 et 360 on renvoie -x*/
	double pi = 3.1415926535897932384626433832;
	double res = 0;

	res = 13 * sin((degree) * pi / 180);
	// printf("resx : %f\n", res);
	return (res);
}

double find_wall_y(double degree)
{
	double pi = 3.1415926535897932384626433832;
	double res = 0;
	res = 13 * cos((degree) * pi / 180);
	// printf("resy : %f\n", res);
	return (res * -1);
}

int	ft_check_player_up(t_v *v)
{
	if (v->m.py > 0)
	{
		v->m.dir = 0;
		int tmp_ppx = v->m.ppx + find_wall_x(v->m.degree);
		tmp_ppx = ((tmp_ppx + (XSIZE / 2)) / XSIZE);
		int tmp_ppy = v->m.ppy + find_wall_y(v->m.degree);
		tmp_ppy = ((tmp_ppy + (XSIZE / 2)) / XSIZE);
		if (v->m.map[tmp_ppy][tmp_ppx] == '1')
			return (0);
		if (v->ig.img)
			mlx_destroy_image(v->mlx, v->ig.img);
		v->ig.img = mlx_new_image(v->mlx, ((v->m.x) * XSIZE), (v->m.y * XSIZE));
		if (!v->ig.img)
			ft_stop_all(v, 1);
		v->ig.ad = mlx_get_data_addr(v->ig.img, &v->ig.bpp, &v->ig.llen, &v->ig.en);
		ft_new_player_pos(v, v->m.ppy, v->m.ppx, v->m.degree);
		ft_draw_line_map(v);
		ft_check_pix_map(v);
		ft_draw_pix_line_circle(v, v->m.ppy, v->m.ppx);
		ft_paint_player_pixel(v, v->m.ppy, v->m.ppx);
		v->m.py = (((v->m.ppy + (XSIZE / 2)) / XSIZE));
		return (1);
	}
	return (0);
}

int	ft_check_player_down(t_v *v)
{
	if (v->m.py < v->m.y - 1)
	{
		v->m.dir = 1;
		int tmp_ppx = v->m.ppx + find_wall_x(v->m.degree + 180);
		tmp_ppx = ((tmp_ppx + (XSIZE / 2)) / XSIZE);
		int tmp_ppy = v->m.ppy + find_wall_y(v->m.degree + 180);
		tmp_ppy = ((tmp_ppy + (XSIZE / 2)) / XSIZE);
		if (v->m.map[tmp_ppy][tmp_ppx] == '1')
			return (0);
		if (v->ig.img)
			mlx_destroy_image(v->mlx, v->ig.img);
		v->ig.img = mlx_new_image(v->mlx, ((v->m.x) * XSIZE), (v->m.y * XSIZE));
		if (!v->ig.img)
			ft_stop_all(v, 1);
		v->ig.ad = mlx_get_data_addr(v->ig.img, &v->ig.bpp, &v->ig.llen, &v->ig.en);
		ft_new_player_pos(v, v->m.ppy, v->m.ppx, v->m.degree + 180);
		ft_draw_line_map(v);
		ft_check_pix_map(v);
		ft_draw_pix_line_circle(v, v->m.ppy, v->m.ppx);
		ft_paint_player_pixel(v, v->m.ppy, v->m.ppx);
		v->m.py = (((v->m.ppy + (XSIZE / 2)) / XSIZE));
		return (1);
	}
	return (0);
}

int	ft_check_player_right(t_v *v)
{
	if (v->m.px < v->m.x - 1)
	{
		v->m.dir = 2;
		int tmp_ppx = v->m.ppx + find_wall_x(v->m.degree + 90);
		tmp_ppx = ((tmp_ppx + (XSIZE / 2)) / XSIZE);
		int tmp_ppy = v->m.ppy + find_wall_y(v->m.degree + 90);
		tmp_ppy = ((tmp_ppy + (XSIZE / 2)) / XSIZE);
		if (v->m.map[tmp_ppy][tmp_ppx] == '1')
			return (0);
		if (v->ig.img)
			mlx_destroy_image(v->mlx, v->ig.img);
		v->ig.img = mlx_new_image(v->mlx, ((v->m.x) * XSIZE), (v->m.y * XSIZE));
		if (!v->ig.img)
			ft_stop_all(v, 1);
		v->ig.ad = mlx_get_data_addr(v->ig.img, &v->ig.bpp, &v->ig.llen, &v->ig.en);
		ft_new_player_pos(v, v->m.ppy, v->m.ppx, v->m.degree + 90);
		ft_draw_line_map(v);
		ft_check_pix_map(v);
		ft_draw_pix_line_circle(v, v->m.ppy, v->m.ppx);
		ft_paint_player_pixel(v, v->m.ppy, v->m.ppx);
		v->m.px = ((v->m.ppx + (XSIZE / 2)) / XSIZE);
		return (1);
	}
	return (0);
}

int	ft_check_player_left(t_v *v)
{
	if (v->m.px > 0)
	{
		v->m.dir = 2;
		int tmp_ppx = v->m.ppx + find_wall_x(v->m.degree + 270);
		tmp_ppx = ((tmp_ppx + (XSIZE / 2)) / XSIZE);
		int tmp_ppy = v->m.ppy + find_wall_y(v->m.degree + 270);
		tmp_ppy = ((tmp_ppy + (XSIZE / 2)) / XSIZE);
		if (v->m.map[tmp_ppy][tmp_ppx] == '1')
			return (0);
		if (v->ig.img)
			mlx_destroy_image(v->mlx, v->ig.img);
		v->ig.img = mlx_new_image(v->mlx, ((v->m.x) * XSIZE), (v->m.y * XSIZE));
		if (!v->ig.img)
			ft_stop_all(v, 1);
		v->ig.ad = mlx_get_data_addr(v->ig.img, &v->ig.bpp, &v->ig.llen, &v->ig.en);
		ft_new_player_pos(v, v->m.ppy, v->m.ppx, v->m.degree + 270);
		ft_draw_line_map(v);
		ft_check_pix_map(v);
		ft_draw_pix_line_circle(v, v->m.ppy, v->m.ppx);
		ft_paint_player_pixel(v, v->m.ppy, v->m.ppx);
		v->m.px = ((v->m.ppx + (XSIZE / 2)) / XSIZE);
		return (1);
	}
	return (0);
}


int	ft_moove_ray_left(t_v *v)
{
	// v->m.degree -= 10;
	// if (v->m.degree == -10)
	// 	v->m.degree = 350;
	v->m.degree -= 5;
	if (v->m.degree == -5)
		v->m.degree = 355;
	ft_printf("v->m.degree=%d\n", v->m.degree);
	if (v->ig.img)
		mlx_destroy_image(v->mlx, v->ig.img);
	v->ig.img = mlx_new_image(v->mlx, ((v->m.x) * XSIZE), (v->m.y * XSIZE));
	if (!v->ig.img)
		ft_stop_all(v, 1);
	v->ig.ad = mlx_get_data_addr(v->ig.img, &v->ig.bpp, &v->ig.llen, &v->ig.en);
	ft_draw_line_map(v);
	ft_check_pix_map(v);
	ft_draw_pix_line_circle(v, v->m.ppy, v->m.ppx);
	ft_paint_player_pixel(v, v->m.ppy, v->m.ppx);
	return (1);
}

int	ft_moove_ray_right(t_v *v)
{
	// v->m.degree += 10;
	// if (v->m.degree == 370)
	// 	v->m.degree = 10;
	v->m.degree += 5;
	if (v->m.degree == 365)
		v->m.degree = 5;
	ft_printf("v->m.degree=%d\n", v->m.degree);
	if (v->ig.img)
		mlx_destroy_image(v->mlx, v->ig.img);
	v->ig.img = mlx_new_image(v->mlx, ((v->m.x) * XSIZE), (v->m.y * XSIZE));
	if (!v->ig.img)
		ft_stop_all(v, 1);
	v->ig.ad = mlx_get_data_addr(v->ig.img, &v->ig.bpp, &v->ig.llen, &v->ig.en);
	ft_draw_line_map(v);
	ft_check_pix_map(v);
	ft_draw_pix_line_circle(v, v->m.ppy, v->m.ppx);
	ft_paint_player_pixel(v, v->m.ppy, v->m.ppx);
	return (1);
}