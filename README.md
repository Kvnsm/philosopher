# Philosophers

*I've never thought philosophy would be so deadly.*

In computer science, the dining philosophers problem is an
example problem often used in concurrent algorithm design to
illustrate synchronization issues and techniques for resolving them.

It was originally formulated in 1965 by Edsger Dijkstra as a
student exam exercise, presented in terms of computers competing
for access to tape drive peripherals. Soon after, Tony Hoare gave
the problem its present formulation.

## Description

There are 5 philosophers sitting around a round table eating spaghetti and each of them has one fork between them. All 5 of them sit around the table and pick up the fork placed towards their right. But, here’s the problem. To eat the spaghetti they need both the forks and since everyone picked up the fork to their right, nobody gets the left fork and hence, nobody can eat.

![Image of philo](https://static.javatpoint.com/operating-system/images/os-dining-philosophers-problem.gif)

## Getting Started

### Compile

Just make all

### Executing program

Example :
```
./philo 4 410 300 200 
```
Arguments :
* 4 is the number of philosophers, it is also the number of forks
* 410 is the time to die, is in milliseconds, if a philosopher doesn't start eating "time to die" milliseconds after starting his last meal or the beginning of the simulation, it dies
* 300 is the time to eat is in milliseconds and is the time it take for a philosopher to eat. During this time he will need to keep two forks.
* 200 is the time to sleep is in milliseconds and is the time the philosopher will spend sleeping.
* number_of_times_each_philosopher_must_eat: argument is optional, if all
philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the
simulation will stop. If not specified, the simulation will stop only at the death
of a philosopher.

### Error Code

* code 29	: Wrong argument number
* code 1	: Wrong argument syntax
* code 2	: Memory allocation failed
* code 3	: Pthread creation failed
* code 4	: Wrong number philo arg

### To test

* ./philo 4 410 200 200 (alive)
* ./philo 5 800 200 200 (alive)
* ./philo 4 410 300 200 (death)

### Link

* [Understand pthreads (french version)](https://franckh.developpez.com/tutoriels/posix/pthreads)
* [All videos of Code Vault to understand pthreads (english version)](https://youtu.be/d9s_d28yJq0)
* [Difference between Binary Semaphores and Mutexes](https://youtu.be/ZpRN3XQY4AA)