/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:39:35 by ksam              #+#    #+#             */
/*   Updated: 2021/07/10 13:51:36 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct	s_details
{
	int			nb_philo;
	float		time_to_die;
	float		time_to_eat;
	float		time_to_sleep;
	int			nb_time_must_eat;
}				t_details;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);

int		error_argument(void);

#endif