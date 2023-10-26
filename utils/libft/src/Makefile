NAME = libft.a
CC = cc
RM = rm -fr
SRCS = \
ft_bzero.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_memset.c ft_strlen.c ft_memcpy.c \
ft_memmove.c ft_strdup.c ft_strlcpy.c  \
ft_strlcat.c ft_toupper.c ft_tolower.c \
ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memcmp.c ft_memchr.c ft_strnstr.c \
ft_atoi.c ft_calloc.c ft_putchar_fd.c \
 ft_putstr_fd.c ft_substr.c ft_strjoin.c \
 ft_strtrim.c ft_putendl_fd.c ft_putnbr_fd.c \
 ft_itoa.c ft_strmapi.c ft_striteri.c \
 ft_split.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c \
ft_atox.c get_next_line.c ft_gridlen.c
OBJS = $(SRCS:%.c=./obj/%.o)
FLAGS = -Werror -Wextra -Wall -g

all: $(NAME)

$(NAME): $(OBJS)

./obj/%.o: %.c
	@mkdir -p obj
	@$(CC) $(FLAGS) -I../../../includes -c $< -o $@
	@ar -rcs -o ../$(NAME) $@

clean:
	$(RM) ./obj

fclean: clean
	$(RM) ../$(NAME)

re: fclean all