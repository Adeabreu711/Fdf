/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfbuildchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:07:19 by alde-abre         #+#    #+#             */
/*   Updated: 2025/02/07 12:05:47 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_checknullchar(t_sbuild *out, t_conv *conv, char c)
{
	int	fill_size;

	if (c)
		return (1);
	fill_size = 0;
	if (conv->witdh > 1)
		fill_size = conv->witdh - 1;
	if (conv->flags & ALIGN_L)
	{
		ft_sb_addstr(&out, "\0", 1);
		while (fill_size-- > 0)
			ft_sb_addstr(&out, " ", 1);
		return (0);
	}
	while (fill_size-- > 0)
		ft_sb_addstr(&out, " ", 1);
	ft_sb_addstr(&out, "\0", 1);
	return (0);
}

int	ft_pfbuildchar(t_sbuild *out, t_conv *conv, char c)
{
	char	*temp;
	int		size;

	if (!ft_checknullchar(out, conv, c))
		return (conv->lenght);
	size = !!c;
	if (conv->witdh > size)
		size += conv->witdh - size;
	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		return (conv->lenght);
	if (conv->witdh)
		temp = ft_memset(temp, ' ', size);
	if (!!(conv->flags & ALIGN_L) && c)
		ft_memset(temp, (int)c, 1);
	else if (c)
		ft_memset(temp + (size - 1), (int)c, 1);
	ft_sb_addstr(&out, temp, size);
	free(temp);
	return (conv->lenght);
}
