/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:31:22 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/16 23:28:09 by hasmith          ###   ########.fr       */
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

void	tokenpts(t_mast *mast, char **line)
{
	int x;


	mast->i = 0;
	x = 0;
	while (x < mast->txlen)
	{
		// if (mast->token[y][x] == '*' && cnt == 1)
		// 	mast->stars++;
		// else 
		if (*line[x] == '*')
		{
			// mast->tpts[mast->i] = (int*)malloc(sizeof(int) * 2);
			// mast->tpts[mast->i][0] = mast->mylen + 3;
			// mast->tpts[mast->i][1] = x;
			//printf("(%d, %d)\n", mast->tpts[mast->i][0], mast->tpts[mast->i][1]); ////////////
			mast->newlist = (t_points*)malloc(sizeof(t_points));
			mast->newlist->pts[0] = mast->j - (mast->mylen + 3);
			mast->newlist->pts[1] = x;
			mast->newlist->next = 0;
			if (!mast->mytok)
				mast->mytok = mast->newlist;
			if (!mast->list)
				mast->list = mast->newlist;
			else
			{
				mast->list->next = mast->newlist;
				mast->list = mast->newlist;
			}
			
			// ////changed to liked list
			// 	mast->mytok = (t_points*)malloc(sizeof(t_points));
			// 	mast->mytok->pts[0] = mast->j - (mast->mylen + 3);//y;  
			// 	mast->mytok->pts[1] = x;
			// 	mast->mytok->next = 0;
			// 	if (!mast->mytok2)
			// 		mast->mytok2 = mast->mytok;
			// 	//printf("(%d, %d)\n", mast->mytok->pts[0], mast->mytok->pts[1]);//mast->j - (mast->mylen + 3), x);//
			// 	 //allocate space for list
			// 	mast->mytok = mast->mytok->next;
				
		}
		x++;
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

void	cpy_map(t_mast *mast)
{
	int i;

	i = 0;
	while (i < mast->mylen)
	{
		ft_memcpy(mast->map2[i], mast->map[i], sizeof(mast->map[i]));
		i++;
	}
}

void	parse(t_mast *mast , int i)
{
	char		*line;

	line = mast->ln;
	while ((get_next_line(0, &line)))
	{
		// //EXIT(/*exit if somthing*/);
		if (mast->j == 0) //saves map dimentions
		{
			mast->mylen = f_atoi(&line, 8);
			mast->mxlen = f_atoi(&line, 9 + ft_intlen(mast->mylen));
			if (i == 1)
			{
				mast->map = (char**)malloc(sizeof(char*) * mast->mylen + 1);
				mast->map2 = (char**)malloc(sizeof(char*) * mast->mylen + 1);
				mast->map[mast->mylen] = NULL;
				mast->map2[mast->mylen] = NULL;
			}
		}
		if ((mast->j >= 2 && mast->j < mast->mylen + 2) && i == 1) //saves map int 2 2d arrays
		{
			mast->map[mast->i] = ft_strsub(line, 4, ft_strlen(line) - 4);
			mast->map2[mast->i] = ft_strsub(line, 4, ft_strlen(line) - 4);
			mast->i++;
		}
		else if (mast->j >= 2 && mast->j < mast->mylen + 2) //copies new map to mast->map
		{
			ft_memcpy(mast->map[mast->i++], line, sizeof(line));
			//mast->map2[mast->i++] = ft_strsub(line, 4, ft_strlen(line) - 4);
		}
		if (mast->mylen && mast->j == mast->mylen + 2) //saves token dimentions
		{
			mast->tylen = f_atoi(&line, 6);
			mast->txlen = f_atoi(&line, 7 + ft_intlen(mast->tylen));
			mast->i = 0;
		}
		if (mast->j >= mast->mylen + 3 && mast->j < mast->mylen + 3 + mast->tylen) //for the token
		{
			tokenpts(mast, &line);
									//mast->token[mast->i++] = ft_strsub(line, 0, ft_strlen(line));
									//printf("%d\n", mast->j - (mast->mylen + 3));
		}
		if (mast->j == mast->mylen + 3 + mast->tylen) //for linked list
		{
			free(mast->mytok);
			mast->mytok = NULL;
		}
		free(line);
		line = NULL;
		if (mast->j >= mast->mylen + mast->tylen + 2)
			break ;
		mast->j++;
	}
	free(line);
	printf("player: %c,(%d, %d), (%d, %d)\n", mast->player, mast->mylen, mast->mxlen, mast->tylen, mast->txlen); ///////////////////

	mappts(mast);
}
