/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 15:57:42 by hasmith           #+#    #+#             */
/*   Updated: 2017/09/24 17:12:32 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnbr(char *c)
{
	if (*c == '-')
		c++;
	while (*c)
	{
		if (!(ft_isdigit(*c)))
			return (0);
		c++;
	}
	return (1);
}