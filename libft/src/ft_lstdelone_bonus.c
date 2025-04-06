/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:52:17 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/21 19:52:18 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Free the memory of the given list with the given function.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del)
		del(lst->content);
	free(lst);
}
