/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:28:21 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/22 22:36:58 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

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
**	find closest valid place on of both opp and me
**	decide what direction, top/left(moves towards bottom/right) point
**	place token point you want at a certain position
*/

int		check_i(t_mast *mast, int i)
{
	if (i == 0)
		find_player(mast);
	if (i >= 1)
	{
		parse(mast, i);
		put_new_map(mast);
		if (i == 1)
			set_me_opp(mast);
		compare(mast);
		if (place_pt(mast) == 0)
		{
			mast->startpt[0] = 0;
			mast->startpt[1] = 0;
			put_peice(mast);
			return (1);
		}
		else
			put_peice(mast);
		cpy_map(mast);
	}
	return (0);
}

int		my_key_funct(int keycode, t_mast *mast)
{
	if (keycode == 53)
		exit(1);
	return (0);
}

int		main(int ac, char **av)
{
	t_mast	mast;
	int		i;

	ft_bzero(&mast, sizeof(mast));
	mast.wsize = 1000;
	mast.mlx = mlx_init();
	mast.win = mlx_new_window(mast.mlx, mast.wsize, mast.wsize, "FILLER");
	pixel_str(&mast);
	i = 0;
	while (1)
	{
		mast.j = 0;
		mast.stars = 0;
		if (check_i(&mast, i) == 1)
			break ;
		i++;
		mlx_hook(mast.win, 2, 0, my_key_funct, &mast);
		mlx_do_sync(mast.mlx);
	}
	if (mast.map)
		free_array(mast.map);
	mlx_destroy_image(mast.mlx, mast.img_ptr);
	sleep(3);
	return (0);
}
