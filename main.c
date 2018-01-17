/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:28:21 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/16 23:28:05 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	put_peice(t_mast *mast)
{
		if (mast->player == 'o')
		{
			ft_putchar(mast->o[0] + '0');
			ft_putchar(' ');
			ft_putchar(mast->o[1] + '0');
		}
		else if (mast->player == 'x')
		{
			ft_putchar(mast->x[0] + '0');
			ft_putchar(' ');
			ft_putchar(mast->x[1] + '0');
		}
		ft_putchar('\n');
}

int		main(int ac, char **av) //? name = filler
{
	t_mast mast;

	ft_bzero(&mast, sizeof(mast));//sets everything to zero
	char *place = "0 0";
	//mast.filename = "map";//mast.filename = av[1]; //change back this when done testing

	//mast.tpts = (int**)malloc(sizeof(int*) * 2);

	int i = 0;
	while (i < 3)
	{
		mast.j = 0;
		if (i == 0) //find what player you are
		{
			get_next_line(0, &mast.ln);
			if (mast.ln[10] == '1')
				mast.player = 'o';
			else if (mast.ln[10] == '2')
				mast.player = 'x';
			//printf("p1:%c", mast.player);
		}
		else if (i == 1) //parse the board
		{
			mast.list = NULL;
			mast.mytok = NULL;
			mast.newlist = NULL;
			////mast.opptok = NULL;
			// mast.mytok = NULL;
			// mast.mytok2 = NULL;
			// mast.mytok = (t_points*)malloc(sizeof(t_points));
			// mast.mytok2 = mast.mytok;
			// //mast.opptok = (t_points*)malloc(sizeof(t_points));
			parse(&mast, i);
			// free(mast.mytok);
			// mast.mytok = NULL;
			while (mast.mytok)
			{
				printf("\n(%d, %d)\n", mast.mytok->pts[0], mast.mytok->pts[1]);
				mast.mytok = mast.mytok->next;
			}
		}
		if (i >= 1) //place peice
		{

			
			//parse
			//compare
			//find closest valid place on my peices (for all points of my new token) to thier farthest point from their old stars
			//decide what direction to place to determine if top/left(moves towards bottom/right) point
			//place token point you want at a certain position with this math ((mast->map[y - mast->token[0]][x - mast->token[1]])) for (0, 0)

			//put_peice(&mast);
			;
		}
		i++;
		//if (i = 3)
		//parse(&mast);
	}
	//printf("Player: %c, map: (%d, %d), Token: (%d, %d)\n", mast.player, mast.mylen, mast.mxlen, mast.tylen, mast.txlen); ///////////////////
	// ft_putarr(mast.map);
	// ft_putarr(mast.token);
	// if (mast.map)
	// 	free_array(mast.map);
	// if (mast.token)
	// 	free_array(mast.token);
	// printf("X:(%d, %d)\n", mast.x[0], mast.x[1]);
	// printf("O:(%d, %d)\n", mast.o[0], mast.o[1]);
	return (0);
}
