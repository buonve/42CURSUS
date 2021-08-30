SRCS			= Account.cpp tests.cpp
OBJ				= $(SRCS:.cpp=.o)

CC				= g++
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -std=c++98 -g
NAME			= Account

%.o:			%.cpp
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
				$(RM) $(OBJ) $(OBJ_BONUS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

g:				fclean $(OBJS)
				$(CC) -g -o $(NAME) ${SRCS} ${LIBS} 

.PHONY:			all clean fclean re g