/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 13:45:08 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/12 16:15:40 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	ft_find_min_low(t_list *lst, int size)
{
	t_list	*tmp;
	long	tab[4];

	tmp = ft_lstend(lst);
	tab[0] = 1;
	tab[1] = -1;
	tab[2] = lst->size == size - 1 ? 0 : 3000000000;
	tab[3] = lst->size == size - 2 ? 0 : 3000000000;
	lst = lst->next;
	while (tab[2] == 3000000000)
	{
		tab[3] = tmp->size == size - 2 ? tab[1] : tab[3];
		tab[3] = lst->size == size - 2 ? tab[0] : tab[3];
		tab[2] = tmp->size == size - 1 ? tab[1] : tab[2];
		tab[2] = lst->size == size - 1 ? tab[0] : tab[2];
		if (lst->next == tmp || tmp == lst || tab[3] == size - 1)
			break ;
		lst = lst->next;
		tmp = tmp->prev;
		tab[0]++;
		tab[1]--;
	}
	if (tab[3] == 0)
		return (0);
	return ((tab[2] * tab[3]) > 0 && tab[3] != 3000000000 ? tab[3] : tab[2]);
}

static void	ft_repush_on_a(t_ps *ps)
{
	long	i;
	int		size;

	size = ps->len + 1;
	while (LPB != NULL
		&& (i = ft_find_min_low(LPB, size)) != 3000000000)
	{
		if (i < 0)
			while (i++)
			{
				if (revers_roll(ps, 'b', &LPB, NULL) == 1)
					return ;
			}
		else if (i > 0)
			while (i--)
				if (roll(ps, 'b', &LPB, NULL) == 1)
					return ;
		push(ps, 'a', &LPB, NULL);
		if (LPA->next != NULL && LPA->size > LPA->next->size)
			swap(ps, 'a', &LPA, NULL);
		if (LPA->size == size - 1
			|| (LPA->next != NULL && LPA->next->size == size - 1))
			size = LPA->size;
	}
}

static void	ft_push_on_b(t_ps *ps)
{
	int		max;
	int		mid;
	int		len;

	while (LPA != NULL)
	{
		len = ft_lstlen(LPA);
		mid = LPB == NULL ? 0 : max;
		max = len / 6 > 25 ? mid + len / 6 : mid + 25;
		max = max > ps->len ? ps->len : max;
		mid = mid + ((max - mid) / 2);
		while ((int)ft_lstlen(LPA) > ps->len - max)
		{
			if (LPA->size <= max)
			{
				ft_push(ps, 'b');
				if (LPB->size > mid)
					ft_roll(ps, 'b');
			}
			else
				roll(ps, 'a', &LPA, NULL);
		}
	}
}

void		ft_solve_select(t_ps *ps)
{
	LPA = ft_lststart(LPA);
	if (ft_lstlen(LPA) < 6)
		ft_under6(ps);
	else
	{
		ft_push_on_b(ps);
		ft_repush_on_a(ps);
	}
}
