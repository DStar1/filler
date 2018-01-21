/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:28:21 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/21 02:01:15 by hasmith          ###   ########.fr       */
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
	
	
	
	mast.fd = 0;
//	mast.fd = open("testmap1.1.txt", O_RDONLY);/////get rid of when reading from stdin
	
	
	
	
	
	
	
	//mast.tpts = (int**)malloc(sizeof(int*) * 2);

	int i = 0;
	//while (i <= 18)//while (1)//i < 5)
	while (1)
	{
		mast.j = 0;
		//mast.i = 0;
		mast.stars = 0;
		if (i == 0) //find what player you are
		{
			get_next_line(mast.fd, &mast.ln);
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


			i++;
			
			//printf("p1:%c", mast.player);
		}
		// else if (i == 1) //parse the board
		// {
		// 	parse(&mast, i);

		// 	// for (int p = 0; p < mast.stars; p++) //print my token coords
		// 	// {
		// 	// 	printf("\n(%d, %d)\n", mast.tpts[p][0], mast.tpts[p][1]);
		// 	// }
		// }
		
		// if (i == 1)// (i >= 1) //place peice
		// {
		// 	parse(&mast, i);
		// 			// printf("X:(%d, %d)\n", mast.x[0], mast.x[1]);
		// 			// printf("O:(%d, %d)\n", mast.o[0], mast.o[1]);
		// 	set_me_opp(&mast);
		// 	place_pt(&mast);//reorder the token points based on direction to start with
		// 	compare(&mast);
		// 	find_closest_pnt(&mast);


		// 	put_peice(&mast);
		// 	////check_opp(&mast);
			
		// 	//parse
		// 	//compare
		// 	//find closest valid place on my peices (for all points of my new token) to thier farthest point from their old stars
		// 	//decide what direction to place to determine if top/left(moves towards bottom/right) point
		// 	//place token point you want at a certain position with this math ((mast->map[y - mast->token[0]][x - mast->token[1]])) for (0, 0)

		// 	//put_peice(&mast);
		// 	;
		// }
		if (i >= 1)// && i <= 4)// (i >= 1) //place peice
		{
			parse(&mast, i);
			if (i == 1)
				set_me_opp(&mast);

			
			// for (int e = 0; e < mast.stars; e++)
			// 	printf("valid? (%d, %d)\n", mast.tpts[e][0], mast.tpts[e][1]);
			compare(&mast);
			// 			printf("past compare. Token dimentions = (%d, %d)\n", mast.tylen, mast.txlen);
			// printf("opp:(%d, %d)\n", mast.oppt[0], mast.oppt[1]);
			// printf("me:(%d, %d)\n", mast.mypt[0], mast.mypt[1]);
			place_pt(&mast);//reorder the token points based on direction to start with
						//printf("me:(%d, %d)\n", mast.mypt[0], mast.mypt[1]);
						// printf("stars:%d\n", mast.stars);
			//find_closest_pnt(&mast);
						//printf("past place\n");

			put_peice(&mast);

			// printf("i = %d\n", i);
			// printf("opp:(%d, %d)\n", mast.oppt[0], mast.oppt[1]);
			// printf("me:(%d, %d)\n", mast.mypt[0], mast.mypt[1]);
			
			// printf("Player: %c, map: (%d, %d), Token: (%d, %d)\n", mast.player, mast.mylen, mast.mxlen, mast.tylen, mast.txlen); ///////////////////
			cpy_map(&mast);
		}


		// if (i == 18)
		// 	break ;




		i++;
		//if (i = 3)
		//parse(&mast);
	}
	//printf("Player: %c, map: (%d, %d), Token: (%d, %d)\n", mast.player, mast.mylen, mast.mxlen, mast.tylen, mast.txlen); ///////////////////
	// ft_putarr(mast.map);
	// ft_putarr(mast.token);
	if (mast.map)
		free_array(mast.map);



		
	close(mast.fd);//get rid of when reading from stdin




	// if (mast.token)
	// 	free_array(mast.token);
	// printf("X:(%d, %d)\n", mast.x[0], mast.x[1]);
	// printf("O:(%d, %d)\n", mast.o[0], mast.o[1]);
	return (0);
}
