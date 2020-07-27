/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmbrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <dougal@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 01:21:20 by gdougal           #+#    #+#             */
/*   Updated: 2020/07/24 01:21:43 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nmbrlen(long num, int base)
{
	int	res;

	res = (num ? 0 : 1);
	while (num)
	{
		num /= base;
		res++;
	}
	return (res);
}
