NAME = so_long

GNL_NAME = ./get_next_line/get_next_line.a

SRC = so_long.c utils.c utils2.c validfilecheck.c mapcontrols1.c mapcontrols2.c init_map.c movements.c

GNL_SRC = ./get_next_line/get_next_line.c ./get_next_line/get_next_line.h ./get_next_line/get_next_line_utils.c

MLX_DIR = ./mlx

MLX_LIB = ./mlx/libmlx.a

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

CC = @gcc

CFLAGS = -Wall -Wextra -Werror -g

AR = @ar -rcs

GNL_OBJS = $(GNL_SRC:.c=.o)

all: $(GNL_NAME) $(NAME)

$(GNL_NAME): $(GNL_OBJS)
	$(AR) $(GNL_NAME) $(GNL_OBJS)

$(NAME): $(SRC)
	@make re -C $(MLX_DIR)
	$(CC) $(CFLAG) $(SRC) $(GNL_NAME) $(MLX_FLAGS) -o $(NAME)

clean :
	@rm -rf ./get_next_line/*.o
	@rm -rf ./mlx/*.o

fclean :
	@rm -rf $(NAME)
	@make clean -C $(MLX_DIR)
	@rm -rf ./get_next_line/*.o
	@rm -rf $(GNL_NAME)

re : fclean all

.PHONY: all clean fclean re