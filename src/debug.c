/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:06:19 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/11 14:28:46 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstdebug(t_list *lst, char *s)
{
	ft_putendl("---------------------------------------------");
	ft_putendl(s);
	if (lst == NULL)
		return ;
	lst = ft_lststart(lst);
	while (lst->next != NULL)
	{
		ft_printf("%-4s ->> %2d\n", lst->content, lst->size);
		lst = lst->next;
	}
	ft_printf("%-4s ->> %2d\n", lst->content, lst->size);
	ft_putendl("---------------------------------------------");
}
