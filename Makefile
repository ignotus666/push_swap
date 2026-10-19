# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarin-l <jmarin-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/18 22:30:00 by dahanlon          #+#    #+#              #
#    Updated: 2026/10/19 14:51:42 by jmarin-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
SRCS = $(SRC_DIR)/push_swap.c \
       $(SRC_DIR)/parse_utils.c \
       $(SRC_DIR)/stack_utils.c \
       $(SRC_DIR)/str_utils.c \
       $(SRC_DIR)/ft_split.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(SRC_DIR)/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re