# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 11:38:55 by lincerpi          #+#    #+#              #
#    Updated: 2021/04/08 14:43:00 by vbuonvin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libasm.a
AS		= @nasm
ASFLAGS	= -f macho64
SRCS	= ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s
OBJS	= $(SRCS:.s=.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all 

test:
	make
	gcc main.c $(NAME)
	./a.out
	rm -rf ./a.out
	make fclean
	
test_tripouille: 
	make
	git clone https://github.com/Tripouille/libasmTester.git
	cd libasmTester && make m
	rm -rf libasmTester
	make fclean

.PHONY: all clean fclean re test_tripouille