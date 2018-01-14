/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:28:21 by hasmith           #+#    #+#             */
/*   Updated: 2018/01/13 18:55:45 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(int ac, char **av) //? name = filler
{
	t_mast mast;

	ft_bzero(&mast, sizeof(mast));//sets everything to zero
	mast.filename = "map";//mast.filename = av[1]; //change back this when done testing
	parse(&mast);
	ft_putarr(mast.map);
	ft_putarr(mast.token);
	if (mast.map)
		free_array(mast.map);
	if (mast.token)
		free_array(mast.token);
	printf("X:(%d, %d)\n", mast.x[0], mast.x[1]);
	printf("O:(%d, %d)\n", mast.o[0], mast.o[1]);
	// if (mast.ln)
	// 	free(mast.ln);
	return (0);
}
