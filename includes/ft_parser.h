/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <dougal@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:01:39 by gdougal           #+#    #+#             */
/*   Updated: 2020/07/27 12:01:41 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# define FLAG_MINUS (0b00000001u)
# define FLAG_ZERO	(0b00000010u)

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_print_struct
{
	unsigned char	flags;
	int				width;
	int				precision;
	char			type;
	size_t			delta;
}					t_print_struct;

t_print_struct		*ft_parser(va_list *argptr, const char *str);

#endif
