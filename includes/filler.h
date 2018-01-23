/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:26:25 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/22 22:34:58 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"

/*
** maybe change to tpts[100][2]
*/

typedef struct		s_points
{
	int				pts[2];
	struct s_points	*next;
}					t_points;

typedef struct		s_mast
{
	int				*img_int;
	void			*mlx_ptr;
	void			*img_ptr;
	int				bpp;
	int				size_line;
	int				endian;
	void			*mlx;
	void			*win;
	int				wsize;
	int				ynx[2];
	int				first;
	int				plcnt;
	int				ret;
	int				fd;
	int				sum;
	int				i;
	int				j;
	char			*ln;
	char			*place;
	char			player;
	char			opponent;
	int				mylen;
	int				mxlen;
	char			**map;
	char			**map2;
	int				tylen;
	int				txlen;
	int				x[2];
	int				o[2];
	int				oppt[2];
	int				mypt[2];
	int				startpt[2];
	int				stars;
	int				tpts[1000][2];
}					t_mast;

void				parse(t_mast *mast, int i);
void				cpy_map(t_mast *mast);
void				compare(t_mast *mast);
void				find_closest_pnt(t_mast *mast);
int					place_pt(t_mast *mast);
void				put_peice(t_mast *mast);
void				draw(t_mast *master, int y1, int x1, int color);
void				put_new_map(t_mast *mast);
void				pixel_str(t_mast *m);
void				create_image(t_mast *m);
int					token_last(t_mast *mast, int y, int x, int last);

#endif
