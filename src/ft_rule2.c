/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 11:52:13 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/04 09:52:25 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char		roll(t_ps *ps, char m, t_list **start, t_list **end)
{
	ft_roll(ps, m);
	*start = ft_lststart(*start);
	if (end != NULL)
		*end = ft_lstend(*end);
	if (m == 'a')
		return (ft_order_lst(LPA));
	return (0);
}

char		revers_roll(t_ps *ps, char m, t_list **start, t_list **end)
{
	ft_revers_roll(ps, m);
	*start = ft_lststart(*start);
	if (end != NULL)
		*end = ft_lstend(*end);
	if (m == 'a')
		return (ft_order_lst(LPA));
	return (0);
}

char		swap(t_ps *ps, char m, t_list **start, t_list **end)
{
	ft_swap(ps, m);
	*start = ft_lststart(*start);
	if (end != NULL)
		*end = ft_lstend(*end);
	if (m == 'a')
		return (ft_order_lst(LPA));
	return (0);
}

char		push(t_ps *ps, char m, t_list **start, t_list **end)
{
	ft_push(ps, m);
	*start = ft_lststart(*start);
	if (end != NULL)
		*end = ft_lstend(*end);
	if (m == 'a')
		return (ft_order_lst(LPA));
	return (0);
}
