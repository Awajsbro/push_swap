/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 11:29:59 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/12 14:30:10 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

char	ft_order_lst(t_list *lst)
{
	t_list	*tmp;

	if (lst == NULL)
		return (1);
	tmp = ft_lststart(lst);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (tmp->size < tmp->prev->size)
			return (0);
	}
	return (1);
}

char	ft_check_result(t_ps *ps)
{
	int	i;

	LPA = ft_lststart(LPA);
	LPB = ft_lststart(LPB);
	if (LPB != NULL)
		return (0);
	i = 0;
	while (i < ps->len - 1)
	{
		i++;
		if (i != LPA->size)
		{
			LPA = ft_lststart(LPA);
			LPB = ft_lststart(LPB);
			return (0);
		}
		LPA = LPA->next;
	}
	ft_lstdel(&LPA);
	return (1);
}
