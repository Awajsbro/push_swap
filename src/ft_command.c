/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:06:20 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/02 12:39:14 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_exec_cmd(char *s, int i, t_ps *ps)
{
	if (ft_strnequ(&s[i], "rra\n", 4))
		ft_revers_roll(ps, 'a');
	else if (ft_strnequ(&s[i], "rrb\n", 4))
		ft_revers_roll(ps, 'b');
	else if (ft_strnequ(&s[i], "rrr\n", 4))
		ft_revers_roll(ps, 'r');
	else if (ft_strnequ(&s[i], "sa\n", 3))
		ft_swap(ps, 'a');
	else if (ft_strnequ(&s[i], "sb\n", 3))
		ft_swap(ps, 'b');
	else if (ft_strnequ(&s[i], "ss\n", 3))
		ft_swap(ps, 's');
	else if (ft_strnequ(&s[i], "pa\n", 3))
		ft_push(ps, 'a');
	else if (ft_strnequ(&s[i], "pb\n", 3))
		ft_push(ps, 'b');
	else if (ft_strnequ(&s[i], "ra\n", 3))
		ft_roll(ps, 'a');
	else if (ft_strnequ(&s[i], "rb\n", 3))
		ft_roll(ps, 'b');
	else if (ft_strnequ(&s[i], "rr\n", 3))
		ft_roll(ps, 'r');
}

static char	ft_check_cmd(char *s, t_ps *ps)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		ft_exec_cmd(s, i, ps);
		if (ft_strnequ(&s[i], "rra\n", 4) || ft_strnequ(&s[i], "rrb\n", 4)
			|| ft_strnequ(&s[i], "rrr\n", 4))
			i = i + 4;
		else if (ft_strnequ(&s[i], "sa\n", 3) || ft_strnequ(&s[i], "sb\n", 3)
			|| ft_strnequ(&s[i], "ss\n", 3) || ft_strnequ(&s[i], "pa\n", 3)
				|| ft_strnequ(&s[i], "pb\n", 3) || ft_strnequ(&s[i], "ra\n", 3)
					|| ft_strnequ(&s[i], "rb\n", 3)
						|| ft_strnequ(&s[i], "rr\n", 3))
			i = i + 3;
		else if (s[i] == '\n')
			i = i + 1;
		else
		{
			ft_strncpy(s, &s[i], ft_strclen(&s[i], '\n'));
			return (0);
		}
	}
	return (1);
}

void		ft_get_cmd(t_ps *ps)
{
	char	*tmp;
	char	*cm;

	cm = ft_strnew(0);
	tmp = ft_strnew(31);
	while (read(ps->fdr, tmp, 30) > 0)
	{
		cm = ft_joinfree(cm, tmp);
		tmp = ft_strnew(31);
	}
	free(tmp);
	tmp = cm;
	if (ft_check_cmd(cm, ps) == 0)
	{
		ft_error_cm(cm, ps);
		free(tmp);
		ft_dellst(LPA, LPB);
		exit(EXIT_FAILURE);
	}
}
