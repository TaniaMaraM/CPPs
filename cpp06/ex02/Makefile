# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/02 11:07:28 by tmarcos           #+#    #+#              #
#    Updated: 2026/04/08 21:51:31 by tmarcos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = identify
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -I include
RM = rm -f

SRC_DIR = src
OBJ_DIR = obj

SRC = main.cpp \
      Base.cpp \
      functions.cpp

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
