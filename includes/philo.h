/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:39:35 by ksam              #+#    #+#             */
/*   Updated: 2021/07/19 13:16:10 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo_stuff
{
	int					id;
	int					lfork;
	int					rfork;
	int					eat_counter;
	struct s_details	*details;
	long				last_meal;
	long				limit_time;
}						t_philo_stuff;

typedef struct s_details
{
	int					nb_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					must_eat_counter;
	int					philo_full_counter;

	t_philo_stuff		*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		blabla;

	long				start_timer;

}						t_details;

int				ft_atoi(const char *str);
int				ft_isdigit(int c);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
long			get_time(void);

int				error_messages(int code);
int				error_malloc(void);
int				error_argument(void);
int				error_pthread(void);
int				error_nb_philo(void);

int				philo_arg_checker(char **argv);
int				philo_arg_parser(t_details *data, char **argv, int argc);
void			init_philo(t_details *data);
int				init_mutexes(t_details *data);
int				thread_spawn(t_details *data);
void			*philosophe(void *arg);
void			manger(t_philo_stuff *philo);
void			dormir(t_philo_stuff *philo);
void			mutex_forks(t_philo_stuff *copy);
void			unmutex_forks(t_philo_stuff *copy);
void			clean_all(t_details *data, pthread_t *th);

void			display_messages(t_philo_stuff *philo, int code);

#endif