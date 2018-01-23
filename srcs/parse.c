/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:31:22 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/22 20:44:20 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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
			mast->tpts[mast->stars][0] = mast->j - (mast->mylen + 3);
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

/*
** 1) saves map dimentions
** 2) saves map int 2 2d arrays
** 3) copies new map(mast->map2) to mast->map
** 4) saves token dimentions
** 5) token points
** printf("player: %c,(%d, %d), (%d, %d)\n", mast->player,
** mast->mylen, mast->mxlen, mast->tylen, mast->txlen);
*/

void	parse_two(t_mast *mast, int i)
{
	int w;
	int q;

	if ((mast->j >= 2 && mast->j < mast->mylen + 2) && i == 1)
	{
		mast->map[mast->i] = ft_strsub(mast->ln, 4, ft_strlen(mast->ln) - 4);
		mast->map2[mast->i] = ft_strsub(mast->ln, 4, ft_strlen(mast->ln) - 4);
		mast->i++;
	}
	else if (mast->j >= 2 && mast->j < mast->mylen + 2)
	{
		w = 4;
		q = 0;
		while (mast->ln[w])
			mast->map[mast->i][q++] = mast->ln[w++];
		mast->i++;
	}
	if (mast->mylen && mast->j == mast->mylen + 2)
	{
		mast->tylen = f_atoi(mast, 6);
		mast->txlen = f_atoi(mast, 7 + ft_intlen(mast->tylen));
		mast->i = 0;
	}
	if (mast->j >= mast->mylen + 3 && mast->j < mast->mylen + 3 + mast->tylen)
		tokenpts(mast);
}

void	parse(t_mast *mast, int i)
{
	while ((get_next_line(mast->fd, &mast->ln)))
	{
		if (mast->j == 0 && i == 1)
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
		parse_two(mast, i);
		free(mast->ln);
		mast->ln = NULL;
		if (mast->j >= mast->mylen + mast->tylen + 2)
			break ;
		mast->j++;
	}
	free(mast->ln);
	if (i == 1)
		mappts(mast);
}
