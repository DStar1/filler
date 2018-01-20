/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 21:03:09 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/20 01:21:20 by hasmith          ###   ########.fr       */
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

	i = 0;
	ret = 0;
	mast->tokindex = 0;
	y1 = y - (mast->tpts[index][0]); //was mast->tpts[i][0]
	x1 = x - (mast->tpts[index][1]); //was mast->tpts[i][0]
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
		mast->startpt[0] = y - (mast->tpts[index][0]);// - (mast->tylen - 1));
		mast->startpt[1] = x - (mast->tpts[index][1]);// - (mast->txlen - 1));
	}
	return (ret);
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
		index = mast->stars;
		iter = -1;
	}
	while (index >= 0) //go throught tokens points
	{
		if (check_valid(mast, y, x, index) == mast->stars - 1)
			return (1);
		else
			index += iter;
	}
	return (0);
}




/*
** decide what point of token to place on your closest point
** to determine the direction. If top/left point is placed, (moves towards bottom/right)
*/

void	tpoint_dir(t_mast *mast)
{
	
}

/*
** place token point you want at a certain position with this math
** ((mast->map[y - mast->token[0]][x - mast->token[1]])) for (0, 0)
*/

int	place_up_r(t_mast *mast) //not complete
{
	//highest y point, with the lowest x
	// int index;
	int y;
	int x;
 //starts at bootom coordinate of token mast->tpts[index][]
	//first try to place the point based on mast->mypt, then do the loops
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
	//lowest y point, with the lowest x
	//token[0]//first pt
	//mast->tokindex = 0;
	int y;
	int x;
 //starts at bootom coordinate of token mast->tpts[index][]
	//first try to place the point based on mast->mypt, then do the loops
	if (token_last(mast, mast->mypt[0], mast->mypt[1], 0) == 1)
		return (1);
	y = mast->mylen - 1; //starts at one less than the dimenttions
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



	// if (mast->tpts[*i][0] + mast->tpts[*i][1] < mast->tpts[*i + 1][0] + mast->tpts[*i][1])
	// {
	// 	ft_swap(&(mast->tpts[*i + 1][0]), &(mast->tpts[*i][0]));
	// 	ft_swap(&(mast->tpts[*i + 1][1]), &(mast->tpts[*i][1]));
	// 	*i = -1;
	//}
}



int	place_up_l(t_mast *mast) //checks down and to the right
{
	//highest y point, with the highest x
	//token[stars]//last pt
	//mast->tokindex = mast->stars;
	int y;
	int x;
 //starts at bootom coordinate of token mast->tpts[index][]
	//first try to place the point based on mast->mypt, then do the loops
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

int		place_down_l(t_mast *mast) //not complete
{
	//lowest y point, with the highest x
	int y;
	int x;
 //starts at bootom coordinate of token mast->tpts[index][]
	//first try to place the point based on mast->mypt, then do the loops

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

int	place_pt(t_mast *mast)
{
//	int i;
	// int j;

//	i = 0;
	// j = 0;
	// mast->tpt[0] = mast->tpts[i][0];
	// mast->tpt[1] = mast->tpts[i][1];
	// for (int x = 0; x < mast->stars; x++)
	// {
	// 	printf("stars order(before): (%d, %d)\n", mast->tpts[x][0], mast->tpts[x][1]);
	// }
	// while (i < mast->stars - 1)
	// {
	//	printf("in\n");
		if (mast->oppt[0] <= mast->mypt[0] && mast->oppt[1] <= mast->mypt[1])
			{/*printf("1\n");*/place_up_l(mast);}
		else if (mast->oppt[0] >= mast->mypt[0] && mast->oppt[1] >= mast->mypt[1])
			{/*printf("2\n");*/place_down_r(mast);}
		else if (mast->oppt[0] < mast->mypt[0] && mast->oppt[1] > mast->mypt[1])
			{/*printf("3\n");*/place_up_r(mast);}
		else if (mast->oppt[0] > mast->mypt[0] && mast->oppt[1] < mast->mypt[1])
			{/*printf("4\n");*/place_down_l(mast);}
		// else
		// 	printf("4\n");
	//	i++;
	//}
	// for (int x = 0; x < mast->stars; x++)
	// {
	// 	printf("stars order(after): (%d, %d)\n", mast->tpts[x][0], mast->tpts[x][1]);
	// }
	return (0);
}

/*
** try to place the point starting with mast->start coordinates
** or if their opponents closest point is greater than my mypt y and x, iterate up/back x/y from there
*/

// void	try_to_place(t_mast *mast)
// {
// 	int y;
// 	int x;
// 	int iter;
// 	int tokindex;

// 	iter = 0;
// 	tokindex = 0;
// 	y = mast->mypt[0];
// 	x = mast->mypt[1];
// 	if(mast->oppt[0] + mast->oppt[1] <= mast->mypt[0] + mast->mypt[1]) //whether to go up fom there or down from there
// 	{
// 		iter = -1;
// 		tokindex = mast->stars; //tpts starts at the last value
// 	}
// 	else
// 	{
// 		iter = 1;
// 		tokindex = 0;
// 	}
// 	while (y < mast->mylen)
// 	{
// 		if (y != 0)
// 			x = 0;
// 		while (x < mast->mxlen)
// 		{
// 			if (mast->map[y][x] == mast->player)
// 			{
// 				if (foundstart == 1 && (end = check_valid(mast, y, x)) == mast->stars - 1)//if all the points can be put on the map with this as the point, and only one point overlaps with one point
// 				{
// 					break ;
// 				}
// 				else
// 					mast->errorcnt++;
// 			}
// 			x += iter;
// 		}
// 		if (end == mast->stars - 1)
// 			break ;
// 		y += iter;
// 	}
// }