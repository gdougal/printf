/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <dougal@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 23:38:37 by gdougal           #+#    #+#             */
/*   Updated: 2020/07/23 23:34:16 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "ft_proc.h"

static void	ft_wthout_perc(const char **str, int *ret_res)
{
	while (**str && **str != '%')
	{
		write(1, *str, 1);
		(*ret_res)++;
		(*str)++;
	}
}

int			ft_printf(const char *str, ...)
{
	int				ret_res;
	va_list			argptr;
	t_print_struct	*res_pars;

	ret_res = 0;
	va_start(argptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (!(res_pars = ft_parser(&argptr, ++str)))
			{
				va_end(argptr);
				return (-1);
			}
			str += res_pars->delta;
			ret_res += ft_post_parse(res_pars, &argptr);
		}
		else
			ft_wthout_perc(&str, &ret_res);
	}
	va_end(argptr);
	return (ret_res);
}
