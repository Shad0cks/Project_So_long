NAME			= libftprintf.a

SRCS_LIST		= \
					ft_printf.c 	\
					parse_args.c 	\
					aff_u.c 		\
					conv.c			\
					putall.c		\


SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

HEADER			= includes
FOLDER			= sources

LIBFT 			= ../libft

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}

$(NAME):		${OBJS}
				@make -C $(LIBFT)
				@cp ../libft/libft.a ./$(NAME)
				@ar -rcs ${NAME} ${OBJS}

bonus:			${NAME}

%.o: %.c
				@${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<

clean:
				@${RM} ${OBJS}
				@make clean -C $(LIBFT)

fclean:			clean
				@${RM} ${NAME}
				@make fclean -C $(LIBFT)

re:				fclean all

.PHONY: 		all fclean clean re