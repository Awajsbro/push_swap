/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 13:45:08 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/30 18:22:13 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	ft_find_min_low(t_list *lst, int size)
{
	t_list	*tmp;
	int		tab[4];
	int		lim;

	lim = ft_lstlen(lst) > 15 ? 10 : ft_lstlen(lst);
	tmp = ft_lstend(lst);
	tab[0] = 1;
	tab[1] = -2;
	tab[2] = lst->size < size ? 1 : 43;
	tab[3] = lst->size < size ? lst->size : 0;
	lst = lst->next;
	while (lim--)
	{
		tab[3] = tmp->size > tab[3] && tmp->size < size ? tmp->size : tab[3];
		tab[3] = lst->size > tab[3] && lst->size < size ? lst->size : tab[3];
		tab[2] = tab[3] == tmp->size ? tab[1] : tab[2];
		tab[2] = tab[3] == lst->size ? tab[0] : tab[2];
		if (lst->next == NULL)
			break ;
		lst = lst->next;
		tmp = tmp->prev;
		tab[0]++;
		tab[1]--;
	}
	return (tab[2] - 1);
}

void	ft_altern_push_decroi(t_ps *ps, t_list *tmp, int size)
{
	int		i;
	while (ft_order_lst(LPA) == 0 && ((i = ft_find_min_low(LPA, size)) != 42))
	{
		if (i < 0)
			while (i++)


	}
	if (LPA->size < size && ft_order_lst(LPA) == 0)
		push(ps, 'b', &LPA, &tmp);
}

void	ft_altern_push_croi(t_ps *ps, t_list *tmp, int size)
{
	while (ft_order_lst(LPA) == 0 && (LPA->size > size || tmp->size > size
		|| LPA->next->size > size || tmp->prev->size > size))
	{
		if (tmp->prev->size < tmp->size && tmp->prev->size < LPA->size
			&& tmp->prev->size > size)
		{
			if (revers_roll(ps, 'a', &LPA, &tmp) == 0
				&& revers_roll(ps, 'a', &LPA, &tmp) == 0
					&& push(ps, 'b', &LPA, &tmp) == 0
						&& roll(ps, 'a', &LPA, &tmp) == 0)
				;
			else
				return ;
		}
		else
		{
			if (LPA->next->size < LPA->size && LPA->next->size > size)
			{
				if (swap(ps, 'a', &LPA, &tmp) == 1)
					return ;
			}
			else if (LPA->size > tmp->size && tmp->size > size
				&& revers_roll(ps, 'a', &LPA, &tmp) == 1)
				return ;
			push(ps, 'b', &LPA, &tmp);
		}
		size = LPB->size;
		if (LPA->next == NULL)
			break ;
	}
	if (LPA->size > size && ft_order_lst(LPA) == 0)
		push(ps, 'b', &LPA, &tmp);
}

void	ft_sequnece_push_decroi(t_ps *ps)
{
	t_list	*tmp;

	tmp = ft_lstend(LPA);
	while (ft_order_lst(LPA) == 0 && (LPA->size > LPA->next->size
		|| tmp->size > LPA->next->size
			|| tmp->prev->size > LPA->next->size))
	{
		if (LPA->size < LPA->next->size && swap(ps, 'b', &LPA, &tmp) == 1)
			return ;
		while (tmp->size > LPA->size || tmp->prev->size > LPA->size)
		{
			if (revers_roll(ps, 'a', &LPA, &tmp) == 1)
				return ;
			if (tmp->size > LPA->size && ft_order_lst(ps->lpa) == 0)
			{
				if (revers_roll(ps, 'a', &LPA, &tmp) == 0
					&& swap(ps, 'a', &LPA, &tmp) == 0
						&& roll(ps, 'a', &LPA, &tmp) == 0)
					;
				else
					return ;
			}
		}
	 	push(ps, 'b', &LPA, &tmp);
		if (tmp->prev == NULL)
			return ;
	}
}

void	ft_sequnece_push_croi(t_ps *ps)
{
	t_list	*tmp;

	tmp = ft_lstend(LPA);
	while (ft_order_lst(LPA) == 0 && (LPA->size < LPA->next->size
		|| tmp->size < LPA->next->size
			|| tmp->prev->size < LPA->next->size))
	{
		if (LPA->size > LPA->next->size && swap(ps, 'b', &LPA, &tmp) == 1)
			return ;
		while (tmp->size < LPA->size || tmp->prev->size < LPA->size)
		{
			if (revers_roll(ps, 'a', &LPA, &tmp) == 1)
				return ;
			if (tmp->size < LPA->size && ft_order_lst(ps->lpa) == 0)
			{
				if (revers_roll(ps, 'a', &LPA, &tmp) == 0
					&& swap(ps, 'a', &LPA, &tmp) == 0
						&& roll(ps, 'a', &LPA, &tmp) == 0)
					;
				else
					return ;
			}
		}
	 	push(ps, 'b', &LPA, &tmp);
		if (tmp->prev == NULL)
			return ;
	}
}

static void	ft_push_on_b(t_ps *ps)
{
	int		i;
	int		j;

	while (ft_order_lst(LPA) == 0)
	{
		i = ft_begin_up(ft_lstcpy(LPA));
		j = ft_begin_down(ft_lstcpy(LPA));
ft_printf("%D i %D j\n", i, j);
		if ((i / 10) > ((j / 10) * 2) / 3)
		{
			if ((i % 10) == 1)
			{
				ft_putendl("altern croi");
				ft_altern_push_croi(ps, ft_lstend(LPA), 0);
			}
			else
				{ft_putendl("sequen croi");
				ft_sequnece_push_croi(ps);}
		}
		else
		{
			if ((j % 10) == 2)
				{ft_putendl("altern decroi");
				ft_altern_push_decroi(ps, ft_lstend(LPA), 2147483647);}
			else
				{ft_putendl("sequence decroi");
				ft_sequnece_push_decroi(ps);}
		}
	}
}

void	ft_solve_select(t_ps *ps)
{
	LPA = ft_lststart(LPA);
	if (ft_lstlen(LPA) < 6)
		ft_under6(ps);
	else
		while (ft_check_result(ps) == 0)
		{
			ft_push_on_b(ps);
			break ;
		}
}
