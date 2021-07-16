/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 04:06:15 by ksam              #+#    #+#             */
/*   Updated: 2021/07/16 14:03:00 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time(void)
{
	struct timeval	t1;
	long			ret;

	gettimeofday(&t1, NULL);

	ret = (t1.tv_sec * 1000.0) + (t1.tv_usec / 1000.0);
	return (ret);
}