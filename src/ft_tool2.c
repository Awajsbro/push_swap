/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:01:28 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/27 17:55:14 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_sequence_up(t_list *lst, t_list *tmp)
{
	int		i;

	i = 0;
	while (tmp->prev != NULL)
	{
		i++;
		if (tmp->prev->size < tmp->size)
			tmp = tmp->prev;
		else
			break ;
	}
	while (lst->next != NULL)
	{
		i++;
		if (lst->size < lst->next->size)
			lst = lst->next;
		else
			break ;
	}
ft_putendl("je vais encore bien");
	ft_lstdel(&lst);
ft_putendl("je vais toujours bien");
	return ((i * 10) + 3);
}

static int	ft_sequence_down(t_list *lst, t_list *tmp)
{
	int		i;

	i = 0;
	while (tmp->prev != NULL)
	{
		i++;
		if (tmp->prev->size > tmp->size)
			tmp = tmp->prev;
		else
			break ;
	}
	while (lst->next != NULL)
	{
		i++;
		if (lst->size > lst->next->size)
			lst = lst->next;
		else
			break ;
	}
	ft_lstdel(&lst);
	return ((i * 10) + 4);
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
			if (lst->size < tmp->size)
			{
				size = lst->size;
				ft_lstdelone(&lst);
			}
			else
			{
				size = tmp->size;
				ft_lstdelone(&tmp);
			}
		}
		else
			break ;
	}
	if (tmp->size > size || lst->size > size)
		i++;
	ft_lstdel(&lst);
	return ((i * 10) + 1);
}

static int	ft_alternate_down(t_list *lst, t_list *tmp)
{
	int		i;
	int		size;

	i = 0;
	size = 2147483647;
	while (lst->next != NULL)
	{
		if (tmp->size < size || lst->size < size)
		{
			i++;
			if (lst->size < tmp->size)
			{
				size = tmp->size;
				ft_lstdelone(&tmp);
			}
			else
			{
				size = lst->size;
				ft_lstdelone(&lst);
			}
		}
		else
			break ;
	}
	if (tmp->size < size || lst->size < size)
		i++;
ft_putendl("la par contre je vais casser");
	ft_lstdel(&lst);
ft_putendl("voila j'ai peter");
	return ((i * 10) + 2);
}

int		ft_end_up(t_list *lst, char m)
{
	int		s;

	s = 0;
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
				if (lst->prev->size > lst->next->size)
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
	int		s;

	s = 0;
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
				if (lst->prev->size < lst->next->size)
				{
					s++;
					ft_swap_int((int*)&(lst->size), (int*)&(lst->prev->size));
				}
		}
	}
	if (m == -1)
		return (ft_sequence_down(ft_lststart(lst), ft_lstend(lst)));
	return (ft_alternate_up(ft_lststart(lst), ft_lstend(lst)));
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
	return ((s / 10) > (i / 10) + 1 ? s : i);
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
	return ((s / 10) > (i / 10) + 1 ? s : i);
}
