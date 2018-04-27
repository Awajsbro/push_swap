/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 11:29:59 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/27 17:45:20 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	ft_order_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = ft_lststart(lst);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (tmp->size < tmp->prev->size)
			return (0);
	}
	return (1);
}

char	ft_reverse_order_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = ft_lststart(lst);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (tmp->size > tmp->prev->size)
			return (0);
	}
	return (1);
}

char	ft_max(t_list *lst)
{
	t_list	*tmp;

	tmp = ft_lststart(lst);
	while (tmp != NULL)
	{
		if (tmp->size > lst->size)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

char	ft_min(t_list *lst)
{
	t_list	*tmp;

	tmp = ft_lststart(lst);
	while (tmp != NULL)
	{
		if (tmp->size < lst->size)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		ft_find_min_roll(t_list *lst, int val)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (lst->size != val && tmp->size != val)
	{
		i++;
		if (lst->next != NULL)
			lst = lst->next;
		else
			lst = ft_lststart(tmp);
		if (tmp->prev != NULL)
			tmp = tmp->prev;
		else
			tmp = ft_lstend(lst);
	}
	if (tmp->size == val)
		i = -i;
	return (i);
}
