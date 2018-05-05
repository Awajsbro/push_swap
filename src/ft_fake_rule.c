/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fake_rule.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:34:04 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/01 16:02:04 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char		fake_roll(t_list **lsa, t_list **end)
{
	*lsa = ft_lststart(*lsa);
	ft_lstaddend(lsa, ft_lstremove(lsa));
	*lsa = ft_lststart(*lsa);
	if (end != NULL)
		*end = ft_lstend(*end);
	return (ft_order_lst(*lsa));
}

char		fake_revers_roll(t_list **lsa, t_list **end)
{
	*lsa = ft_lstend(*lsa);
	ft_lstaddstart(lsa, ft_lstremove(lsa));
	*lsa = ft_lststart(*lsa);
	if (end != NULL)
		*end = ft_lstend(*end);
	return (ft_order_lst(*lsa));
}

char		fake_swap(t_list **lsa, t_list **end)
{
	*lsa = ft_lststart(*lsa);
	*lsa = (*lsa)->next;
	ft_lstaddstart(lsa, ft_lstremove(lsa));
	*lsa = ft_lststart(*lsa);
	if (end != NULL)
		*end = ft_lstend(*end);
	return (ft_order_lst(*lsa));
}

char		fake_push(t_list **lsa, t_list **lsb, t_list **end)
{
	*lsa = ft_lststart(*lsa);
	ft_lstaddstart(lsb, ft_lstremove(lsa));
	*lsa = ft_lststart(*lsa);
	if (end != NULL)
		*end = ft_lstend(*end);
	return (ft_order_lst(*lsa));
}
