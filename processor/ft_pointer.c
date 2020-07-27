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

int	ft_pointer(t_print_struct *res_pars, va_list *argptr)
{
	size_t	num;
	int		len;
	int		spcs;
	int		zr0;

	spcs = 0;
	num = va_arg(*argptr, size_t);
	len = 2 + ft_nmbrlen(num, 16);
	zr0 = res_pars->precision - len;
	if (res_pars->precision >= 0 && res_pars->precision > len - 2)
		len = res_pars->precision + 2;
	if (!(res_pars->flags & FLAG_MINUS) && res_pars->width)
		spcs += ft_putchar_n(' ', res_pars->width - len);
	write(1, "0x", 2);
	ft_putchar_n('0', zr0);
	ft_putnbr_base_fd(num, 16, 1, 0);
	if ((res_pars->flags & FLAG_MINUS) && res_pars->width)
		spcs += ft_putchar_n(' ', res_pars->width - len);
	len += spcs;
	return (len);
}
