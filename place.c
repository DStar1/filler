/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 21:03:09 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/17 21:58:21 by hasmith          ###   ########.fr       */
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

void	place_up_r(t_mast *mast)
{
	//highest y point, with the lowest x

}

void	place_down_r(t_mast *mast)
{
	//lowest y point, with the lowest x
	//token[0]//first pt
	mast->tokindex = 0;
}

void	place_up_l(t_mast *mast)
{
	//highest y point, with the highest x
	//token[stars]//last pt
	mast->tokindex = mast->stars;
}

void	place_down_l(t_mast *mast)
{
	//lowest y point, with the highest x
}

void	place_pt(t_mast *mast)
{
	if (mast->oppt[0] < mast->mypt[0] && mast->oppt[1] < mast->mypt[1])
		place_up_l(mast);
	if (mast->oppt[0] < mast->mypt[0] && mast->oppt[1] > mast->mypt[1])
		place_down_l(mast);
	if (mast->oppt[0] > mast->mypt[0] && mast->oppt[1] < mast->mypt[1])
		place_up_r(mast);
	if (mast->oppt[0] < mast->mypt[0] && mast->oppt[1] < mast->mypt[1])
		place_down_r(mast);
}