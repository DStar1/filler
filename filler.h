/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:26:25 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/11 21:48:25 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef struct		s_mast
{
	int				i;
	int				j;
	char			*ln;
	char			*user1;
	char			*user2;
	int				mylen;
	int				mxlen;
	char			**map;
	char			**token;
	int				tylen;
	int				txlen;
	char			*filename;
	int				x[2];
	int				o[2];
	char            *user;
	void			*somthing;
	struct s_mast	*next;
}					t_mast;

void	parse(t_mast *mast);


#endif