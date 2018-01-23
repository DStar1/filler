/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 21:03:09 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/22 21:06:26 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** place token point you want at a certain position with this math
** ((mast->map[y - mast->token[0]][x - mast->token[1]])) for (0, 0)
*/

int		place_down_l(t_mast *mast)
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

int		place_down_r(t_mast *mast)
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

int		place_up_l(t_mast *mast)
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
** or if their opponents closest point is greater than my mypt y and x,
** iterate up/back x/y from there
*/

int		place_pt(t_mast *mast)
{
	int ret;

	ret = 0;
	if (mast->oppt[0] <= mast->mypt[0] && mast->oppt[1] <= mast->mypt[1])
		ret = place_up_l(mast);
	else if (mast->oppt[0] >= mast->mypt[0] && mast->oppt[1] >= mast->mypt[1])
		ret = place_down_r(mast);
	else if (mast->oppt[0] <= mast->mypt[0] && mast->oppt[1] >= mast->mypt[1])
		ret = place_up_r(mast);
	else if (mast->oppt[0] >= mast->mypt[0] && mast->oppt[1] <= mast->mypt[1])
		ret = place_down_l(mast);
	return (ret);
}
