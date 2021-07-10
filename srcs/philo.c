/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:39:28 by ksam              #+#    #+#             */
/*   Updated: 2021/07/10 14:53:21 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char **argv)
{
	t_details	data;
	
	if (argc < 5 || argc > 6)
		return(printf("Error: wrong argument number\n"));

	memset(&data, -1, sizeof(data));
	
	if (philo_arg_checker(argv))
		return (error_argument());
	data.nb_philo = ft_atoi(argv[1]);
	return (0);
}