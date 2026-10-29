# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/18 22:30:00 by dahanlon          #+#    #+#              #
#    Updated: 2026/10/27 16:09:05 by dahanlon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
SRCS = $(SRC_DIR)/parse_utils.c \
       $(SRC_DIR)/stack_utils.c \
       $(SRC_DIR)/str_utils.c \
       $(SRC_DIR)/ft_split.c \
	   $(SRC_DIR)/compute_disorder.c \
	   $(SRC_DIR)/op_swap.c \
	   $(SRC_DIR)/op_push.c \
	   $(SRC_DIR)/op_rotate.c \
	   $(SRC_DIR)/op_rev_rotate.c \
	   $(SRC_DIR)/alg_simple.c \
	   $(SRC_DIR)/alg_medium.c \
	   $(SRC_DIR)/alg_complex.c \
	   $(SRC_DIR)/alg_adaptive.c \
	   $(SRC_DIR)/alg_utils.c \
	   $(SRC_DIR)/bench.c

OBJS = $(SRCS:.c=.o)

PS_SRC = $(SRC_DIR)/push_swap.c
PS_OBJ = $(PS_SRC:.c=.o)

BONUS_SRC = $(SRC_DIR)/checker.c \
			$(SRC_DIR)/checker_utils.c \
			$(SRC_DIR)/get_next_line.c \
			$(SRC_DIR)/get_next_line_utils.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(PS_OBJ)
	$(CC) $(CFLAGS) $(OBJS) $(PS_OBJ) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJS) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJ) -o $(BONUS)

%.o: %.c $(SRC_DIR)/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(PS_OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re