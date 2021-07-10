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