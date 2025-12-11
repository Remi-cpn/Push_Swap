# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 09:56:21 by rcompain          #+#    #+#              #
#    Updated: 2025/12/11 20:35:36 by remi-cpn         ###   ########.fr        #
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

SRC			= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/move_push.c \
			  $(SRC_DIR)/move_rotate.c \
			  $(SRC_DIR)/move_reverse_rotate.c \
			  $(SRC_DIR)/utils.c \
			  $(SRC_DIR)/sort.c \
			  $(SRC_DIR)/sort_best_index.c \
			  $(SRC_DIR)/parsing.c \
			  $(SRC_DIR)/parsing_utils.c \
			  $(SRC_DIR)/memory.c \
			  $(SRC_DIR)/opti_lst.c \
			  $(SRC_DIR)/opti_lst_utils.c

OBJ			= ${SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o}

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: banner $(LIBFT_A) $(NAME)

$(NAME): progress_bar_project $(OBJ)
	@$(CC) $(CFLAGS) -I$(INC_DIR) $(OBJ) $(LIBFT_A) -o $(NAME)
	@echo "\r\033[2K$(CYAN)Compiled files: $(BOLD)$(GREEN)[OK]$(RESET)"
	@echo "$(BOLD) $(GREEN)\n         Project compiled successfully ✅$(RESET)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@printf "\r\033[2K$(CYAN)Compiled files: %s$(RESET)" "$<"
	@sleep 0.05

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT_A):progress_bar_libft
	@make -s -C $(LIBFT_DIR)
	@echo "\r\033[2K$(CYAN)Compiled files: $(BOLD)$(GREEN)[OK]\n$(RESET)"
	

clean:
	@make clean -s -C $(LIBFT_DIR)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(CYAN)2K\rObject files removed$(RESET)"

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

BOLD		= \033[1m
DIM			= \033[2m
SHINNY		= \033[5m

BANNER = \
"$(BOLD)$(ORANGE)\n\n  	          Compilation ...  $(RESET)\n"\

banner:
	@echo $(BANNER)

progress_bar_libft:	
	@total=30; \
	i=1; \
	printf "📚 $(BOLD)Libft$(RESET)  ["; \
	while [ $$i -le $$total ]; do \
		bar="$$(printf '█%.0s' $$(seq 1 $$i))"; \
		spaces=""; \
		if [ $$i -lt $$total ]; then \
			spaces="$$(printf ' %.0s' $$(seq 1 $$((total - i))))"; \
		fi; \
		pct=$$((i * 100 / $$total)); \
		printf "\r📚 $(BOLD)Libft$(RESET)  [$(DIM)$$bar$$spaces$(RESET)] Loading:%3d%%" $$pct; \
		sleep 0.02; \
		i=$$((i+1)); \
	done; \
	printf "\033[2K\r📚 $(BOLD)Libft$(RESET) %s [$(DIM)██████████████████████████████$(RESET)] \033[32mSuccess !\033[0m\n"

progress_bar_project:
	@total=30; \
	i=1; \
	printf "📝 $(BOLD)Project$(RESET) ["; \
	while [ $$i -le $$total ]; do \
		bar="$$(printf '█%.0s' $$(seq 1 $$i))"; \
		spaces=""; \
		if [ $$i -lt $$total ]; then \
			spaces="$$(printf ' %.0s' $$(seq 1 $$((total - i))))"; \
		fi; \
		pct=$$((i * 100 / $$total)); \
		printf "\r📝 $(BOLD)Project$(RESET) [$(DIM)$$bar$$spaces$(RESET)] Loading:%3d%%" $$pct; \
		sleep 0.02; \
		i=$$((i+1)); \
	done; \
	printf "\033[2K\r📝 $(BOLD)Project$(RESET) %s[$(DIM)██████████████████████████████$(RESET)] \033[32mSuccess !\033[0m\n"


.PHONY: all clean fclean re banner progress_bar_libft progress_bar_project

