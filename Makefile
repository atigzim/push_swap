CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC =  ft_split.c  mov_one.c    mov_tow.c  parsing_tow.c   push_utils_tow.c	mov_three.c  parsing.c  push_swap.c    push_utils.c  sort.c
NAME = push_swap
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all