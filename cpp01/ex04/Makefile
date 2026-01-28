# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/28 14:30:57 by tmarcos           #+#    #+#              #
#    Updated: 2026/01/28 19:05:11 by tmarcos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES =
RM = rm -f

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
GRAY = \033[0;90m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)🚀 Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) ready!$(RESET)"
	@echo "$(GRAY)Usage: $(RESET)./replace <filename> <s1> <s2>"

make%.o: %.cpp
	@echo "$(GRAY)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "$(RED)🧹 Cleaned object files.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)🗑️ Fully cleaned everything.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
