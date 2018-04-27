/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 13:45:08 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/27 17:51:25 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_altern_push_decroi(t_ps *ps, t_list *tmp, int size)
{
	while (ps->lpa->size < size || tmp->size < size
		|| ps->lpa->next->size < size || tmp->prev->size < size)
	{
		if (ps->lpa->next->size > ps->lpa->size && ps->lpa->next->size < size)
			ft_swap(ps, 'a');
		if (tmp->prev->size > tmp->size && tmp->prev->size > ps->lpa->size
			&& tmp->prev->size < size)
		{
			ft_revers_roll(ps, 'a');
			ft_revers_roll(ps, 'a');
			ft_push(ps, 'b');
			ft_roll(ps, 'a');
		}
		else
		{
			if (ps->lpa->size < tmp->size && tmp->size < size)
				ft_revers_roll(ps, 'a');
			ft_push(ps, 'b');
		}
		size = ps->lpb->size;
		if (ps->lpa->next == NULL)
			break ;
	}
	if (ps->lpa->size < size)
		ft_push(ps, 'b');
}

void	ft_altern_push_croi(t_ps *ps, t_list *tmp, int size)
{
	while (ps->lpa->size > size || tmp->size > size
		|| ps->lpa->next->size > size || tmp->prev->size > size)
	{
		if (ps->lpa->next->size < ps->lpa->size && ps->lpa->next->size > size)
			ft_swap(ps, 'a');
		if (tmp->prev->size < tmp->size && tmp->prev->size < ps->lpa->size
			&& tmp->prev->size > size)
		{
			ft_revers_roll(ps, 'a');
			ft_revers_roll(ps, 'a');
			ft_push(ps, 'b');
			ft_roll(ps, 'a');
		}
		else
		{
			if (ps->lpa->size > tmp->size && tmp->size > size)
				ft_revers_roll(ps, 'a');
			ft_push(ps, 'b');
		}
		size = ps->lpb->size;
		if (ps->lpa->next == NULL)
			break ;
	}
	if (ps->lpa->size > size)
		ft_push(ps, 'b');
}

void	ft_sequnece_push_decroi(t_ps *ps)
{
	t_list	*tmp;

	tmp = ft_lstend(ps->lpa);
	while (ft_order_lst(ps->lpa) == 0 && (ps->lpa->size > ps->lpa->next->size
		|| tmp->size > ps->lpa->next->size
			|| tmp->prev->size > ps->lpa->next->size))
	{
		if (ps->lpa->size < ps->lpa->next->size)
			ft_swap(ps, 'b');
		while (tmp->size > ps->lpa->size || tmp->prev->size > ps->lpa->size)
		{
			ft_revers_roll(ps, 'a');
			if (tmp->size > ps->lpa->size)
			{
				ft_revers_roll(ps, 'a');
				ft_swap(ps, 'a');
				ft_roll(ps, 'a');
			}
		}
	 	ft_push(ps, 'b');
		if (tmp->prev == NULL)
			break ;
	}
}

void	ft_sequnece_push_croi(t_ps *ps)
{
	t_list	*tmp;

	tmp = ft_lstend(ps->lpa);
	while (ft_order_lst(ps->lpa) == 0 && (ps->lpa->size < ps->lpa->next->size
		|| tmp->size < ps->lpa->next->size
			|| tmp->prev->size < ps->lpa->next->size))
	{
		if (ps->lpa->size > ps->lpa->next->size)
			ft_swap(ps, 'b');
		while (tmp->size < ps->lpa->size || tmp->prev->size < ps->lpa->size)
		{
			ft_revers_roll(ps, 'a');
			if (tmp->size < ps->lpa->size)
			{
				ft_revers_roll(ps, 'a');
				ft_swap(ps, 'a');
				ft_roll(ps, 'a');
			}
		}
	 	ft_push(ps, 'b');
		if (tmp->prev == NULL)
			break ;
	}
}

static void	ft_push_on_b(t_ps *ps)
{
	int		i;
	int		j;

	while (ft_order_lst(ps->lpa) == 0)
	{
ft_putendl("c'est pas ici que je segfault");
		i = ft_begin_up(ft_lstcpy(ps->lpa));
ft_printf(" i == %D\n", i);
		j = ft_begin_down(ft_lstcpy(ps->lpa));
ft_printf(" j == %D\n", j);
		if ((i / 10) > (j / 10))
		{
			if ((i % 10) == 1)
				ft_altern_push_croi(ps, ft_lstend(ps->lpa), 0);
			else
				ft_sequnece_push_croi(ps);
		}
		else
		{
			if ((j % 10) == 2)
				ft_altern_push_decroi(ps, ft_lstend(ps->lpa), 2147483647);
			else
				ft_sequnece_push_decroi(ps);
		}
	}
}

void	ft_solve_select(t_ps *ps)
{
	ps->lpa = ft_lststart(ps->lpa);
	if (ft_lstlen(ps->lpa) < 6)
		ft_under6(ps);
	else
		while (ft_check_result(ps) == 0)
		{
			ft_push_on_b(ps);
			break ;
		}
}
