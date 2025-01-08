/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:08:48 by pcruz             #+#    #+#             */
/*   Updated: 2025/01/08 10:27:14 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print_status(t_philosopher *philosopher, char *status)
{
	pthread_mutex_lock(&philosopher->data->print_lock);
	if (!philosopher->data->death_occurred)
		printf("%ld %d %s\n", get_time_in_ms() - philosopher->data->start_time,
			philosopher->id, status);
	pthread_mutex_unlock(&philosopher->data->print_lock);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	while (1)
	{
		pthread_mutex_lock(&philosopher->data->death_lock);
		if (philosopher->data->death_occurred)
		{
			pthread_mutex_unlock(&philosopher->data->death_lock);
			break ;
		}
		pthread_mutex_unlock(&philosopher->data->death_lock);
		print_status(philosopher, "is thinking");
		pthread_mutex_lock(philosopher->left_fork);
		print_status(philosopher, "has taken a fork");
		pthread_mutex_lock(philosopher->right_fork);
		print_status(philosopher, "has taken a fork");
		print_status(philosopher, "is eating");
		philosopher->last_meal_time = get_time_in_ms();
		usleep(philosopher->data->time_to_eat);
		philosopher->times_eaten++;
		if (philosopher->data->number_of_times_each_philosopher_must_eat > 0
			&& philosopher->times_eaten
			== philosopher->data->number_of_times_each_philosopher_must_eat)
		{
			pthread_mutex_lock(&philosopher->data->death_lock);
			philosopher->data->all_philosophers_ate++;
			pthread_mutex_unlock(&philosopher->data->death_lock);
		}
		pthread_mutex_unlock(philosopher->right_fork);
		pthread_mutex_unlock(philosopher->left_fork);
		print_status(philosopher, "is sleeping");
		usleep(philosopher->data->time_to_sleep);
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	long	time_since_last_meal;
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&data->death_lock);
		if (data->death_occurred || data->all_philosophers_ate
			== data->number_of_philosophers)
		{
			pthread_mutex_unlock(&data->death_lock);
			return (NULL);
		}
		pthread_mutex_unlock(&data->death_lock);
		while (i < data->number_of_philosophers)
		{
			pthread_mutex_lock(&data->death_lock);
			time_since_last_meal = get_time_in_ms()
				- data->philosophers[i].last_meal_time;
			if (time_since_last_meal > data->time_to_die)
			{
				data->death_occurred = 1;
				printf("%ld %d %s\n", get_time_in_ms()
					- data->philosophers[i].data->start_time,
					data->philosophers[i].id, "died");
				pthread_mutex_unlock(&data->death_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&data->death_lock);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	monitor_thread;
	t_data	data;
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("Usage: %s number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n", argv[0]);
		return (0);
	}
	data.number_of_philosophers = ft_atol(argv[1]);
	data.time_to_die = ft_atol(argv[2]);
	data.time_to_eat = ft_atol(argv[3]);
	data.time_to_sleep = ft_atol(argv[4]);
	data.number_of_times_each_philosopher_must_eat = (argc == 6) ? ft_atol(argv[5]) : -1;
	data.all_philosophers_ate = 0;
	data.death_occurred = 0;
	data.start_time = get_time_in_ms();
	data.forks = malloc(data.number_of_philosophers * sizeof(pthread_mutex_t));
	data.philosophers = malloc(data.number_of_philosophers * sizeof(t_philosopher));
	if (!data.forks || !data.philosophers)
	{
		printf("Memory allocation failed.\n");
		free(data.forks);
		free(data.philosophers);
		return (1);
	}
	i = -1;
	while (++i < data.number_of_philosophers)
		pthread_mutex_init(&data.forks[i], NULL);
	pthread_mutex_init(&data.print_lock, NULL);
	pthread_mutex_init(&data.death_lock, NULL);
	i = -1;
	while (++i < data.number_of_philosophers)
	{
		data.philosophers[i].id = i + 1;
		data.philosophers[i].times_eaten = 0;
		data.philosophers[i].last_meal_time = data.start_time;
		data.philosophers[i].left_fork = &data.forks[i];
		data.philosophers[i].right_fork = &data.forks[(i + 1) % data.number_of_philosophers];
		data.philosophers[i].data = &data;
	pthread_create(&data.philosophers[i].thread, NULL, philosopher_routine, &data.philosophers[i]);
	}
	pthread_create(&monitor_thread, NULL, monitor_routine, &data);
	pthread_join(monitor_thread, NULL);
	i = -1;
	while (++i < data.number_of_philosophers)
		pthread_join(data.philosophers[i].thread, NULL);
	i = -1;
	while (++i < data.number_of_philosophers)
		pthread_mutex_destroy(&data.forks[i]);
	pthread_mutex_destroy(&data.print_lock);
	pthread_mutex_destroy(&data.death_lock);
	free(data.forks);
	free(data.philosophers);
	return (0);
}
