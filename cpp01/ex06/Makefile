# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/28 14:30:57 by tmarcos           #+#    #+#              #
#    Updated: 2026/01/28 19:28:14 by tmarcos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlfilter
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -I include
RM = rm -f

SRC = src/main.cpp \
	  src/Harl.cpp

OBJ = $(SRC:%.cpp=obj/%.o)

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
GRAY = \033[0;90m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)🚀 Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) ready!$(RESET)"
	@echo "$(GRAY)Usage: $(RESET)./harlfilter <level>"

obj/%.o: %.cpp
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
