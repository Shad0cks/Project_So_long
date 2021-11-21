# LIB NAME

NAME	= libft.a

# SOURCES

SRC	= \
	ft_memset ft_memcpy ft_memmove ft_memchr ft_memcmp ft_bzero \
	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
	ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
	ft_strchr ft_strrchr ft_strncmp ft_strnstr \
	ft_substr ft_strjoin ft_strtrim ft_split\
	ft_strlen ft_strlcpy ft_strlcat \
	ft_strmapi ft_striteri \
	ft_toupper ft_tolower \
	ft_strdup ft_calloc \
	ft_atoi ft_itoa

SRCS	= $(addsuffix .c, $(SRC))
OBJS	= $(SRCS:.c=.o)

B_SRC	= \
	ft_lstnew ft_lstadd_front ft_lstadd_back \
	ft_lstdelone ft_lstclear \
	ft_lstsize ft_lstlast \
	ft_lstiter ft_lstmap

B_SRCS	= $(addsuffix .c, $(B_SRC))
B_OBJS	= $(B_SRCS:.c=.o)

# COMMANDS

CC		= gcc
RM		= rm -f
AR		= ar rc
RN		= ranlib

CFLAGS	= -Wall -Werror -Wextra

# RULES

%.o: %.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(RN) $(NAME)

bonus: $(NAME) $(B_OBJS)
	@$(AR) $(NAME) $(OBJS) $(B_OBJS)
	@$(RN) $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all