/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:32:37 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/19 16:37:37 by hasmith          ###   ########.fr       */
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
			}
			if (mast->map[y][x] == mast->player)
				mast->pcnt++;
			//mast->opptok = NULL;
			x++;
		}
		y++;
	}
}

// /*
// ** Find thier farthest point of thier new peice from the rest of their old stars.
// ** Go through linked list and choose the point that is farthest from all other stars
// ** Save that point as direction[0] = y, direction[1] = x 
// */

/*
** check if is it possible to place all points onto the map
**
*/

int		check_valid(t_mast *mast, int y, int x)
{
	int ret;
	int i;
	int y1;
	int x1;

	i = 0;
	ret = 0;
	mast->tokindex = 0;
	y1 = y - (mast->tpts[i][0]);
	x1 = x - (mast->tpts[i][1]);
	while (i < mast->stars)
	{
		// y1 = (y + mast->tpts[i][0]);//mast->tpts[i][0] - mast->tylen + y + 1;//
		// x1 = (x + mast->tpts[i][1]);//mast->tpts[i][1] - mast->txlen + x + 1;//
		//printf("valid? y, x(%d, %d), token(%d, %d), new(%d, %d)\n",y, x, mast->tpts[i][0], mast->tpts[i][1], mast->tpts[i][0] + y1, mast->tpts[i][1] + x1);
		if (y1 < mast->mylen && x1 < mast->mxlen)
		{
			if (mast->map[mast->tpts[i][0] + y1][mast->tpts[i][1] + x1] == '.')
			{
				// mast->tpt[0] = y1;
				// mast->tpt[1] = x1;
				ret++;
			}
			else if (mast->map[mast->tpts[i][0] + y1][mast->tpts[i][1] + x1] == mast->player)
			{
				mast->tokindex = i;//save index if it equals mast->player?
			}
		}
		// else
		// 	return (0);
		i++;
	}
	if (ret == mast->stars - 1)
	{
		//printf("\ntrue token(%d, %d)\n", y1 - mast->tpts[0][0], x1 - mast->tpts[0][1]);
		mast->mypt[0] = y - (mast->tpts[0][0]);// - (mast->tylen - 1));
		mast->mypt[1] = x - (mast->tpts[0][1]);// - (mast->txlen - 1));
	}
	return (ret);
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
	int end;

	mast->errorcnt = 0;
	end = 0;
	y = 0;
	while (y < mast->mylen)
	{
		end = 0;
		x = 0;
		while (x < mast->mxlen)
		{
			if (mast->map[y][x] == mast->player)
			{
				// if (ft_abs(y - mast->oppt[0]) < ft_abs(mast->mypt[0] - mast->oppt[0]) && ft_abs(x - mast->oppt[1]) < ft_abs(mast->mypt[1] - mast->oppt[1]))///*absolute values of (y - oppt[0] < mypt[0] - oppt[0]) && absolute values of (x - oppt[1] < mypt[1] - oppt[1]))*/)
				// {
					// if (mast->errorcnt == mast->pcnt)
					// {
					// 	//move the token coordinate, and then if it's at the end of the token coordinates, exit
					// }
					//ft_putstr("in\n");

					if ((end = check_valid(mast, y, x)) == mast->stars - 1)//if all the points can be put on the map with this as the point, and only one point overlaps with one point
					{
						// mast->mypt[0] = y - (mast->tylen - 1);//mast->tpts[mast->errorcnt][0]; //applys all pts and will end with thier last point
						// mast->mypt[1] = x - (mast->txlen - 1);//mast->tpts[mast->errorcnt][1]; ////add these back!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
						break ;
					}
					else
						mast->errorcnt++;
				// }

				// //printf("(%d, %d)")
			}
			//mast->opptok = NULL;
			x++;
		}
		if (end == mast->stars - 1)
			break ;
		y++;
	}
}
