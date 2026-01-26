# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2026/01/21 16:30:00 by tmarcos           #+#    #+#             #
#    Updated: 2026/01/21 16:30:00 by tmarcos          ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRC = ex00/megaphone.cpp
OBJ = $(SRC:.cpp=.o)

# COLORS
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
CYAN = \033[0;36m
RESET = \033[0m

all: $(NAME)
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@echo "$(CYAN)  ex00: Usage: ./megaphone <text>                                 $(RESET)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"

$(NAME): $(OBJ)
	@echo "$(GREEN)🚀 Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) ready!$(RESET)"

%.o: %.cpp
	@echo "$(YELLOW)📦 Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "$(RED)🧹 Cleaned object files.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)🗑️  Full clean done.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
