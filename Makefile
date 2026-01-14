# LIBFT
LIBFT_URL = https://github.com/ana-fon/libft_updated.git

LIBS_PATH = libs
LIBFT_PATH = $(LIBS_PATH)/libft
LIBFT_ARCH = $(LIBFT_PATH)/libft.a

CHECKER = checker_linux
CHECKER_URL = https://cdn.intra.42.fr/document/document/42928/checker_linux
TESTER = push_swap_tester.sh
TESTER_URL = https://raw.githubusercontent.com/SirMrPenguin/Push_Swap_simple_tester/refs/heads/main/push_swap_tester.sh

NAME = push_swap

SRC_PATH = src
INC_PATH = src

FILES = main.c operations/push.c operations/rev_rotate.c operations/rotate.c \
		operations/swap.c parsing/parsing_utils.c parsing/parsing.c \
		sorting/list_utils.c sorting/radix_sort.c sorting/sort_small.c

SRC = $(addprefix $(SRC_PATH)/, $(FILES))
OBJS = $(SRC:.c=.o)

HEADERS = $(INC_PATH)/push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I $(INC_PATH) -I $(LIBFT_PATH)

RM = rm -fr
MAKE_LIBFT = make -C $(LIBFT_PATH)

# ------------------------------------------------------------------------------

all: deps $(NAME)

tests:
	@if [ ! -f "$(CHECKER)" ]; then \
		wget $(CHECKER_URL) ; \
		chmod +x $(CHECKER) ; \
	fi
	@if [ ! -f "$(TESTER)" ]; then \
		wget $(TESTER_URL) ; \
		chmod +x $(TESTER) ; \
		mv $(TESTER) vibe_tester.sh; \
	fi

deps:
	@if [ ! -d "$(LIBFT_PATH)" ]; then make get_libft; fi

$(NAME): $(LIBFT_ARCH) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INC) $(LIBFT_ARCH) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

get_libft:
	@mkdir -p $(LIBS_PATH)
	@if [ ! -d "$(LIBFT_PATH)" ]; then \
		git clone $(LIBFT_URL) $(LIBFT_PATH); \
	fi

$(LIBFT_ARCH):
	$(MAKE_LIBFT)

clean:
	$(RM) $(OBJS)
	@if [ -d "$(LIBFT_PATH)" ]; then $(MAKE_LIBFT) clean; fi
	@if [ -f $(CHECKER) ]; then rm -fr $(CHECKER); fi
	@if [ -f vibe_tester.sh ]; then rm -fr vibe_tester.sh; fi
	@if [ -f logs.txt ]; then rm -fr logs.txt; fi
	@if [ -f valgrind.log ]; then rm -fr valgrind.log; fi

fclean: clean
	$(RM) $(NAME) $(LIBS_PATH)

re: fclean all

.PHONY: all deps clean fclean re get_libft tests
