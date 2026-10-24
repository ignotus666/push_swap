# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/18 22:30:00 by dahanlon          #+#    #+#              #
#    Updated: 2026/10/22 14:40:03 by dahanlon         ###   ########.fr        #
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
       $(SRC_DIR)/ft_split.c \
	   $(SRC_DIR)/compute_disorder.c \
	   $(SRC_DIR)/op_swap.c \
	   $(SRC_DIR)/op_push.c \
	   $(SRC_DIR)/op_rotate.c \
	   $(SRC_DIR)/op_rev_rotate.c \
	   $(SRC_DIR)/alg_simple.c

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