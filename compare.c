/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:32:37 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/15 21:12:10 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** compare old and new map to see where opp places piece
*/

void	compare(t_mast *mast)
{
	int y;
	int x;

	y = 0;
	while (y < mast->mylen)
	{
		x = 0;
		while (x < mast->mxlen)
		{
			if (mast->map[y][x] != mast->map2[y][x])
				//save coodinates in a linked list
			x++;
		}
		y++;
	}
}

/*
** Find thier farthest point of thier new peice from the rest of their old stars.
** Go through linked list and choose the point that is farthest from all other stars
** Save that point as direction[0] = y, direction[1] = x
*/

void	find_opp_point(t_mast *mast)
{
	//go through linked list and choose the point that is farthest from all other stars
	//save that point as direction[0] = y, direction[1] = x
	 
}

/*
** find what point(my letters) is closest to (direction[0], direction[1]) 
*/

void	find_cosest_pnt(t_mast *mast)
{
	//find what point(my letters) is closest to (direction[0], direction[1]) 
}