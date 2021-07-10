/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:13:32 by ksam              #+#    #+#             */
/*   Updated: 2021/07/10 13:13:57 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		signe;
	long	nb;

	i = 0;
	signe = 1;
	nb = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			signe *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb * signe > 2147483647)
			return (-1);
		if (nb * signe < -2147483648)
			return (0);
		nb = (nb * 10) + (str[i++] - '0');
	}
	return (nb * signe);
}