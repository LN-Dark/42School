/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:52:26 by pcruz             #+#    #+#             */
/*   Updated: 2025/01/08 10:21:45 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philosopher
{
    int id;
    int times_eaten;
    pthread_t   thread;
    long    last_meal_time;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    struct s_data   *data;
} t_philosopher;

typedef struct s_data
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
    int all_philosophers_ate;
    pthread_mutex_t *forks;
    pthread_mutex_t print_lock;
    pthread_mutex_t death_lock;
    long    start_time;
    t_philosopher   *philosophers;
    int death_occurred;
} t_data;

long    get_time_in_ms(void);
void    print_status(t_philosopher *philosopher, char *status);
void    *philosopher_routine(void *arg);
void    *monitor_routine(void *arg);
long    ft_atol(const char *str);

#endif