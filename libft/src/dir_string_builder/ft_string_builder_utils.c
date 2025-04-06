/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_builder_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:20:09 by alde-abre         #+#    #+#             */
/*   Updated: 2025/03/07 18:43:15 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string_builder.h"
#include "../includes/libft.h"

/**
 * @return A pointer to a sb (string builder) ptr with the given string added.
 */
t_sbuild	*ft_sbnew(char *str)
{
	t_sbuild	*sb;
	int			i;

	i = -1;
	sb = ft_calloc(1, sizeof(t_sbuild));
	if (!sb)
		return (NULL);
	while (str[++i] && i < SB_SIZE - 1)
		sb->str[i] = str[i];
	sb->id = i;
	sb->next = NULL;
	return (sb);
}

/**
 * @brief Free the memory of the given sb (string builder) container
 * and all the other linked containers.
 */
void	ft_sbclear(t_sbuild **container)
{
	t_sbuild	*temp;

	while (*container)
	{
		temp = (*container)->next;
		free(*container);
		*container = temp;
	}
}

/**
 * @return A pointer directing to the last string of the given
 * sb container (string builder).
 */
t_sbuild	*ft_sblast(t_sbuild *container)
{
	t_sbuild	*temp;

	if (!container)
		return (container);
	temp = container;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

/**
 * @return The lenght of the total amount of char
 * in the given sb (string builder).
 */
int	ft_sblen(t_sbuild *container)
{
	t_sbuild	*temp;
	int			count;

	count = 0;
	temp = container;
	while (temp->next)
	{
		count += temp->id;
		temp = temp->next;
	}
	return (temp->id + count);
}
