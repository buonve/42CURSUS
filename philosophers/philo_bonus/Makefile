#Name
NAME =			philo_bonus

#Compiler
CC = 			gcc
CFLAGS = 		-Wall -Wextra -Werror -g #-fsanitize=address

#Norm
NORM =			norminette

#Shell
MKDIR =			mkdir -p
RM =			rm -rf

#Directories
SRCDIR = 		./srcs
OBJDIR =  		./objs
INCDIR = 		.

FILES =			main.c				\
				parser.c			\
				ft_isdigit.c		\
				ft_atoi.c			\
				utils.c				\
				init_everything.c	\
				table.c				\
				actions.c			\
				ft_strdup.c			\
				ft_strlen.c			\
				ft_strlcpy.c		\
				ft_calloc.c

#Srcs
SRCS = 			$(foreach FILE, $(FILES), $(shell find $(SRCDIR) -name $(FILE)))

#Objs
OBJS = 			$(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SRCS:.c=.o))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(@D)
	@$(CC) $(CFLAGS) -I $(INCDIR) -c -o $@ $<

all: $(NAME) run

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

norminette:
	@$(NORM)

clean:
	@$(RM) $(OBJDIR) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all norminette clean fclean run re