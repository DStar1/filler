/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 21:03:09 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/18 21:25:24 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

void	place_up_r(t_mast *mast, int *i) //not complete
{
	//highest y point, with the lowest x
	if (mast->tpts[*i][1] < mast->tpts[*i + 1][1])
	{
		ft_swap(&mast->tpts[*i + 1][0], &mast->tpts[*i][0]);
		ft_swap(&mast->tpts[*i + 1][1], &mast->tpts[*i][1]);
		*i = -1;
	}
}

void	place_down_r(t_mast *mast, int *i)
{
	//lowest y point, with the lowest x
	//token[0]//first pt
	//mast->tokindex = 0;
	if (mast->tpts[*i][0] + mast->tpts[*i][1] < mast->tpts[*i + 1][0] + mast->tpts[*i][1])
	{
		ft_swap(&mast->tpts[*i + 1][0], &mast->tpts[*i][0]);
		ft_swap(&mast->tpts[*i + 1][1], &mast->tpts[*i][1]);
		*i = -1;
	}
}

void	place_up_l(t_mast *mast, int *i) 
{
	//highest y point, with the highest x
	//token[stars]//last pt
	//mast->tokindex = mast->stars;
	if (mast->tpts[*i][0] + mast->tpts[*i][1] > mast->tpts[*i + 1][0] + mast->tpts[*i][1])
	{
		ft_swap(&mast->tpts[*i + 1][0], &mast->tpts[*i][0]);
		ft_swap(&mast->tpts[*i + 1][1], &mast->tpts[*i][1]);
		*i = -1;
	}
}

void	place_down_l(t_mast *mast, int *i) //not complete
{
	//lowest y point, with the highest x
	if (mast->tpts[*i][1] > mast->tpts[*i + 1][1])
	{
		ft_swap(&mast->tpts[*i + 1][0], &mast->tpts[*i][0]);
		ft_swap(&mast->tpts[*i + 1][1], &mast->tpts[*i][1]);
		*i = -1;
	}
}

void	place_pt(t_mast *mast)
{
	int i;
	// int j;

	i = 0;
	// j = 0;
	// mast->tpt[0] = mast->tpts[i][0];
	// mast->tpt[1] = mast->tpts[i][1];
	while (i < mast->stars - 1)
	{
		if (mast->oppt[0] < mast->mypt[0] && mast->oppt[1] < mast->mypt[1])
			place_up_l(mast, &i);
		else if (mast->oppt[0] < mast->mypt[0] && mast->oppt[1] > mast->mypt[1])
			place_down_l(mast, &i);
		else if (mast->oppt[0] > mast->mypt[0] && mast->oppt[1] < mast->mypt[1])
			place_up_r(mast, &i);
		else if (mast->oppt[0] < mast->mypt[0] && mast->oppt[1] < mast->mypt[1])
			place_down_r(mast, &i);
		i++;
	}
	// if (mast->stars == 2)
	// {

	// }
}