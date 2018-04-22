/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 11:29:59 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/22 18:29:23 by awajsbro         ###   ########.fr       */
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

int		ft_longestup(t_list *lst, t_list *tmp, int s)
{
	while (s != -1)
	{
		s = -1;
		while (lst->next != NULL)
		{
			if (lst->size < lst->next->size)
				lst = lst->next;
			else
				break;
		}
		if (lst->prev != NULL && lst->next != NULL)
			if (lst->prev->size < lst->next->size)
				ft_swap_int((int*)&(lst->size), (int*)&(lst->next->size));
		while (tmp->prev != NULL)
		{
			if (tmp->size > tmp->size)
				tmp = tmp->prev;
			else
				break;
		}
		if (tmp->next != NULL && tmp->prev != NULL)
			if (tmp->next->size < tmp->prev->size)
				ft_swap_int((int*)&(tmp->size), (int*)&(tmp->prev->size));
	}
	return (ft_sequence_up(lst));
}
