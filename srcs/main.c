/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:28:21 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/21 22:15:11 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** beats carli half the time when I'm player 2
** ablian 50/50 me player 1
*/

#include "filler.h"

void	put_peice(t_mast *mast)
{
	ft_putnbr(mast->startpt[0]);
	ft_putchar(' ');
	ft_putnbr(mast->startpt[1]);
	ft_putchar('\n');
}

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
** set my point and oppontes point only in beggining
*/

void	set_me_opp(t_mast *mast)
{
		if (mast->player == 'O')
		{
			mast->oppt[0] = mast->x[0];
			mast->oppt[1] = mast->x[1];
			mast->mypt[0] = mast->o[0];
			mast->mypt[1] = mast->o[1];
		}
		else if (mast->player == 'X')
		{
			mast->oppt[0] = mast->o[0];
			mast->oppt[1] = mast->o[1];
			mast->mypt[0] = mast->x[0];
			mast->mypt[1] = mast->x[1];
		}
		mast->stars = 1;
}

/*
** find what player you are
*/

void	find_player(t_mast *mast)
{
	get_next_line(mast->fd, &mast->ln);
	if (mast->ln[10] == '1')
	{
		mast->player = 'O';
		mast->opponent = 'X';
	}
	else if (mast->ln[10] == '2')
	{
		mast->player = 'X';
		mast->opponent = 'O';
	}
	free(mast->ln);
}

/*
**	parse
**	compare
**	find closest valid place on my peices (for all points of my new token) to thier farthest point from their old stars
**	decide what direction to place to determine if top/left(moves towards bottom/right) point
**	place token point you want at a certain position with this math ((mast->map[y - mast->token[0]][x - mast->token[1]])) for (0, 0)
*/

int		main(int ac, char **av)
{
	t_mast mast;
	int i;

	ft_bzero(&mast, sizeof(mast));
	mast.fd = 0;
//	mast.fd = open("testmap1.1.txt", O_RDONLY);/////get rid of when reading from stdin
	i = 0;

		mast.mlx = mlx_init();
		mast.win = mlx_new_window(m.mlx, m.wsize, m.wsize, av[1]);

	//while (i <= 18)//while (1)//i < 5)	
	while (1)
	{
		mast.j = 0;
		//mast.i = 0;
		mast.stars = 0;
		if (i == 0)
			find_player(&mast);
		if (i >= 1)// && i <= 4)// (i >= 1) //place peice
		{
			parse(&mast, i);
			if (i == 1)
				set_me_opp(&mast);
			compare(&mast);
			if (place_pt(&mast) == 0)
			{
				mast.startpt[0] = 0;
				mast.startpt[1] = 0;
				put_peice(&mast);
				break ;
			}
			else
				put_peice(&mast);
			// printf("i = %d\n", i);
			// printf("opp:(%d, %d)\n", mast.oppt[0], mast.oppt[1]);
			// printf("me:(%d, %d)\n", mast.mypt[0], mast.mypt[1]);
			// printf("Player: %c, map: (%d, %d), Token: (%d, %d)\n", mast.player, mast.mylen, mast.mxlen, mast.tylen, mast.txlen); ///////////////////
			cpy_map(&mast);
		}
		i++;
	}
	//printf("Player: %c, map: (%d, %d), Token: (%d, %d)\n", mast.player, mast.mylen, mast.mxlen, mast.tylen, mast.txlen); ///////////////////
	if (mast.map)
		free_array(mast.map);
//	close(mast.fd);//get rid of when reading from stdin
	return (0);
}
