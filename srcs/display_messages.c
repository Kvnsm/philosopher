/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_messages.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:16:44 by ksam              #+#    #+#             */
/*   Updated: 2021/07/17 07:47:25 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	display_messages(t_philo_stuff *philo, int code)
{
	long	timestamp;

	timestamp = get_time() - philo->details->start_timer;
	pthread_mutex_lock(&philo->details->blabla);
	if (code == 1)
		printf("%ld \t %d is eating\n", timestamp, philo->id + 1);
	else if (code == 2)
		printf("%ld \t %d is sleeping\n", timestamp, philo->id + 1);
	else if (code == 3)
		printf("%ld \t %d has taken a fork\n", timestamp, philo->id + 1);
	else if (code == 4)
		printf("%ld \t %d is thinking\n", timestamp, philo->id + 1);
	else
		printf("%ld \t %d died\n", timestamp, philo->id + 1);
	if (code != 5)
		pthread_mutex_unlock(&philo->details->blabla);
}
