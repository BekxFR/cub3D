/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:54:34 by mgruson           #+#    #+#             */
/*   Updated: 2023/01/18 17:58:08 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include "libs/libft/includes/libft.h"
# include "libs/libft/includes/ft_printf.h"
# include "libs/libft/includes/get_next_line.h"
# include "libs/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

typedef struct s_data {
	void	*img;
	char	*ad;
	int		pos;
	int		addr_use;
	int		bpp;
	int		llen;
	int		en;
	int		x;
	int		y;
	int		color1;
	int		color2;
	int		color3;
}	t_data;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		px;
	int		py;
	int		ppx;
	int		ppy;
}	t_map;

typedef struct s_var
{
	void	*mlx;
	void	*win;
	t_data	ig;
	t_map	m;
}	t_v;

#define XSIZE 64

/* cub3d.c */
int		ft_close_event(t_v *v);
void	ft_reset_paint(t_v *v, int y, int x);
void	ft_paint_player_pixel(t_v *v, int y, int x);
void	ft_draw_line_circle(t_v *v, int y, int x);
void	ft_draw_pix_line_circle(t_v *v, int y, int x);
void	ft_check_map(t_v *v);
void	ft_check_pix_map(t_v *v);
void	ft_draw_line_map(t_v *v);
void	ft_stop_all(t_v *v, int exint);
void	ft_draw_pix_line_dir(t_v *v, int y, int x, int degree);

/* moove.c */
void	moove_player(int dir, t_v *v);
int		ft_keypress_event(int key, t_v *v);
int		ft_check_player_up(t_v *v);
int		ft_check_player_down(t_v *v);
int		ft_check_player_right(t_v *v);
int		ft_check_player_left(t_v *v);

#endif
