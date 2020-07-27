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

int	ft_string(t_print_struct *res_pars, va_list *argptr)
{
	char	*s;
	int		len;
	int		spcs;

	spcs = 0;
	s = va_arg(*argptr, char*);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (res_pars->precision >= 0 && res_pars->precision < len)
		len = res_pars->precision;
	if (!(res_pars->flags & FLAG_MINUS) && res_pars->width)
		spcs += ft_putchar_n(' ', res_pars->width - len);
	write(1, s, len);
	if ((res_pars->flags & FLAG_MINUS) && res_pars->width)
		spcs += ft_putchar_n(' ', res_pars->width - len);
	len += spcs;
	return (len);
}
