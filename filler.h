/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:26:25 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/16 23:28:19 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

/*
** 
*/


typedef struct		s_points
{
	int				pts[2];
	struct s_points	*next;
}					t_points;

typedef struct		s_mast
{
	int				i;
	int				j;
	char			*ln;
	char			*place;
	char			player;
	char			*user1;
	char			*user2;
	int				mylen;
	int				mxlen;
	char			**map;
	char			**map2;
	char			**token;
	int				tylen;
	int				txlen;
	char			*filename;
	int				x[2];
	int				o[2];
	int				stars;
	int				**tpts;
	char			*user;
	t_points		*opptok;
	t_points		*mytok;
	t_points		*newlist;
	t_points		*list;
	void			*something;
	struct s_mast	*next;
}					t_mast;

void				parse(t_mast *mast, int i);

#endif
