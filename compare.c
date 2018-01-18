/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:32:37 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/17 21:33:52 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
			if (mast->map[y][x] != mast->map2[y][x] && mast->map[y][x] != mast->player && mast->map[y][x] != '.') //and not the capital letter of me
			{
				//loop through your peices and find the least distance if it doesn't beat everyone
				// if (mast->mypt[0])
				// {
					mast->oppt[0] = y; //applys all pts and will end with thier last point
					mast->oppt[1] = x;
				// }
				// //save coodinates in a linked list
				// mast->opptok->next = (t_points*)malloc(sizeof(t_points)); //allocate space
				// mast->opptok->pts[0] = y;
				// mast->opptok->pts[1] = x;
				// mast->opptok = mast->opptok->next;
				// //printf("(%d, %d)")
				;
			}
			//mast->opptok = NULL;
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
** find what point(my letters) is closest to (oppt[0], oppt[1]) 
** and is valid
*/

void	find_closest_pnt(t_mast *mast)
{
	//find what point(my letters) is closest to (oppt[0], oppt[1]) 
	int y;
	int x;

	y = 0;
	while (y < mast->mylen)
	{
		x = 0;
		while (x < mast->mxlen)
		{
			if (mast->map[y][x] == mast->player)
			{
				if (ft_abs(y - mast->oppt[0]) < ft_abs(mast->mypt[0] - mast->oppt[0]) && ft_abs(x - mast->oppt[1]) < ft_abs(mast->mypt[1] - mast->oppt[1]))///*absolute values of (y - oppt[0] < mypt[0] - oppt[0]) && absolute values of (x - oppt[1] < mypt[1] - oppt[1]))*/)
				{
					//if ()//if all the points can be put on the map with this as the point, and only one point overlaps with one point
						mast->mypt[0] = y; //applys all pts and will end with thier last point
						mast->mypt[1] = x;
				}

				// //printf("(%d, %d)")
				;
			}
			//mast->opptok = NULL;
			x++;
		}
		y++;
	}
}