

NAME = libasm.a

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

PR_NAME = asm_test

SRC = ft_strcmp.s ft_read.s ft_write.s\
	 ft_strdup.s ft_strlen.s ft_strcpy.s


OBJ = $(SRC:.s=.o)

$(NAME):
		@nasm -f elf64 ft_strcmp.s
		@nasm -f elf64 ft_read.s
		@nasm -f elf64 ft_write.s
		@nasm -f elf64 ft_strdup.s
		@nasm -f elf64 ft_strlen.s
		@nasm -f elf64 ft_strcpy.s
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME) $(PR_NAME)

test: all
		gcc $(CFLAGS) main.c libasm.a -o $(PR_NAME)

re: fclean all