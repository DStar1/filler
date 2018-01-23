/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:46:31 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/22 20:57:03 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** creates a string with alocated space for all pixels on screen
*/

void	pixel_str(t_mast *m)
{
	m->img_ptr = mlx_new_image(m->mlx, m->wsize, m->wsize);
	m->img_int = (int*)mlx_get_data_addr(
		m->img_ptr, &m->bpp, &m->size_line, &m->endian);
}

/*
** puts all pixles to screen, and then destroys the image
** mlx_destroy_image(m->mlx, m->img_ptr); to destroy
*/

void	create_image(t_mast *m)
{
	mlx_put_image_to_window(m->mlx, m->win, m->img_ptr, 0, 0);
}

/*
** draws to screen map to screen
*/

void	draw(t_mast *mast, int y1, int x1, int color)
{
	int x;
	int y;
	int x_dist;
	int y_dist;

	y_dist = (mast->wsize / mast->mylen);
	x_dist = (mast->wsize / mast->mxlen);
	y = y1 * y_dist;
	while (y < ((y1 * y_dist) + y_dist))
	{
		x = x1 * x_dist;
		while (x < ((x1 * x_dist) + x_dist))
		{
			if (x < mast->wsize && y < mast->wsize)
				if (y >= 0 && x >= 0)
					if (x != x1 * x_dist && y != y1 * y_dist)
						mast->img_int[((y * mast->wsize) + x)] = color;
			x++;
		}
		y++;
	}
}

void	put_new_map(t_mast *mast)
{
	int y;
	int x;

	y = 0;
	while (y < mast->mylen)
	{
		x = 0;
		while (x < mast->mxlen)
		{
			if (mast->map[y][x] == mast->player)
				draw(mast, y, x, 0x000099);
			if (mast->map[y][x] == mast->opponent)
				draw(mast, y, x, 0x990000);
			x++;
		}
		y++;
	}
	create_image(mast);
}
