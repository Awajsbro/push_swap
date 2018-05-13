/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reduce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:51:26 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/13 15:24:03 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_print_cmd_color(char *s, t_ps *ps)
{
	if (*s == M_SA || *s == M_BA)
		write(ps->fdw, "\033[32;1msa\n\033[0m", 14);
	else if (*s == M_SB || *s == M_BB)
		write(ps->fdw, "\033[32;1msb\n\033[0m", 14);
	else if (*s == M_SS)
		write(ps->fdw, "\033[32;1mss\n\033[0m", 14);
	else if (*s == M_PA)
		write(ps->fdw, "\033[32;1mpa\n\033[0m", 14);
	else if (*s == M_PB)
		write(ps->fdw, "\033[32;1mpb\n\033[0m", 14);
	else if (*s == M_RA)
		write(ps->fdw, "\033[32;1mra\n\033[0m", 14);
	else if (*s == M_RB)
		write(ps->fdw, "\033[32;1mrb\n\033[0m", 14);
	else if (*s == M_RR)
		write(ps->fdw, "\033[32;1mrr\n\033[0m", 14);
	else if (*s == M_RRA)
		write(ps->fdw, "\033[32;1mrra\n\033[0m", 15);
	else if (*s == M_RRB)
		write(ps->fdw, "\033[32;1mrrb\n\033[0m", 15);
	else if (*s == M_RRR)
		write(ps->fdw, "\033[32;1mrrr\n\033[0m", 15);
}

static void	ft_print_cmd(char *s, t_ps *ps)
{
	if (*s == M_SA || *s == M_BA)
		write(ps->fdw, "sa\n", 3);
	else if (*s == M_SB || *s == M_BB)
		write(ps->fdw, "sb\n", 3);
	else if (*s == M_SS)
		write(ps->fdw, "ss\n", 3);
	else if (*s == M_PA)
		write(ps->fdw, "pa\n", 3);
	else if (*s == M_PB)
		write(ps->fdw, "pb\n", 3);
	else if (*s == M_RA)
		write(ps->fdw, "ra\n", 3);
	else if (*s == M_RB)
		write(ps->fdw, "rb\n", 3);
	else if (*s == M_RR)
		write(ps->fdw, "rr\n", 3);
	else if (*s == M_RRA)
		write(ps->fdw, "rra\n", 4);
	else if (*s == M_RRB)
		write(ps->fdw, "rrb\n", 4);
	else if (*s == M_RRR)
		write(ps->fdw, "rrr\n", 4);
}

static char	*ft_remove_void(char *s)
{
	char		*n;
	int			i;
	int			j;

	i = 0;
	j = 1;
	while (s[++i] != 0)
		if (s[i] != M_VID)
			j++;
	if (!(n = (char*)malloc(sizeof(*n) * j + 1)))
		exit(EXIT_FAILURE);
	n[j + 1] = 0;
	n[0] = M_VID;
	i = 0;
	j = 1;
	while (s[i++] != 0)
	{
		if (s[i] != M_VID)
		{
			n[j] = s[i];
			j++;
		}
	}
	free(s);
	return (n);
}

void		ft_reduce(t_ps *ps)
{
	int	i;

	i = -1;
	while (i != (int)ft_strlen(ps->cmd))
	{
		i = (int)ft_strlen(ps->cmd);
		ft_reduce_by_a(ps->cmd, 0, 0);
		ft_reduce_by_b(ps->cmd, 0, 0);
		ft_rm_comeback_a_first(ps->cmd, 0, 0);
		ft_rm_comeback_b_first(ps->cmd, 0, 0);
		ps->cmd = ft_remove_void(ps->cmd);
	}
	i = -1;
	while (ps->cmd[++i] != 0)
	{
		if (ps->cmd[i + 1] == 0 && (ps->opt & M_COLOR) == M_COLOR)
			ft_print_cmd_color(&ps->cmd[i], ps);
		else
			ft_print_cmd(&ps->cmd[i], ps);
	}
	free(ps->cmd);
}
