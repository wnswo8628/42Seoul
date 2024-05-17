# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonseo <jonseo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 05:45:52 by jonseo            #+#    #+#              #
#    Updated: 2023/12/04 02:35:01 by jonseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ircserv
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Server.cpp Client.cpp Channel.cpp parsecommand.cpp \
		command/invite.cpp command/inviteOnlyMode.cpp command/join.cpp command/keyMode.cpp \
		command/kick.cpp command/limitMode.cpp command/mode.cpp \
		command/nick.cpp command/who.cpp \
		command/operatorMode.cpp command/part.cpp command/pass.cpp command/ping.cpp command/privmsg.cpp \
		command/quit.cpp command/topic.cpp command/topicMode.cpp command/user.cpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re