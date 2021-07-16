/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:48:20 by ksam              #+#    #+#             */
/*   Updated: 2021/07/16 02:54:48 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		error_messages(int code)
{
	if (code == 1)
		return (error_argument());
	else if (code == 2)
		return(error_malloc());
	else if (code == 3)
		return(error_pthread());
	return (-1);
}

int		error_argument(void)
{
	printf("Error: wrong argument syntax");
	return (1);
}

int		error_malloc(void)
{
	printf("Error: malloc failled\n");
	return (2);
}

int		error_pthread(void)
{
	printf("Error: pthread failled\n");
	return (3);
}