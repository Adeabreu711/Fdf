/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfnullcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:10:04 by alde-abr          #+#    #+#             */
/*   Updated: 2025/02/07 12:05:55 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_checkerrorstr(t_conv *conv, char *error)
{
	int	prec;

	prec = conv->precision;
	if (!ft_strncmp(error, "(null)", 6) && prec >= 0 && prec < 6)
		return (0);
	return (1);
}

int	ft_pfnullcheck(t_sbuild *out, t_conv *conv, t_uint64 nb, char *s)
{
	int	fill_size;
	int	err_len;
	int	strnull;

	fill_size = 0;
	strnull = ft_checkerrorstr(conv, s);
	err_len = ft_strlen(s);
	if (nb && ((!conv->precision) || err_len > 0))
	{
		if (conv->witdh > err_len * strnull)
			fill_size = conv->witdh - err_len + (!strnull * 6);
		err_len *= strnull;
		if (conv->flags & ALIGN_L)
		{
			ft_sb_addstr(&out, s, err_len);
			while (fill_size-- > 0)
				ft_sb_addstr(&out, " ", 1);
			return (0);
		}
		while (fill_size-- > 0)
			ft_sb_addstr(&out, " ", 1);
		ft_sb_addstr(&out, s, err_len);
		return (0);
	}
	return (1);
}
