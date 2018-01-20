/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:32:37 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/20 01:21:26 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** find my closest point to opp pt
*/

void	find_my_closest_pt(t_mast *mast, int opy, int opx)
{
	int y;
	int x;
	int sum;
	int opp;
	int first;

	y = 0;
	opp = opy + opx;
	sum = 0;
	first = 0;
	while (y < mast->mylen)
	{
		x = 0;
		while (x < mast->mxlen)
		{
			if (mast->map[y][x] == mast->player) //find my closest pt to opp pts
			{
				if (first == 0)
				{
					sum = ft_abs(opp - (x + y));
					mast->mypt[0] = y;
					mast->mypt[1] = x;
					first = 1;
				}
				if (first == 1 && ft_abs(opp - (x + y)) < sum)
				{
					sum = ft_abs(opp - (x + y));
					mast->mypt[0] = y;
					mast->mypt[1] = x;
				}
			}
			x++;
		}
		y++;
	}
}

/*
** compare old and new map to see where opp places piece
*/

void	compare(t_mast *mast)
{
	int y;
	int x;
	int first;
	int sum;

	first = 0;
	y = 0;
	while (y < mast->mylen)
	{
		x = 0;
		while (x < mast->mxlen)
		{
			if ((mast->map[y][x] != mast->map2[y][x] && mast->map[y][x] == mast->opponent)) //and not the capital letter of me
			{
				
				//loop through your peices and find the least distance if it doesn't beat everyone
				if (first == 0)
				{
					mast->oppt[0] = y; //applys all pts and will end with thier last new point
					mast->oppt[1] = x;
					find_my_closest_pt(mast, y, x);
					sum = ft_abs((mast->mypt[0] + mast->mypt[1]) - (x + y));
					first = 1;
					// x = 0;
					// y = 0;
				}
				/////////////////////////////////////find thier closest point
				else if (first == 1 && ft_abs((mast->mypt[0] + mast->mypt[1]) - (x + y)) < sum)
				{
					find_my_closest_pt(mast, y, x);
					sum = ft_abs((mast->mypt[0] + mast->mypt[1]) - (x + y));
					mast->oppt[0] = y;
					mast->oppt[1] = x;
				}
				// //printf("(%d, %d)")
			}
			// if (mast->map[y][x] == mast->player && found  == 1) //find my closest pt to opp pts
			// {
				
			// }
				//mast->pcnt++;
			//mast->opptok = NULL;
			x++;
		}
		y++;
	}
//		printf("Opponent point:(%d, %d)\nclosest point on my points(%d, %d)\n", mast->oppt[0], mast->oppt[1], mast->mypt[0], mast->mypt[1]);
	// find_my_closest_pt(mast);
}

// /*
// ** Find thier farthest point of thier new peice from the rest of their old stars.
// ** Go through linked list and choose the point that is farthest from all other stars
// ** Save that point as direction[0] = y, direction[1] = x 
// */


/*
** start from the point shortest distance and find the next shortest distance that is possbible
** maybe log all points that have been tried already?
** or just make a four point searching functions. up/right iterative, down/left iterative, etc...
*/



/*
** find what point(my letters) is closest to (oppt[0], oppt[1]) 
** and is valid
*/

// void	find_closest_pnt(t_mast *mast)
// {
// 	//find what point(my letters) is closest to (oppt[0], oppt[1]) 
// 	int y;
// 	int x;
// 	int end;
// 	int foundstart;
// 	int lastyx[2];

// 	foundstart = 0;
// 	mast->errorcnt = 0;
// 	end = 0;
// 	lastyx[0] = 0;
// 	lastyx[1] = 0;
// 	y = 0;
// 	while (y < mast->mylen)
// 	{
// 		end = 0;
// 		x = 0;
// 		while (x < mast->mxlen)
// 		{
// 			if (mast->map[y][x] == mast->player)
// 			{
// 				//maybe save this\/ point and work up from there for down right, down from there for up left and so on
// 				if (/*foundstart == 0 && */ (ft_abs(y - mast->oppt[0]) < ft_abs(lastyx[0] - mast->oppt[0]) && ft_abs(x - mast->oppt[1]) < ft_abs(lastyx[1] - mast->oppt[1])))///*absolute values of (y - oppt[0] < mypt[0] - oppt[0]) && absolute values of (x - oppt[1] < mypt[1] - oppt[1]))*/)
// 				{
// 					// mast->mypt[0] = y; //the shortest distance from opponents last placed piece
// 					// mast->mypt[1] = x;
// 					// printf("Opp point:(%d, %d)\nclosest point on my points(%d, %d)\n", mast->oppt[0], mast->oppt[1], y, x);
// 					//foundstart = 1;
// 					;
// 				}
// 				// if (foundstart == 1 && (end = check_valid(mast, y, x)) == mast->stars - 1)//if all the points can be put on the map with this as the point, and only one point overlaps with one point
// 				// {
// 				// 	break ;
// 				// }
// 				// else
// 				// 	mast->errorcnt++;
// 				lastyx[0] = y;
// 				lastyx[1] = x;
// 			}
// 			//mast->opptok = NULL;
// 			x++;
// 		}
// 		// if (end == mast->stars - 1)
// 		// 	break ;
// 		y++;
// 	}
// }


