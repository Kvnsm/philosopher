/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:48:20 by ksam              #+#    #+#             */
/*   Updated: 2021/07/17 07:47:57 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	error_messages(int code)
{
	if (code == 1)
		return (error_argument());
	else if (code == 2)
		return (error_malloc());
	else if (code == 3)
		return (error_pthread());
	else if (code == 4)
		return (error_nb_philo());
	return (-1);
}

int	error_argument(void)
{
	printf("Error: wrong argument syntax");
	return (1);
}

int	error_malloc(void)
{
	printf("Error: malloc failled\n");
	return (2);
}

int	error_pthread(void)
{
	printf("Error: pthread failled\n");
	return (3);
}

int	error_nb_philo(void)
{
	printf("Error: Number philo can't be 0\n");
	return (4);
}
