/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 07:38:19 by ksam              #+#    #+#             */
/*   Updated: 2021/07/17 07:38:31 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	dormir(t_philo_stuff *philo)
{
	display_messages(philo, 2);
	usleep(philo->details->time_to_sleep * 1000);
}
