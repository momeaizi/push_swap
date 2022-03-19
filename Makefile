NAME = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	push_swap.c \
	sort/sort.c \
	sort/quiqsort.c \
	utils/utils.c \
	utils/list.c \
	operations/parent_rules.c \
	operations/child_rules.c \
	operations/rules.c \
	utils/main_utils.c
CHECKER_SRCS = checker.c \
	sort/sort.c \
	sort/quiqsort.c \
	utils/utils.c \
	utils/list.c \
	operations/parent_rules_checker.c \
	operations/child_rules_checker.c \
	operations/rules_checker.c \
	utils/get_line.c \
	utils/main_utils.c

.PHONY : all fclean clean re

all : $(NAME)

$(CHECKER) : $(CHECKER_SRCS)
	$(CC) $(CFLAGS) $(CHECKER_SRCS) -o $(CHECKER)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean :
	rm -f $(NAME)

fclean : clean
	rm -f $(CHECKER)

re : fclean all
