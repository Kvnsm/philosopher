/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 07:37:29 by ksam              #+#    #+#             */
/*   Updated: 2021/07/19 13:16:03 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	manger(t_philo_stuff *philo)
{
	philo->last_meal = get_time();
	philo->limit_time = philo->last_meal + philo->details->time_to_die;
	display_messages(philo, 1);
	++philo->eat_counter;
	usleep(philo->details->time_to_eat * 1000);
}
