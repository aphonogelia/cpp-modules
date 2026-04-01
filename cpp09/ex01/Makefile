# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 12:40:32 by htharrau          #+#    #+#              #
#    Updated: 2026/04/01 15:26:29 by htharrau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
	
SRCS = main.cpp RPN.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 

-include $(DEPS)

%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re