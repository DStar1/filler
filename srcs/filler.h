/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:26:25 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/21 22:38:08 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

/*
** 
*/


typedef struct		s_points
{
	int				pts[2];
	struct s_points	*next;
}					t_points;

typedef struct		s_vars
{
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	int				numerator;
	int				longest;
	int				shortest;
	int				i;
	int				w;
	int				h;
	double			dx1;
	double			dy1;
	double			dx2;
	double			dy2;
	int				x11;
	int				y11;
	int				x22;
	int				y22;
	int				c;
	void			*content;
	struct s_vars	*next;
}					t_vars;

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
	int				x11;
	int				y11;
	int				x22;
	int				y22;

	int				fd;
	int				i;
	int				j;
	char			*ln;
	char			*place;
	char			player;
	char			opponent;
	char			*user1;
	char			*user2;
	int				mylen;
	int				mxlen;
	char			**map;
	char			**map2;
	char			**token;
	int				tokindex;
	int				tylen;
	int				txlen;
	int				x[2];
	int				o[2];
	int				oppt[2];
	int				mypt[2];
	int				mypt_last[2];
	int				startpt[2];
	int				errorcnt;
	int				pcnt; //player points cnt
	int				stars;
	int				tpts[1000][2]; //changed from **tpts// maybe chage to tpts[100][2]
	int				tpts_ord[1000][2]; //token points reordered based on where to place them
	int				tpt[2];
	char			*user;
	t_points		*opptok;
	t_points		*mytok;
	t_points		*newlist;
	t_points		*list;
	void			*something;
	struct s_mast	*next;
}					t_mast;

void				parse(t_mast *mast, int i);
void	compare(t_mast *mast);
void	find_closest_pnt(t_mast *mast);
int		place_pt(t_mast *mast);
void	put_peice(t_mast *mast);

#endif