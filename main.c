/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:28:21 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/15 20:28:07 by hasmith          ###   ########.fr       */
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
			parse(&mast, i);
		if (i >= 1) //place peice
		{
			//parse
			//compare
			//decide what direction to place to determine if top/left(moves towards bottom/right) point
			//find closest valid place on my peices (for all points of my new token) to thier last piece
			//place token at ((mast->map[y - mast->token[0]][x - mast->token[1]]))

			put_peice(&mast);
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
