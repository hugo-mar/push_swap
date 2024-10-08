# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 14:39:20 by hugo-mar          #+#    #+#              #
#    Updated: 2024/10/08 18:37:40 by hugo-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
PUSH_SWAP_ARCHIVE = push_swap.a
CHECKER_ARCHIVE = checker.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -Isources -Iget_next_line
MAKE_LIB = ar -rcs

SRC_DIR = sources
GNL_DIR = get_next_line

SRCS = $(SRC_DIR)/algorithm1.c $(SRC_DIR)/algorithm2.c $(SRC_DIR)/algorithm3.c \
       $(SRC_DIR)/commands1.c $(SRC_DIR)/commands2.c $(SRC_DIR)/error_handling.c \
       $(SRC_DIR)/push_swap.c $(SRC_DIR)/split.c $(SRC_DIR)/stack_init.c \
       $(SRC_DIR)/stack_utils.c

BONUS_SRCS = $(SRC_DIR)/algorithm1.c $(SRC_DIR)/algorithm2.c $(SRC_DIR)/algorithm3.c \
             $(SRC_DIR)/commands1.c $(SRC_DIR)/commands2.c $(SRC_DIR)/error_handling.c \
             $(SRC_DIR)/checker.c $(SRC_DIR)/split.c $(SRC_DIR)/stack_init.c \
             $(SRC_DIR)/stack_utils.c $(SRC_DIR)/libft.c $(SRC_DIR)/checker_utils.c\
			 $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PUSH_SWAP_ARCHIVE)
	$(CC) $(PUSH_SWAP_ARCHIVE) -o $(NAME)

$(PUSH_SWAP_ARCHIVE): $(OBJS)
	$(MAKE_LIB) $(PUSH_SWAP_ARCHIVE) $(OBJS)

bonus: $(NAME) $(CHECKER)

$(CHECKER): $(CHECKER_ARCHIVE)
	$(CC) $(CHECKER_ARCHIVE) -o $(CHECKER)

$(CHECKER_ARCHIVE): $(BONUS_OBJS)
	$(MAKE_LIB) $(CHECKER_ARCHIVE) $(BONUS_OBJS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(PUSH_SWAP_ARCHIVE) $(CHECKER_ARCHIVE)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus
