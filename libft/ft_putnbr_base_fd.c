/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <dougal@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:11:46 by gdougal           #+#    #+#             */
/*   Updated: 2020/07/25 17:11:56 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(long long n, int base, int fd, int reg)
{
	char			num;
	long long		i;
	long long		j;
	int				sign;

	i = n;
	j = base;
	sign = n < 0 ? -1 : 1;
	while (i /= base)
		j *= base;
	if (sign < 0)
		write(fd, "-", 1);
	while (j /= base)
	{
		i = ((n / j) * sign);
		if (i > 9 && i < 35)
			num = (char)(i + (reg ? 55 : 87));
		else if (i >= 0 && i <= 9)
			num = (char)(i + '0');
		write(fd, &num, 1);
		n %= j;
	}
}
