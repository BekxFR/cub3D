
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
	if (dir == 1)
		mlx_put_image_to_window(v->mlx, v->win, v->ig.img, 0, 0);
}

int	ft_keypress_event(int key, t_v *v)
{
	ft_printf("1v->m.py=%d et v->m.px=%d\n", v->m.py, v->m.px);
	if (key == 65362 || key == 119)
		moove_player('W', v);
	if (key == 65364 || key == 115)
		moove_player('S', v);
	if (key == 65363 || key == 100)
		moove_player('D', v);
	if (key == 65361 || key == 97)
		moove_player('A', v);
	if (key == 65307)
		ft_close_event(v);
	return (0);
}

int	ft_check_player_up(t_v *v)
{
	if (v->m.py > 0)
	{
		if (v->m.map[((v->m.ppy + ((XSIZE / 2) - 10)) / 64)][v->m.px] == '1')
			return (0);
		v->m.ppy -= 10;
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
		v->m.py = (((v->m.ppy + (XSIZE / 2)) / 64));
		return (1);
	}
	return (0);
}

int	ft_check_player_down(t_v *v)
{
	if (v->m.py < v->m.y - 1)
	{
		if (v->m.map[((v->m.ppy + ((XSIZE / 2) + 10)) / 64)][v->m.px] == '1')
			return (0);
		v->m.ppy += 10;
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
		v->m.py = (((v->m.ppy + (XSIZE / 2)) / 64));
		return (1);
	}
	return (0);
}

int	ft_check_player_right(t_v *v)
{
	if (v->m.px < v->m.x - 1)
	{
		if (v->m.map[v->m.py][((v->m.ppx + ((XSIZE / 2) + 10)) / 64)] == '1')
			return (0);
		v->m.ppx += 10;
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
		v->m.px = ((v->m.ppx + (XSIZE / 2)) / 64);
		return (1);
	}
	return (0);
}

int	ft_check_player_left(t_v *v)
{
	if (v->m.px > 0)
	{
		if (v->m.map[v->m.py][((v->m.ppx + ((XSIZE / 2) - 10)) / 64)] == '1')
			return (0);
		v->m.ppx -= 10;
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
		v->m.px = ((v->m.ppx + (XSIZE / 2)) / 64);
		return (1);
	}
	return (0);
}
