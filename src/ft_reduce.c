/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reduce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:51:26 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/05 14:20:05 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_print_cmd(char *s)
{
	while (*(s++) != 0)
	{
		if (*s == M_SA || *s == M_BA)
			write(1, "sa\n", 3);
		else if (*s == M_SB || *s == M_BB)
			write(1, "sb\n", 3);
		else if (*s == M_SS)
			write(1, "ss\n", 3);
		else if (*s == M_PA)
			write(1, "pa\n", 3);
		else if (*s == M_PB)
			write(1, "pb\n", 3);
		else if (*s == M_RA)
			write(1, "ra\n", 3);
		else if (*s == M_RB)
			write(1, "rb\n", 3);
		else if (*s == M_RR)
			write(1, "rr\n", 3);
		else if (*s == M_RRA)
			write(1, "rra\n", 4);
		else if (*s == M_RRB)
			write(1, "rrb\n", 4);
		else if (*s == M_RRR)
			write(1, "rrr\n", 4);
	}
}

// static void ft_rm_comeback(char *s, int i, int j)
// {
// 	while (s[++i] != 0)
// 	{
// 		if (s[i] == M_SA || s[i] == M_RA || s[i] == M_RRA || s[i] == M_BA)
// 		{
// 			j = i + 1;
// 			while (s[j] == M_SB || s[j] == M_RB || s[j] == M_RRB
// 				|| s[j] == M_BB || s[j] == M_VID)
// 				j++;
// 			if ((s[i] == M_SA && s[j] == M_SA) || (s[i] == M_RA && s[j] == M_RRA)
// 				|| (s[i] == M_RRA && s[j] == M_RA) || s[j] == M_BA)
// 				s[i] = M_VID;
// 			s[j] = s[i] == M_VID ? M_VID : s[j];
// 		}
// 		else if (s[i] == M_SB || s[i] == M_RB || s[i] == M_RRB || s[i] == M_BB)
// 		{
// 			j = i + 1;
// 			while (s[j] == M_SA || s[j] == M_RA || s[j] == M_RRA
// 				|| s[j] == M_BA || s[j] == M_VID)
// 				j++;
// 			if ((s[i] == M_SB && s[j] == M_SB) || (s[i] == M_RB && s[j] == M_RRB)
// 				|| (s[i] == M_RRB && s[j] == M_RB) || s[j] == M_BB)
// 				s[i] = M_VID;
// 			s[j] = s[i] == M_VID ? M_VID : s[j];
// 		}
// 	}
// }

// static void	ft_reduce_by_a(char *s, int i, int j)
// {
// 	while (s[++i] != 0)
// 	{
// 		if (s[i] == M_PA && s[i + 1] == M_PB)
// 		{
// 			s[i] = M_VID;
// 			s[i + 1] = M_VID;
// 		}
// 		else if (s[i] == M_SA || s[i] == M_RA || s[i] == M_RRA || s[i] == M_BA)
// 		{
// 			j = i + 1;
// 			while (s[j] == M_SA || s[j] == M_RA || s[j] == M_RRA
// 				|| s[j] == M_BA || s[j] == M_VID)
// 				j++;
// 			if ((s[j] == M_SB || s[j] == M_BB) && (s[i] == M_SA || s[i] == M_BA))
// 				s[i] = M_SS;
// 			else if ((s[j] == M_RB || s[j] == M_BB) && (s[i] == M_RA || s[i] == M_BA))
// 				s[i] = M_RR;
// 			else if ((s[j] == M_RRB || s[j] == M_BB) && (s[i] == M_RRA || s[i] == M_BA))
// 				s[i] = M_RRR;
// 			if (s[i] == M_SS || s[i] == M_RR || s[i] == M_RRR || s[i] == M_VID)
// 				s[j] = M_VID;
// 		}
// 	}
// }

// static void	ft_reduce_by_b(char *s, int i, int j)
// {
// 	while (s[++i] != 0)
// 	{
// 		if (s[i] == M_PB && s[i + 1] == M_PA)
// 		{
// 			s[i] = M_VID;
// 			s[i + 1] = M_VID;
// 		}
// 		else if (s[i] == M_SB || s[i] == M_RB || s[i] == M_RRB || s[i] == M_BB)
// 		{
// 			j = i + 1;
// 			while (s[j] == M_SB || s[j] == M_RB || s[j] == M_RRB
// 				|| s[j] == M_BB || s[j] == M_VID)
// 				j++;
// 			if ((s[j] == M_SA || s[j] == M_BA) && (s[i] == M_SB || s[i] == M_BB))
// 				s[i] = M_SS;
// 			else if ((s[j] == M_RA || s[j] == M_BA) && (s[i] == M_RB || s[i] == M_BB))
// 				s[i] = M_RR;
// 			else if ((s[j] == M_RRA || s[j] == M_BA) && (s[i] == M_RRB || s[i] == M_BB))
// 				s[i] = M_RRR;
// 			if (s[i] == M_SS || s[i] == M_RR || s[i] == M_RRR || s[i] == M_VID)
// 				s[j] = M_VID;
// 		}
// 	}
// }

// static char *ft_remove_void(char *s)
// {
// 	char		*n;
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 1;
// 	while (s[++i] != 0)
// 		if (s[i] != M_VID)
// 			j++;
// 	if (!(n = (char*)malloc(sizeof(*n) * j)))
// 		exit(EXIT_FAILURE);
// 	n[0] = M_VID;
// 	i = 0;
// 	j = 1;
// 	while (s[i++] != 0)
// 	{
// 		if (s[i] != M_VID)
// 		{
// 			n[j] = s[i];
// 			j++;
// 		}
// 	}
// 	free(s);
// 	return (n);
// }

void		ft_reduce(t_ps *ps)
{
	// int	i;
	// int	len2;

	// len2 = 0;
	// i = -1;
	// while (i != (int)ft_strlen(ps->cmd))
	// {
	// 	i = -1;
	// 	while (ps->cmd[++i] != 0)
	// 	{
	// 		len2 = ps->cmd[i] == M_PA ? len2-- : len2;
	// 		len2 = ps->cmd[i] == M_PB ? len2++ : len2;
	// 		if ((ps->cmd[i] == M_SA || ps->cmd[i] == M_RA
	// 			|| ps->cmd[i] == M_RRA) && (ps->len - len2) < 3)
	// 			ps->cmd[i] = M_BA;
	// 		else if ((ps->cmd[i] == M_SB || ps->cmd[i] == M_RB
	// 			|| ps->cmd[i] == M_RRB) && len2 < 3)
	// 			ps->cmd[i] = M_BB;
	// 	}
	// 	ft_reduce_by_a(ps->cmd, 0, 0);
	// 	ft_reduce_by_b(ps->cmd, 0, 0);
	// 	ft_rm_comeback(ps->cmd, 0, 0);
	// 	ps->cmd = ft_remove_void(ps->cmd);
	// }
	ft_print_cmd(ps->cmd);
	// free(ps->cmd);
}
