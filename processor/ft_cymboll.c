/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <dougal@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 11:08:39 by gdougal           #+#    #+#             */
/*   Updated: 2020/07/27 11:08:42 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_proc.h"

int	ft_cymboll(t_print_struct *res_pars, va_list *argptr)
{
	char	c;
	int		len;

	len = 1;
	c = va_arg(*argptr, int);
	if (!(res_pars->flags & FLAG_MINUS) && res_pars->width)
		len += ft_putchar_n(' ', res_pars->width - 1);
	write(1, &c, 1);
	if ((res_pars->flags & FLAG_MINUS) && res_pars->width)
		len += ft_putchar_n(' ', res_pars->width - 1);
	return (len);
}
