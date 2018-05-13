/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reduce2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 15:06:12 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/13 15:22:58 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rm_comeback_b_first(char *s, int i, int j)
{
	while (s[++i] != 0)
	{
		if (s[i] == M_PB && s[i + 1] == M_PA)
		{
			s[i] = M_VID;
			s[i + 1] = M_VID;
		}
		else if (s[i] == M_SB || s[i] == M_RB || s[i] == M_RRB || s[i] == M_BB)
		{
			j = i + 1;
			while (s[j] == M_SA || s[j] == M_RA || s[j] == M_RRA
				|| s[j] == M_BA || s[j] == M_VID)
				j++;
			if ((s[i] == M_SB && s[j] == M_SB)
				|| (s[i] == M_RB && s[j] == M_RRB)
					|| (s[i] == M_RRB && s[j] == M_RB) || s[j] == M_BB)
				s[i] = M_VID;
			s[j] = s[i] == M_VID ? M_VID : s[j];
		}
	}
}

void	ft_rm_comeback_a_first(char *s, int i, int j)
{
	while (s[++i] != 0)
	{
		if (s[i] == M_PA && s[i + 1] == M_PB)
		{
			s[i] = M_VID;
			s[i + 1] = M_VID;
		}
		else if (s[i] == M_SA || s[i] == M_RA || s[i] == M_RRA || s[i] == M_BA)
		{
			j = i + 1;
			while (s[j] == M_SB || s[j] == M_RB || s[j] == M_RRB
				|| s[j] == M_BB || s[j] == M_VID)
				j++;
			if ((s[i] == M_SA && s[j] == M_SA)
				|| (s[i] == M_RA && s[j] == M_RRA)
					|| (s[i] == M_RRA && s[j] == M_RA) || s[j] == M_BA)
				s[i] = M_VID;
			s[j] = s[i] == M_VID ? M_VID : s[j];
		}
	}
}

void	ft_reduce_by_a(char *s, int i, int j)
{
	while (s[++i] != 0)
	{
		if (s[i] == M_SA || s[i] == M_RA || s[i] == M_RRA || s[i] == M_BA)
		{
			j = i + 1;
			while (s[j] == M_SA || s[j] == M_RA || s[j] == M_RRA
				|| s[j] == M_BA || s[j] == M_VID)
				j++;
			if ((s[j] == M_SB || s[j] == M_BB)
				&& (s[i] == M_SA || s[i] == M_BA))
				s[i] = M_SS;
			else if ((s[j] == M_RB || s[j] == M_BB)
				&& (s[i] == M_RA || s[i] == M_BA))
				s[i] = M_RR;
			else if ((s[j] == M_RRB || s[j] == M_BB)
				&& (s[i] == M_RRA || s[i] == M_BA))
				s[i] = M_RRR;
			if (s[i] == M_SS || s[i] == M_RR || s[i] == M_RRR || s[i] == M_VID)
				s[j] = M_VID;
		}
	}
}

void	ft_reduce_by_b(char *s, int i, int j)
{
	while (s[++i] != 0)
	{
		if (s[i] == M_SB || s[i] == M_RB || s[i] == M_RRB || s[i] == M_BB)
		{
			j = i + 1;
			while (s[j] == M_SB || s[j] == M_RB || s[j] == M_RRB
				|| s[j] == M_BB || s[j] == M_VID)
				j++;
			if ((s[j] == M_SA || s[j] == M_BA)
				&& (s[i] == M_SB || s[i] == M_BB))
				s[i] = M_SS;
			else if ((s[j] == M_RA || s[j] == M_BA)
				&& (s[i] == M_RB || s[i] == M_BB))
				s[i] = M_RR;
			else if ((s[j] == M_RRA || s[j] == M_BA)
				&& (s[i] == M_RRB || s[i] == M_BB))
				s[i] = M_RRR;
			if (s[i] == M_SS || s[i] == M_RR || s[i] == M_RRR || s[i] == M_VID)
				s[j] = M_VID;
		}
	}
}
