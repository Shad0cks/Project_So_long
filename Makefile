LIBFT_PATH		=	./libs/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./libs/minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

GNL_PATH		=	./libs/Get_Next_Line
GNL				=	$(GNL_PATH)/GNL.a

BONUS_PATH		=	./bonus

SOURCES_FILES	=	main.c \
					check_piece.c \
					init_map.c \
					init_player.c \
					make_map.c \
					player_move.c \
					player_move2.c \
					exit.c


SOURCES_DIR		=	source

HEADER			=	include/header.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

NAME			=	so_long

CC				=	clang
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-L $(MINILIBX_PATH) -lmlx -framework OpenGL -framework AppKit

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

bonus:			
				$(MAKE) -C $(BONUS_PATH)

$(NAME):		$(LIBFT) $(GNL) $(MINILIBX) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJECTS) $(GNL) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(GNL):
				$(MAKE) -C $(GNL_PATH)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(GNL_PATH) clean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(MAKE) -C $(BONUS_PATH) clean
				$(RM) $(OBJECTS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(MAKE) -C $(GNL_PATH) fclean
				$(MAKE) -C $(BONUS_PATH) fclean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus