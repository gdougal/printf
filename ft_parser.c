/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <dougal@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 22:59:21 by gdougal           #+#    #+#             */
/*   Updated: 2020/07/23 23:34:41 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"

static int		parse_flags(const char *str, t_print_struct *res_pars)
{
	int len;

	len = 0;
	while (*(str + len) == '0' || *(str + len) == '-')
	{
		if (*(str + len) == '0')
			res_pars->flags |= FLAG_ZERO;
		else if (*(str + len) == '-')
			res_pars->flags |= FLAG_MINUS;
		len++;
	}
	if (res_pars->flags & FLAG_MINUS && res_pars->flags & FLAG_ZERO)
		res_pars->flags &= ~FLAG_ZERO;
	return (len);
}

static int		parse_width(va_list *argptr, const char *str,
												t_print_struct *res_pars)
{
	int		len;

	len = 0;
	if (ft_isdigit(*str))
	{
		res_pars->width = ft_atoi(str);
		len = ft_nmbrlen(res_pars->width, 10);
	}
	else if (*str == '*')
	{
		res_pars->width = va_arg(*argptr, int);
		len = 1;
		if (res_pars->width < 0)
		{
			res_pars->flags |= FLAG_MINUS;
			if (res_pars->flags & FLAG_MINUS && res_pars->flags & FLAG_ZERO)
				res_pars->flags &= ~FLAG_ZERO;
			res_pars->width *= -1;
		}
	}
	return (len);
}

static int		parse_precision(va_list *argptr, const char *str,
												t_print_struct *res_pars)
{
	int		len;

	len = 0;
	if (*str == '.')
	{
		res_pars->precision = 0;
		str++;
		if (ft_isdigit(*str))
		{
			while (*(str + len) == '0')
				len++;
			if (ft_isdigit(*(str + len)))
			{
				res_pars->precision = ft_atoi(str);
				len += ft_nmbrlen(res_pars->precision, 10);
			}
		}
		else if (*str == '*')
		{
			res_pars->precision = va_arg(*argptr, int);
			len += 1;
		}
		len += 1;
	}
	return (len);
}

static int		parse_type(const char *str, t_print_struct *res_pars)
{
	char	*sample;

	sample = "cspdiuxX%";
	while (*sample)
	{
		if (*str == *sample)
		{
			res_pars->type = *str;
			return (1);
		}
		sample++;
	}
	return (0);
}

t_print_struct	*ft_parser(va_list *argptr, const char *str)
{
	t_print_struct	*res_pars;
	const char		*start;

	start = str;
	if ((res_pars = malloc(sizeof(t_print_struct))))
	{
		res_pars->flags = 0;
		res_pars->width = 0;
		res_pars->precision = -1;
		res_pars->type = 0;
		str += parse_flags(str, res_pars);
		str += parse_width(argptr, str, res_pars);
		str += parse_precision(argptr, str, res_pars);
		str += parse_type(str, res_pars);
		res_pars->delta = str - start;
		if (!(res_pars->type))
		{
			free(res_pars);
			res_pars = NULL;
		}
	}
	return (res_pars);
}
