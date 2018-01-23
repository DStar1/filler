/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:32:37 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/22 22:34:39 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** copy old map
*/

void	cpy_map(t_mast *mast)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < mast->mylen)
	{
		x = 0;
		while (x < mast->mxlen)
		{
			mast->map2[y][x] = mast->map[y][x];
			x++;
		}
		y++;
	}
}

/*
** find my closest point to opp pt
*/

void	if_player(t_mast *mast, int opp)
{
	int y;
	int x;

	y = mast->ynx[0];
	x = mast->ynx[1];
	if (mast->map[y][x] == mast->player)
	{
		if (mast->first == 0)
		{
			mast->sum = ft_abs(opp - (x + y));
			mast->mypt[0] = y;
			mast->mypt[1] = x;
			mast->first = 1;
		}
		if (mast->first == 1 && ft_abs(opp - (x + y)) < mast->sum)
		{
			mast->sum = ft_abs(opp - (x + y));
			mast->mypt[0] = y;
			mast->mypt[1] = x;
		}
	}
}

void	find_my_closest_pt(t_mast *mast, int opy, int opx)
{
	int y;
	int x;
	int opp;

	y = 0;
	opp = opy + opx;
	mast->sum = 0;
	mast->first = 0;
	while (y < mast->mylen)
	{
		x = 0;
		while (x < mast->mxlen)
		{
			mast->ynx[0] = y;
			mast->ynx[1] = x;
			if_player(mast, opp);
			x++;
		}
		y++;
	}
}

/*
** compare old and new map to see where opp places piece
** loop through your peices and find the least distance mypt && oppt
*/

void	if_opp(t_mast *mast, int y, int x)
{
	if (mast->map[y][x] == mast->opponent)
	{
		draw(mast, y, x, 0xff8585);
		if (mast->first == 0)
		{
			mast->oppt[0] = y;
			mast->oppt[1] = x;
			find_my_closest_pt(mast, y, x);
			mast->sum = ft_abs((mast->mypt[0] + mast->mypt[1]) - (x + y));
			mast->first = 1;
		}
		else if (mast->first == 1 &&
				ft_abs((mast->mypt[0] + mast->mypt[1]) - (x + y)) < mast->sum)
		{
			find_my_closest_pt(mast, y, x);
			mast->sum = ft_abs((mast->mypt[0] + mast->mypt[1]) - (x + y));
			mast->oppt[0] = y;
			mast->oppt[1] = x;
		}
	}
}

void	compare(t_mast *mast)
{
	int y;
	int x;

	mast->first = 0;
	y = 0;
	mast->sum = 0;
	while (y < mast->mylen)
	{
		x = 0;
		while (x < mast->mxlen)
		{
			if (mast->map[y][x] != mast->map2[y][x])
			{
				if_opp(mast, y, x);
				if (mast->map[y][x] == mast->player)
					draw(mast, y, x, 0x8585ff);
			}
			x++;
		}
		y++;
	}
	create_image(mast);
}
