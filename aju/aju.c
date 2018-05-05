/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aju.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:38:02 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/05 19:12:26 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int main(int ac, char **av)
{
	int		fd;
	int 	i;
	char	*s;
	char	*d;

	fd = open("push/push_swap.h", O_RDONLY);
	d = ft_strnew(4000);
	fd = read(fd, d, 4000);
	d[fd] = 0;
	close(fd);
	fd = open("push/push_swap.h", O_WRONLY);
	i = 0;
	while (ft_strnequ(&d[i] , av[1], 4) == 0)
		i++;
	i += 6;
	s = ft_strjoin(ft_strndup(d, i), ft_strdup(av[2]));
	s[ft_strlen(av[2]) + i + 1] = 0;
ft_putnbr(i);ft_putendl("");
	i++;
	while (ft_isdigit(d[i]) == 1)
		i++;
ft_putnbr(i);ft_putendl("");
	s = ft_strjoin(s, &d[i]);
	ft_putstr_fd(s, fd);
	return (1);
}
