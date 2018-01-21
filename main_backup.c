/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_txt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:28:21 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/20 17:59:57 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		//ft_memcpy(mast->map2[i], mast->map[i], sizeof(mast->map[i]));
		y++;
	}
}

// static void	check_opp(t_mast *mast)
// {
// 	int y;
// 	int x;

// 	y = 0;
// 	while (y < mast->mylen)
// 	{
// 		x = 0;
// 		while (x < mast->mxlen)
// 		{
// 			if (mast->player == 'O' && mast->map[y][x] == 'X')
// 				put_peice(mast);
// 			else if (mast->player == 'X' && mast->map[y][x] == 'O')
// 				put_peice(mast);
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	set_me_opp(t_mast *mast)
{
		if (mast->player == 'O') 									//set my point and oppontes point only in beggining
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

int		main(int ac, char **av) //? name = filler
{
	t_mast mast;

	ft_bzero(&mast, sizeof(mast));//sets everything to zero
	char *place = "0 0";
	//mast.filename = "map";//mast.filename = av[1]; //change back this when done testing
	//mast.tpts = (int**)malloc(sizeof(int*) * 2);

	int i = 0;
	while (1)//i < 5)
	{
		mast.j = 0;
		//mast.i = 0;
		mast.stars = 0;
		if (i == 0) //find what player you are
		{
			get_next_line(0, &mast.ln);
			if (mast.ln[10] == '1')
			{
				mast.player = 'O';
				mast.opponent = 'X';
			}
			else if (mast.ln[10] == '2')
			{
				mast.player = 'X';
				mast.opponent = 'O';
			}
			free(mast.ln);
			//printf("p1:%c", mast.player);
		}
		if (i >= 1)// && i <= 4)// (i >= 1) //place peice
		{
			parse(&mast, i);
			if (i == 1)
				set_me_opp(&mast);

			
			// for (int e = 0; e < mast.stars; e++)
			// 	printf("valid? (%d, %d)\n", mast.tpts[e][0], mast.tpts[e][1]);
			compare(&mast);
			place_pt(&mast);//reorder the token points based on direction to start with
						//printf("me:(%d, %d)\n", mast.mypt[0], mast.mypt[1]);
						// printf("stars:%d\n", mast.stars);
			//find_closest_pnt(&mast);

			put_peice(&mast);
			
			// printf("opp:(%d, %d)\n", mast.oppt[0], mast.oppt[1]);
			// printf("me:(%d, %d)\n", mast.mypt[0], mast.mypt[1]);
			// printf("Player: %c, map: (%d, %d), Token: (%d, %d)\n", mast.player, mast.mylen, mast.mxlen, mast.tylen, mast.txlen); ///////////////////
			cpy_map(&mast);
		}
		i++;
		//if (i = 3)
		//parse(&mast);
	}
	//printf("Player: %c, map: (%d, %d), Token: (%d, %d)\n", mast.player, mast.mylen, mast.mxlen, mast.tylen, mast.txlen); ///////////////////
	// ft_putarr(mast.map);
	// ft_putarr(mast.token);
	if (mast.map)
		free_array(mast.map);
	// if (mast.token)
	// 	free_array(mast.token);
	// printf("X:(%d, %d)\n", mast.x[0], mast.x[1]);
	// printf("O:(%d, %d)\n", mast.o[0], mast.o[1]);
	return (0);
}
