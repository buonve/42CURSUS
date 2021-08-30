SRCS			= ScavTrap.cpp ClapTrap.cpp main.cpp  
OBJ				= $(SRCS:.cpp=.o)

CC				= clang++
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -std=c++98 -g
NAME			= ScavTrap

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