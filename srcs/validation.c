/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:24:47 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/22 20:44:16 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** check if is it possible to place all points onto the map
*/

int		if_out_of_bounds(t_mast *m, int y1, int x1, int i)
{
	if (((m->tpts[i][0] + y1) >= 0 && (m->tpts[i][0] + y1) < m->mylen)
	&& ((m->tpts[i][1] + x1) >= 0 && (m->tpts[i][1] + x1) < m->mxlen))
	{
		if (m->map[m->tpts[i][0] + y1][m->tpts[i][1] + x1] == '.')
			m->ret++;
		else if (m->map[m->tpts[i][0] + y1][m->tpts[i][1] + x1] == m->player)
		{
			m->plcnt++;
		}
		else
			return (1);
	}
	else
		return (1);
	return (0);
}

int		check_valid(t_mast *m, int y, int x, int index)
{
	int i;
	int y1;
	int x1;

	i = 0;
	m->ret = 0;
	m->plcnt = 0;
	y1 = y - (m->tpts[index][0]);
	x1 = x - (m->tpts[index][1]);
	while (i < m->stars)
	{
		if (if_out_of_bounds(m, y1, x1, i) == 1)
			return (0);
		i++;
	}
	if (m->ret == m->stars - 1 && m->plcnt == 1)
	{
		m->startpt[0] = y - (m->tpts[index][0]);
		m->startpt[1] = x - (m->tpts[index][1]);
		return (1);
	}
	return (0);
}

/*
** iterates through token tpts either from 0 or from the last index
** depending on int last's value. 1 to start at last, 0 for 0
*/

int		token_last(t_mast *m, int y, int x, int last)
{
	int index;
	int iter;

	index = 0;
	iter = 1;
	if (last == 1)
	{
		index = m->stars - 1;
		while (index >= 0)
		{
			if (check_valid(m, y, x, index) == 1)
				return (1);
			index--;
		}
	}
	else
	{
		while (index < m->stars)
		{
			if (check_valid(m, y, x, index) == 1)
				return (1);
			index++;
		}
	}
	return (0);
}

void	put_peice(t_mast *mast)
{
	ft_putnbr(mast->startpt[0]);
	ft_putchar(' ');
	ft_putnbr(mast->startpt[1]);
	ft_putchar('\n');
}
