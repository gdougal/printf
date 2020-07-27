/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_changer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <dougal@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:07:41 by gdougal           #+#    #+#             */
/*   Updated: 2020/07/25 15:07:43 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_base_changer(size_t dec, int base)
{
	int		num_len;
	char	*num;
	size_t	tmp;
	char	*hex;

	hex = "abcdef";
	num_len = ft_nmbrlen(dec, base);
	num = malloc((num_len + 1) * sizeof(char));
	while (num_len)
	{
		tmp = dec % base;
		if (tmp < 10)
			num[num_len - 1] = tmp + '0';
		else if (tmp >= 10)
			num[num_len - 1] = hex[tmp - 10];
		dec = dec / base;
		num_len--;
	}
	return (num);
}
