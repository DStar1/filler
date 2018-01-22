/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:31:22 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/21 17:18:08 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** GLOBAL:
** Parse through data to store what player you are,
** the map, and the token
*/

/*
** find first 'X' and first 'O' pts and save into mast->x and mast->o
*/

void	mappts(t_mast *mast)
{
	int x;
	int y;

	y = 0;
	while (y < mast->mylen)
	{
		x = 0;
		while (x < mast->mxlen)
		{
			if (mast->map[y][x] == 'X')
			{
				mast->x[0] = y;
				mast->x[1] = x;
			}
			if (mast->map[y][x] == 'O')
			{
				mast->o[0] = y;
				mast->o[1] = x;
			}
			x++;
		}
		y++;
	}
}

/*
** count and store stars of my token piece int mast->tpts
*/

void	tokenpts(t_mast *mast)
{
	int x;
	
	x = 0;
	while (mast->ln[x])
	{
		if (mast->ln[x] == '*')
		{
			mast->tpts[mast->stars][0] = mast->j - (mast->mylen + 3); //possibly loses pointer, solve by changing numbers at address only
			mast->tpts[mast->stars][1] = x;
			mast->stars++;
		}
		x++;
	}
}

int		f_atoi(t_mast *mast, int start)
{
	int start1;
	int nb;

	nb = 0;
	start1 = start;
	while (mast->ln[start] && ft_isdigit(mast->ln[start]))
	{
		nb += (mast->ln[start] - '0');
		nb *= 10;
		start++;
	}
	nb /= 10;
	return (nb);
}

void	parse(t_mast *mast , int i)
{
	while ((get_next_line(mast->fd, &mast->ln)))
	{
		if (mast->j == 0 && i == 1) 															//saves map dimentions
		{
			mast->mylen = f_atoi(mast, 8);
			mast->mxlen = f_atoi(mast, 9 + ft_intlen(mast->mylen));
			if (i == 1)
			{
				mast->map = (char**)malloc(sizeof(char*) * mast->mylen + 1);
				mast->map2 = (char**)malloc(sizeof(char*) * mast->mylen + 1);
				mast->map[mast->mylen] = NULL;
				mast->map2[mast->mylen] = NULL;
			}
		}
		if ((mast->j >= 2 && mast->j < mast->mylen + 2) && i == 1) 					//saves map int 2 2d arrays
		{
			mast->map[mast->i] = ft_strsub(mast->ln, 4, ft_strlen(mast->ln) - 4);
			mast->map2[mast->i] = ft_strsub(mast->ln, 4, ft_strlen(mast->ln) - 4);
			mast->i++;
		}
		else if (mast->j >= 2 && mast->j < mast->mylen + 2)						//copies new map(mast->map2) to mast->map
		{
			int q = 0;
			for (int w = 4; mast->ln[w]; w++)
				mast->map[mast->i][q++] = mast->ln[w];
			//ft_memcpy(mast->map[mast->i], newln, sizeof(newln));//ft_memncpy(mast->map[mast->i++], mast->ln, 4, sizeof(mast->ln) - 4);
			mast->i++;
		}
		if (mast->mylen && mast->j == mast->mylen + 2) 								//saves token dimentions
		{
			mast->tylen = f_atoi(mast, 6);
			mast->txlen = f_atoi(mast, 7 + ft_intlen(mast->tylen));
			mast->i = 0;
		}
		if (mast->j >= mast->mylen + 3 && mast->j < mast->mylen + 3 + mast->tylen) //for the token points
			tokenpts(mast);
		free(mast->ln);
		mast->ln = NULL;
		if (mast->j >= mast->mylen + mast->tylen + 2)
			break ;
		mast->j++;
	}
	free(mast->ln);
	//printf("player: %c,(%d, %d), (%d, %d)\n", mast->player, mast->mylen, mast->mxlen, mast->tylen, mast->txlen); ///////////////////
	if (i == 1)
		mappts(mast);
}
