# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/30 18:54:36 by tmarcos           #+#    #+#              #
#    Updated: 2026/01/30 18:58:12 by tmarcos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = DiamondTrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -I include
RM = rm -f

SRC_DIR = src
OBJ_DIR = obj

SRC = main.cpp \
	  ClapTrap.cpp \
	  ScavTrap.cpp \
	  FragTrap.cpp \
	  DiamondTrap.cpp \

OBJ = $(SRC:%.cpp=obj/%.o)

GREEN = \033[0;32m
RED = \033[0;31m
GRAY = \033[0;90m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)🚀 Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) ready!$(RESET)"
	@echo "$(GRAY)Usage: $(RESET)./$(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(GRAY)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(RED)🧹 Cleaned object files.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)🗑️  Fully cleaned everything.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
