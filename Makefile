# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 11:31:41 by ksam              #+#    #+#              #
#    Updated: 2021/07/16 18:39:02 by ksam             ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
NAME		=	philo
INCLUDE		=	includes/philo.h
SRCS		=	srcs/philo.c \
				srcs/argument_parser.c \
				srcs/display_messages.c \
				srcs/error.c \
				srcs/ft_atoi.c \
				srcs/ft_calloc.c \
				srcs/ft_isdigit.c \
				srcs/init_philo.c \
				srcs/routine.c \
				srcs/thread_spawn.c \
				srcs/timer.c
				
OBJS		=	$(SRCS:.c=.o)
CFLAGS		=	-Wall -Werror -Wextra -g3 -fsanitize=address -pthread

all:		$(NAME)

$(NAME):	$(OBJS)	$(INCLUDE)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.c.o:
			$(CC) $(FLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:
			make fclean
			make all

.PHONY:		all clean fclean re