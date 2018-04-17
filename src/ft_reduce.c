/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reduce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:51:26 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/17 17:28:00 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_print_cmd(char *s)
{
	while (*(s++) != 0)
	{
		if (*s == M_SA)
			write(1, "sa\n", 3);
		else if (*s == M_SB)
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

void		ft_reduce(t_ps *ps)
{
	ft_print_cmd(ps->cmd);
	free(ps->cmd);
}
