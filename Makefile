NAME			= prog.a

SRCS_LIST		= \
					main.c 	\
					init_map.c 	\
					check_piece.c \
					make_map.c



SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

HEADER			= include
FOLDER			= source


CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}

$(NAME):		${OBJS}
				@ar -rcs ${NAME} ${OBJS}

bonus:			${NAME}

%.o: %.c
				@${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<

clean:
				@${RM} ${OBJS}

fclean:			clean
				@${RM} ${NAME}

re:				fclean all

.PHONY: 		all fclean clean re