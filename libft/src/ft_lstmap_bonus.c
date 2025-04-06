/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:21:21 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/22 12:21:22 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Apply a given function to all the elements of a copy of
 * the given list.
 * @param {t_list} "lst" pointer to the sart of a linked sructure.
 * @param {void *} (*f)(void *) pointer to function apply to all
 * elements of the given list.
 * @param {void} (*del)(void *) pointer to function that erase an element.
 * @return A copy of the given list "lst" with the function "*f" apllied
 * to each elements.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_f;
	t_list	*next;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	lst_f = NULL;
	while (lst)
	{
		temp = f(lst->content);
		next = ft_lstnew(temp);
		if (!next)
		{
			del(temp);
			ft_lstclear(&lst_f, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_f, next);
		lst = lst->next;
	}
	return (lst_f);
}
