NAME = libft.a
CC = gcc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror
FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_calloc.c ft_isprint.c ft_memccpy.c \
		ft_itoa.c ft_isascii.c ft_memchr.c ft_memcpy.c ft_memset.c ft_isdigit.c ft_putendl_fd.c \
		ft_memcmp.c ft_putchar_fd.c ft_putnbr_fd.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_split.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strmapi.c ft_strnstr.c ft_strtrim.c \
		ft_substr.c ft_tolower.c ft_memmove.c ft_putstr_fd.c ft_strrchr.c ft_toupper.c
OBJ = $(FILES:.c=.o)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

%.o: %.c
			$(CC) -I. -o $@ -c $? $(FLAGS)

all:	$(NAME)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all
