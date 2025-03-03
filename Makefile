CC = cc
CFLAGS = -Wall -Wextra -Werror
MAIN = push_swap.c
BNS = checker.c
SRC =  ft_split.c  mov_checker_one.c mov_checker_tow.c  mov_checker_three.c  checker_utils.c  get_next_line.c mov_one.c get_next_line_utils.c push_swap_u.c mov_tow.c  parsing_two.c   push_utils_two.c	mov_three.c  parsing.c  push_utils.c  sort.c
NAME = push_swap
CHECKER = checker
OBJ = $(SRC:.c=.o)
OBJ_M = $(MAIN:.c=.o)
OBJ_BNS = $(BNS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_M)
	@$(CC) $(CFLAGS) $(OBJ) $(OBJ_M) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus : $(CHECKER)

$(CHECKER) : $(OBJ_BNS) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(OBJ_BNS) -o $(CHECKER)

clean:
	rm -f $(OBJ) $(OBJ_M) $(OBJ_BNS)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all