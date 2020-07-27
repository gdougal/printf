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

static long	ft_write_minus(long num)
{
	write(1, "-", 1);
	return (num *= -1);
}

static int	ft_mns_int(t_print_struct *res_pars, long num)
{
	int	len;
	int	zr0;
	int	spcs;

	spcs = 0;
	len = (!res_pars->precision && !num ? 0 : ft_nmbrlen(num, 10));
	zr0 = res_pars->precision - len;
	len += zr0 > 0 ? zr0 : 0;
	if ((zr0 <= 0 && !res_pars->width) || ((res_pars->flags & FLAG_ZERO)
			&& res_pars->precision < 0))
		num = ft_write_minus(num);
	if ((res_pars->flags & FLAG_ZERO) && res_pars->precision < 0)
		spcs += ft_putchar_n('0', res_pars->width - len - 1);
	else if (!(res_pars->flags & FLAG_MINUS) && res_pars->width)
		spcs += ft_putchar_n(' ', res_pars->width - len - 1);
	if ((zr0 > 0 || res_pars->width) && res_pars->precision > 0)
		num = ft_write_minus(num);
	ft_putchar_n('0', zr0);
	if (len > 0)
		ft_putnbr_fd(num, 1);
	if ((res_pars->flags & FLAG_MINUS) && res_pars->width)
		spcs += ft_putchar_n(' ', res_pars->width - len - 1);
	len += spcs;
	return (len + 1);
}

int			ft_integer(t_print_struct *res_pars, va_list *argptr)
{
	long	num;
	int		len;
	int		spcs;
	int		zr0;

	spcs = 0;
	num = va_arg(*argptr, int);
	if (num >= 0)
	{
		len = (!res_pars->precision && !num ? 0 : ft_nmbrlen(num, 10));
		zr0 = res_pars->precision - len;
		len += zr0 > 0 ? zr0 : 0;
		if ((res_pars->flags & FLAG_ZERO) && res_pars->precision < 0)
			spcs += ft_putchar_n('0', res_pars->width - len);
		else if (!(res_pars->flags & FLAG_MINUS) && res_pars->width)
			spcs += ft_putchar_n(' ', res_pars->width - len);
		ft_putchar_n('0', zr0);
		if (len > 0)
			ft_putnbr_fd(num, 1);
		if ((res_pars->flags & FLAG_MINUS) && res_pars->width)
			spcs += ft_putchar_n(' ', res_pars->width - len);
	}
	else
		len = ft_mns_int(res_pars, num);
	return (len + spcs);
}
