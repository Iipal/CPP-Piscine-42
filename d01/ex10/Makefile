NAME := cat09tails
NPWD := $(CURDIR)/$(NAME)

CC := clang++ -march=native -mtune=native -Ofast -flto -pipe
CC_DEBUG := clang++ -march=native -mtune=native -g3 -D DEBUG -fsanitize=address
CFLAGS := -Wall -Wextra -Werror -Wunused

SRCS := $(abspath $(wildcard *.cpp))
OBJ := $(SRCS:.cpp=.o)

DEL := rm -rf

WHITE := \033[0m
BGREEN := \033[42m
GREEN := \033[32m
RED := \033[31m
INVERT := \033[7m

SUCCESS := [$(GREEN)✓$(WHITE)]
SUCCESS2 := [$(INVERT)$(GREEN)✓$(WHITE)]

all: $(NAME)

$(OBJ): %.o: %.cpp
	@echo -n ' $@: '
	@$(CC) -c $(CFLAGS) $(LIBSINC) $(IFLAGS) $< -o $@
	@echo "$(SUCCESS)"

$(NAME): $(OBJ)
	@echo -n ' <q.p> | $(NPWD): '
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)
	@echo "$(SUCCESS2)"

del:
	@$(DEL) $(OBJ)
	@$(DEL) $(NAME)

pre: del all
	@echo "$(INVERT)$(GREEN)Successed re-build.$(WHITE)"

set_cc_debug:
	@$(eval CC=$(CC_DEBUG))
debug_all: set_cc_debug pre
	@echo "$(INVERT)$(NAME) $(GREEN)ready for debug.$(WHITE)"
debug: set_cc_debug all
	@echo "$(INVERT)$(NAME) $(GREEN)ready for debug.$(WHITE)"

clean:
	@$(DEL) $(OBJ)

fclean: clean
	@$(DEL) $(NAME)
	@echo "$(INVERT)$(RED)deleted$(WHITE)$(INVERT): $(NPWD)$(WHITE)"

re: fclean all

.PHONY: re fclean clean all del pre debug debug_all
