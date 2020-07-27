/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <dougal@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:02:26 by gdougal           #+#    #+#             */
/*   Updated: 2020/07/27 12:02:29 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROC_H
# define FT_PROC_H

# include "ft_parser.h"

int ft_post_parse(t_print_struct *res_pars, va_list *argptr);
int	ft_cymboll(t_print_struct *res_pars, va_list *argptr);
int	ft_percent(t_print_struct *res_pars);
int	ft_hex(t_print_struct *res_pars, va_list *argptr);
int	ft_unsigned(t_print_struct *res_pars, va_list *argptr);
int	ft_integer(t_print_struct *res_pars, va_list *argptr);
int	ft_pointer(t_print_struct *res_pars, va_list *argptr);
int	ft_string(t_print_struct *res_pars, va_list *argptr);

#endif
