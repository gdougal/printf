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

#include "ft_parser.h"
#include "ft_proc.h"

int	ft_post_parse(t_print_struct *res_pars, va_list *argptr)
{
	int len;

	len = 0;
	if (res_pars->type == 'c')
		len = ft_cymboll(res_pars, argptr);
	else if (res_pars->type == 's')
		len = ft_string(res_pars, argptr);
	else if (res_pars->type == 'p')
		len = ft_pointer(res_pars, argptr);
	else if (res_pars->type == 'd' || res_pars->type == 'i')
		len = ft_integer(res_pars, argptr);
	else if (res_pars->type == 'u')
		len = ft_unsigned(res_pars, argptr);
	else if (res_pars->type == 'x' || res_pars->type == 'X')
		len = ft_hex(res_pars, argptr);
	else if (res_pars->type == '%')
		len = ft_percent(res_pars);
	return (len);
}
