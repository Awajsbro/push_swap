/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:11:01 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/02 15:20:46 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct 	s_ps
{
	t_list		*lpa;
	t_list		*lpb;
	char		*cmd;
	char		opt;
	int			fdr;
	int			fdw;
}				t_ps;

void	ft_check(int ac, char **av, int i, t_ps *ps);
void	ft_get_setting(int ac, char **av, int *i, t_ps *ps);
void	ft_get_arg(int ac, char **av, int i, t_ps *ps);
void	ft_error(char **av, int i, int j, t_ps *ps);

#endif
