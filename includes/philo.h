/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:39:35 by ksam              #+#    #+#             */
/*   Updated: 2021/07/13 18:08:23 by ksam             ###   ########lyon.fr   */
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

int				ft_atoi(const char *str);
int				ft_isdigit(int c);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);

int				error_argument(void);

int				philo_arg_checker(char **argv);
int				philo_arg_parser(t_details *data, char **argv, int argc);

#endif