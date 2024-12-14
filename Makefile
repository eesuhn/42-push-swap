NAME = push_swap

MAKE = make --no-print-directory
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCDIR = srcs/
OBJDIR = objs/
SRC_FILES = \
			main \
			move \
			sort \
			utils \

SRCS = $(addprefix $(SRCDIR), $(SRC_FILES:=.c))
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Compiling $(NAME)..."
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "\033[0;32mDone!\033[0m"

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	@echo "> $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBFT):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@echo "\033[0;33mCleaning...\033[0m"
	@$(MAKE) -C $(LIBFT_PATH) clean
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
