NAME		= pipex


SRCS		= pipex.c utils.c

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I$(LIBFT_DIR) -g

$(NAME): $(LIBFT) $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

all: $(NAME) $(BONUS)

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(BONUS_SRCS)
	@$(CC) $(CFLAGS) $(BONUS_SRCS) -L$(LIBFT_DIR) -lft -o $(BONUS)

clean:
	@make -s -C $(LIBFT_DIR) clean

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
