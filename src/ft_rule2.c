/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 11:52:13 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/30 15:41:33 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	ft_jten_merde(t_list *lst)
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

char		roll(t_ps *ps, char m, t_list **start, t_list **end)
{
	ft_roll(ps, m);
	*start = ft_lststart(*start);
	*end = ft_lstend(*end);
	return (ft_jten_merde(LPA));
}

char		revers_roll(t_ps *ps, char m, t_list **start, t_list **end)
{
	ft_revers_roll(ps, m);
	*start = ft_lststart(*start);
	*end = ft_lstend(*end);
	return (ft_jten_merde(LPA));
}

char		swap(t_ps *ps, char m, t_list **start, t_list **end)
{
	ft_swap(ps, m);
	*start = ft_lststart(*start);
	*end = ft_lstend(*end);
	return (ft_jten_merde(LPA));
}

char		push(t_ps *ps, char m, t_list **start, t_list **end)
{
	ft_push(ps, m);
	*start = ft_lststart(*start);
	*end = ft_lstend(*end);
	return (ft_jten_merde(LPA));
}
