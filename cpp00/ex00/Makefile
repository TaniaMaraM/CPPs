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

SRC = src/megaphone.cpp
OBJ = $(SRC:src/%.cpp=obj/%.o)

# COLORS
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
GRAY = \033[0;90m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)🚀 Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) ready!$(RESET)"
	@echo "$(GRAY)Usage: $(RESET)./megaphone <text>"

obj/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	@echo "$(GRAY)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) -r obj
	@echo "$(RED)🧹 Cleaned object files.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)🗑️ Fully cleaned everything.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
