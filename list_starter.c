/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_starter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:25:38 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/06/25 18:40:15 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_long_atoi(const char *nptr)
{
	long	i;
	long	neg;

	i = 0;
	neg = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg *= (-1);
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		i = i * 10 + (*nptr - 48);
		nptr++;
	}
	return (i * neg);
}

void	del(void *lst_content) //Not sure if right
{
	lst_content = NULL;
}

void	exit_error(l_list *current)
{
	ft_lstclear(&current, &del);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	repeat_or_digit(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (++i < argc)
	{
		j = i + 1;
		while (++j < argc)
		{
			if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
				return (-1);
		}
		k = -1;
		while (++k)
		{
			if (ft_isalpha(argv[i][k]) ==  0
				|| argv[i][k] != '+' && argv[i][k] != '-')
				return (-1);
		}
	}
	return (0);
}

l_list	*list_create(int argc, char **argv)
{
	int		i;
	int		num;
	l_list	*current;
	l_list	*tracker;

	i = 0;
	while (++i < argc)
	{
		num = ft_long_atoi(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			exit_error(current);
		tracker = ft_lstnew(num);
		ft_lstadd_back(&current, tracker);
	}
	return (current);
}