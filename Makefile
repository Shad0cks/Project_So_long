LIBFT_PATH		=	./libs/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./libs/minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

GNL_PATH		=	./libs/Get_Next_Line
GNL				=	$(GNL_PATH)/GNL.a

SOURCES_FILES	=	main.c \
					check_piece.c \
					init_map.c \
					init_player.c \
					make_map.c \
					player_move.c 

SOURCES_BONUS	=	main.c \
					check_piece.c \
					init_map.c \
					init_player.c \
					make_map.c \
					player_move.c 


SOURCES_DIR		=	source
BONUS_DIR		=	source

HEADER			=	include/header.h
HEEADER_BONUS	=	include/header.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
BONUS_FILES		=	$(addprefix $(BONUS_DIR)/, $(SOURCES_BONUS))

OBJECTS			= 	$(SOURCES:.c=.o)
OBJECTS_BONUS	= 	$(BONUS_FILES:.c=.o)

NAME			=	so_long
NAME_BONUS		=	so_long_bonus

CC				=	clang
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-L $(MINILIBX_PATH) -lmlx -framework OpenGL -framework AppKit

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(LIBFT) $(GNL) $(MINILIBX) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJECTS) $(GNL) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(NAME_BONUS):		$(LIBFT) $(GNL) $(MINILIBX) $(OBJECTS_BONUS) $(HEADER_BONUS)
					$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(GNL) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME_BONUS)

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
				$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(MAKE) -C $(GNL_PATH) fclean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

.PHONY:			all clean fclean re libft minilibx bonus