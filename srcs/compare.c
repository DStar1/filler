/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:32:37 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/21 17:17:37 by hasmith          ###   ########.fr       */
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
			if (mast->map[y][x] == mast->player)
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
** loop through your peices and find the least distance mypt && oppt
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
			if ((mast->map[y][x] != mast->map2[y][x] &&
				mast->map[y][x] == mast->opponent))
			{
				if (first == 0)
				{
					mast->oppt[0] = y;
					mast->oppt[1] = x;
					find_my_closest_pt(mast, y, x);
					sum = ft_abs((mast->mypt[0] + mast->mypt[1]) - (x + y));
					first = 1;
				}
				else if (first == 1 &&
						ft_abs((mast->mypt[0] + mast->mypt[1]) - (x + y)) < sum)
				{
					find_my_closest_pt(mast, y, x);
					sum = ft_abs((mast->mypt[0] + mast->mypt[1]) - (x + y));
					mast->oppt[0] = y;
					mast->oppt[1] = x;
				}
			}
			x++;
		}
		y++;
	}
}//		printf("Opponent point:(%d, %d)\nclosest point on my points(%d, %d)\n", mast->oppt[0], mast->oppt[1], mast->mypt[0], mast->mypt[1]);
