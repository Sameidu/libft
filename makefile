NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB = ar -rcs
INCLUDES = libft.h
SRCS = ft_atoi.c ft_isascii.c ft_memcpy.c ft_putnbr_fd.c ft_strncmp.c ft_bzero.c ft_isdigit.c ft_memmove.c ft_putstr_fd.c ft_calloc.c ft_isprint.c ft_memset.c ft_strlcat.c ft_isalnum.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_tolower.c ft_isalpha.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strmapi.c ft_striteri.c ft_itoa.c ft_striteri.c ft_split.c ft_strtrim.c ft_strrchr.c ft_strnstr.c
SRCS_BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c  ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
RM = /bin/rm -f

all: $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $?

$(NAME): $(OBJS) $(INCLUDES)
		$(LIB) $(NAME) $(OBJS)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(SRCS_BONUS)
	$(LIB) $(OBJS_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus