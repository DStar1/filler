/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:31:22 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/13 18:55:54 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Parse through data to store what player you are,
** the map, and the token
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

void	tokenpts(t_mast *mast)
{
	int y;
	int x;
	int cnt;
	
	cnt = 1;
	mast->i = 0;
	while (cnt <= 2)
	{
		y = 0;
		while (y < mast->tylen)
		{
			x = 0;
			while (x < mast->txlen)
			{
				if (mast->token[y][x] == '*' && cnt == 1)
					mast->stars++;
				else if (mast->token[y][x] == '*')
				{
					mast->tpts[mast->i] = (int*)malloc(sizeof(int) * 2);
					mast->tpts[mast->i][0] = y;
					mast->tpts[mast->i][1] = x;
					printf("(%d, %d)\n", mast->tpts[mast->i][0], mast->tpts[mast->i][1]); ////////////
				}
				x++;
			}
			y++;
		}
		if (cnt == 1)
			mast->tpts = (int**)malloc(sizeof(int*) * mast->stars);
		cnt++;
	}
}

int		f_atoi(char **line, int start)
{
	int start1;
	int nb;

	nb = 0;
	start1 = start;
	while (line[0][start] && ft_isdigit(line[0][start]))
	{
		nb += (line[0][start] - '0');
		nb *= 10;
		start++;
	}
	nb /= 10;
	return (nb);
}

void	parse(t_mast *mast)
{
	int			fd;
	char		*line;

	line = NULL;
	EXIT((fd = open(mast->filename, O_RDONLY)) == -1);
	while ((get_next_line(fd, &line)))
	{
		//EXIT(/*exit if somthing*/);
		if (mast->j == 0) //this number is dependant on what line it is
			mast->user1 = ft_strsub(line, 15, ft_strlen(line) - 16);
		if (mast->j == 1) //this number is dependant on what line it is
			mast->user2 = ft_strsub(line, 15, ft_strlen(line) - 16);
		if (mast->j == 2) //this number is dependant on what line it is
		{
			mast->mylen = f_atoi(&line, 8);
			mast->mxlen = f_atoi(&line, 9 + ft_intlen(mast->mylen));
			mast->map = (char**)malloc(sizeof(char*) * mast->mylen + 1);
			mast->map[mast->mylen] = NULL;
		}
		if (mast->j >= 4 && mast->j < mast->mylen + 4)
			mast->map[mast->i++] = ft_strsub(line, 4, ft_strlen(line) - 4);
		if (mast->mylen && mast->j == mast->mylen + 4) ////this number is dependant on what line it is
		{
			mast->tylen = f_atoi(&line, 6);
			mast->txlen = f_atoi(&line, 7 + ft_intlen(mast->tylen));
			mast->token = (char**)malloc(sizeof(char*) * mast->tylen + 1);
			mast->token[mast->tylen] = NULL;
			mast->i = 0;
		}
		if (mast->j >= mast->mylen + 5 && mast->j < mast->mylen + 5 + mast->tylen)
			mast->token[mast->i++] = ft_strsub(line, 0, ft_strlen(line));
		mast->j++;
		free(line);
		line = NULL;
	}
	close(fd);
	free(line);
	printf("user1: %s, user2: %s,(%d, %d), (%d, %d)\n", mast->user1, mast->user2, mast->mylen, mast->mxlen, mast->tylen, mast->txlen); ///////////////////
	tokenpts(mast);
	mappts(mast);
}
