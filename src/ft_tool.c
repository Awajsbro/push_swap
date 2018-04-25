/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 11:29:59 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/25 18:44:16 by awajsbro         ###   ########.fr       */
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

static int	ft_alternate_down(t_list *lst, t_list *tmp)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (lst->next != NULL)
	{
		if (tmp->size < size || lst->size < size)
		{
			i++;
			if (lst->size < tmp->size)
			{
				size = tmp->size;
				ft_lstdel(&tmp);
			}
			else
			{
				size = lst->size;
				ft_lstdel(&lst);
			}
		}
	}
	if (tmp->size < size || lst->size < size)
		i++;
	return (i);
}

static int	ft_alternate_up(t_list *lst, t_list *tmp)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (lst->next != NULL)
	{
		if (tmp->size > size || lst->size > size)
		{
			i++;
			if (lst->size > tmp->size)
			{
				size = tmp->size;
				ft_lstdel(&tmp);
			}
			else
			{
				size = lst->size;
				ft_lstdel(&lst);
			}
		}
	}
	if (tmp->size > size || lst->size > size)
		i++;
	return (i);
}

int		ft_begin_down(t_list *lst)
{
	int		s;
	int		i;

	s = 0;
	while (s != -1)
	{
		s = -1;
		while (lst->next != NULL)
		{
			if (lst->size > lst->next->size)
				lst = lst->next;
			else
				break;
		}
		if (lst->prev != NULL && lst->next != NULL)
			if (lst->prev->size > lst->next->size)
			{
				s++;
				ft_swap_int((int*)&(lst->size), (int*)&(lst->next->size));
			}
	}
	i = ft_end_up(ft_lstend(ft_lstcpy(lst)), -1);
	s = ft_end_down(ft_lstend(lst), -1);
	return (s > i + 1 ? s : i);
}

int		ft_begin_up(t_list *lst)
{
	int		s;
	int		i;

	s = 0;
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
			{
				s++;
				ft_swap_int((int*)&(lst->size), (int*)&(lst->next->size));
			}
	}
	s = ft_end_up(ft_lstend(ft_lstcpy(lst)), 1);
	i = ft_end_down(ft_lstend(lst), 1);
	return (s > i + 1 ? s : i);
}

int		ft_end_up(t_list *lst, char m)
{
	int		i;
	int		s;

	while (s != -1)
	{
		s = -1;
		while (lst->prev != NULL)
		{
			if (lst->size > lst->prev->size)
				lst = lst->prev;
			else
				break;
			if (lst->prev != NULL && lst->next != NULL)
				if (lst->prev->size > lst->next)
				{
					s++;
					ft_swap_int((int*)&(lst->size), (int*)&(lst->prev->size));
				}
		}
	}
	if (m == 1)
		return (ft_sequence_up(ft_lststart(lst), ft_lstend(lst)));
	return (ft_alternate_down(ft_lststart(lst), ft_lstend(lst)));
}

int		ft_end_down(t_list *lst, char m)
{
	int		i;
	int		s;

	while (s != -1)
	{
		s = -1;
		while (lst->prev != NULL)
		{
			if (lst->size < lst->prev->size)
				lst = lst->prev;
			else
				break;
			if (lst->prev != NULL && lst->next != NULL)
				if (lst->prev->size < lst->next)
				{
					s++;
					ft_swap_int((int*)&(lst->size), (int*)&(lst->prev->size));
				}
		}
	}
	if (m == -1)
		return (ft_sequence_down(ft_lststart(lst), ft_lstend(lst)));
	return (ft_alternate_up(ft_lststart(lst), ft_lstend(lst)));
