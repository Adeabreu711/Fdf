/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:49:49 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/21 18:49:50 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @return The size of the given linked list "lst".
 */
int	ft_lstsize(t_list *lst)
{
	size_t	count;
	t_list	*temp;

	count = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

// int	main()
// {
// 	int	i = 0;
// 	t_list	*lst = malloc(sizeof(t_list));

// 	t_list	*t = lst;
// 	while (i < 5)
// 	{
// 		printf("ADD\n");
// 		t->next = malloc(sizeof(t_list));
// 		t = t->next;
// 		i++;
// 	}
// 	printf("%i\n", ft_lstsize(lst));
// }
