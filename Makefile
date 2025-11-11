# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 09:56:21 by rcompain          #+#    #+#              #
#    Updated: 2025/11/11 12:52:27 by rcompain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
# **************************************************************************** #
#                                   SETTINGS                                   #
# **************************************************************************** #

NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar rcs

# **************************************************************************** #
#                                   PATHS                                      #
# **************************************************************************** #

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= include
LIBFT_DIR	= libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRC			= $(SRC_DIR)/main.c

OBJ			= ${SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o}

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: banner $(LIBFT_A) $(NAME)

$(NAME): progress_bar_project $(OBJ)
	@$(CC) $(CFLAGS) -I$(INC_DIR) $(OBJ) $(LIBFT_A) -o $(NAME)
	@echo "$(BOLT) $(GREEN)         Project compiled successfully ✅$(RESET)\n\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "$(CYAN)Compiled files: $<$(RESET)\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT_A):progress_bar_libft
	@make -s -C $(LIBFT_DIR)
	

clean:
	@make clean -s -C $(LIBFT_DIR)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(CYAN)Object files removed$(RESET)"

fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@echo "$(CYAN)Executable removed$(RESET)"

re : fclean all

# **************************************************************************** #
#                                   DECO & COLORS                              #
# **************************************************************************** #

GREEN		= \033[32m
CYAN		= \033[36m
PINK		= \033[35m
BROWN1  = \033[38;5;94m
BROWN2  = \033[38;5;130m
ORANGE  = \033[38;5;214m
YELLOW  = \033[38;5;228m
RESET		= \033[0m

BOLT		=\033[1m

BANNER = \
"$(BOLT)$(ORANGE)\n\n  	          Compilation ...  $(RESET)\n"\

banner:
	@echo $(BANNER)

progress_bar_libft:	
	@total=30; \
	i=1; \
	printf "📚  Libft  ["; \
	while [ $$i -le $$total ]; do \
		bar="$$(printf '█%.0s' $$(seq 1 $$i))"; \
		spaces=""; \
		if [ $$i -lt $$total ]; then \
			spaces="$$(printf ' %.0s' $$(seq 1 $$((total - i))))"; \
		fi; \
		pct=$$((i * 100 / $$total)); \
		printf "\r📚  Libft  [$$bar$$spaces] Loading:%3d%%" $$pct; \
		sleep 0.05; \
		i=$$((i+1)); \
	done; \
	printf "\033[2K\r📚  Libft %s [██████████████████████████████] \033[32mSuccess !\033[0m\n\n"

progress_bar_project:
	@total=30; \
	i=1; \
	printf "📝 Project ["; \
	while [ $$i -le $$total ]; do \
		bar="$$(printf '█%.0s' $$(seq 1 $$i))"; \
		spaces=""; \
		if [ $$i -lt $$total ]; then \
			spaces="$$(printf ' %.0s' $$(seq 1 $$((total - i))))"; \
		fi; \
		pct=$$((i * 100 / $$total)); \
		printf "\r📝 Project [$$bar$$spaces] Loading:%3d%%" $$pct; \
		sleep 0.03; \
		i=$$((i+1)); \
	done; \
	printf "\033[2K\r📝 Project %s[██████████████████████████████] \033[32mSuccess !\033[0m\n\n"


.PHONY: all clean fclean re banner progress_bar_libft

