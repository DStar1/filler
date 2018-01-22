/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 21:03:09 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/21 16:50:38 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** check if is it possible to place all points onto the map
**
*/

int		check_valid(t_mast *mast, int y, int x, int index)
{
	int ret;
	int i;
	int y1;
	int x1;
	int plcnt;

	i = 0;
	ret = 0;
	plcnt = 0;
	y1 = y - (mast->tpts[index][0]);
	x1 = x - (mast->tpts[index][1]);
	while (i < mast->stars)
	{
		if (((mast->tpts[i][0] + y1) >= 0 && (mast->tpts[i][0] + y1) < mast->mylen)
					&& ((mast->tpts[i][1] + x1) >= 0 && (mast->tpts[i][1] + x1) < mast->mxlen))
		{
			if (mast->map[mast->tpts[i][0] + y1][mast->tpts[i][1] + x1] == '.')
				ret++;
			else if (mast->map[mast->tpts[i][0] + y1][mast->tpts[i][1] + x1] == mast->player)
			{
				plcnt++;
			}
			else
				return (0);
		}
		else
			return (0);
		i++;
	}
	if (ret == mast->stars - 1 && plcnt == 1)
	{
		mast->startpt[0] = y - (mast->tpts[index][0]);
		mast->startpt[1] = x - (mast->tpts[index][1]);
		return (1);
	}
	return (0);
}

/*
** iterates through token tpts either from 0 or from the last index
** depending on int last's value. 1 to start at last, 0 for 0
*/

int	token_last(t_mast *mast, int y, int x, int last)
{
	int index;
	int iter;

	index = 0;
	iter = 1;
	if (last == 1)
	{
		index = mast->stars - 1;
		while (index >= 0)
		{
			if (check_valid(mast, y, x, index) == 1)
				return (1);
			index--;
		}
	}
	else
	{
		while (index < mast->stars)
		{
			if (check_valid(mast, y, x, index) == 1)
				return (1);
			index++;
		}
	}
	return (0);
}

/*
** place token point you want at a certain position with this math
** ((mast->map[y - mast->token[0]][x - mast->token[1]])) for (0, 0)
*/

int	place_down_l(t_mast *mast)
{
	int y;
	int x;

	if (token_last(mast, mast->mypt[0], mast->mypt[1], 1) == 1)
		return (1);
	y = mast->mylen - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < mast->mxlen)
		{
			if (mast->map[y][x] == mast->player)
			{
				if (token_last(mast, y, x, 1) == 1)
					return (1);
			}
			x++;
		}
		y--;
	}
	return (0);
}

int	place_down_r(t_mast *mast)
{
	int y;
	int x;

	if (token_last(mast, mast->mypt[0], mast->mypt[1], 0) == 1)
		return (1);
	y = mast->mylen - 1;
	while (y >= 0)
	{
		x = mast->mxlen - 1;
		while (x >= 0)
		{
			if (mast->map[y][x] == mast->player)
			{
				if (token_last(mast, y, x, 0) == 1)
					return (1);
			}
			x--;
		}
		y--;
	}
	return (0);
}

int	place_up_l(t_mast *mast)
{
	int y;
	int x;

	if (token_last(mast, mast->mypt[0], mast->mypt[1], 1) == 1)
		return (1);
	y = 0;
	while (y < mast->mylen)
	{
		x = 0;
		while (x < mast->mxlen)
		{
			if (mast->map[y][x] == mast->player)
			{
				// printf("(%d,%d)\n", y , x);
				if (token_last(mast, y, x, 1) == 1)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		place_up_r(t_mast *mast)
{
	int y;
	int x;

	if (token_last(mast, mast->mypt[0], mast->mypt[1], 0) == 1)
		return (1);
		
	y = 0;
	while (y < mast->mylen)
	{
		x = mast->mxlen - 1;
		while (x >= 0)
		{
			if (mast->map[y][x] == mast->player)
			{

				if (token_last(mast, y, x, 0) == 1)
					return (1);
			}
			x--;
		}
		y++;
	}
	return (0);
}

/*
** try to place the point starting with mast->start coordinates
** or if their opponents closest point is greater than my mypt y and x, iterate up/back x/y from there
*/

int	place_pt(t_mast *mast)
{

	int ret;

	ret = 0;
	if (mast->oppt[0] <= mast->mypt[0] && mast->oppt[1] <= mast->mypt[1])
		{ret = place_up_l(mast);}
	else if (mast->oppt[0] >= mast->mypt[0] && mast->oppt[1] >= mast->mypt[1])
		{ret = place_down_r(mast);}
	else if (mast->oppt[0] <= mast->mypt[0] && mast->oppt[1] >= mast->mypt[1])
		{ret = place_up_r(mast);}
	else if (mast->oppt[0] >= mast->mypt[0] && mast->oppt[1] <= mast->mypt[1])
		{ret = place_down_l(mast);}
	return (ret);
}
