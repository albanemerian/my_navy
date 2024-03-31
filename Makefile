##
## EPITECH PROJECT, 2023
## my_organize
## File description:
## my_organize
##

CC	=	gcc

NAME	=	my_navy

UNIT_TEST	= test

CFLAGS	=	-Wshadow -Werror -Wall -I./include

CRITFLAG	= --coverage -lcriterion

LIBS	=	-L./ -lmy

TEST_LIBS	=	-L./ -lmy

SRC		=	main.c				\
			helper.c 			\
			init_board.c		\
			check_file.c		\
			attack.c			\
			maps_attack.c		\
			lose_condition.c	\
			main_extended.c		\
			handler.c			\
			send_pos.c

SRC_TEST	=	helper.c 		\
				init_board.c	\
				check_file.c	\
				attack.c		\
				maps_attack.c	\
				handler.c		\
				main_extended.c

TEST	=	tests/test_printf.c	\
			tests/test_main.c

OBJ		=	$(SRC:.c=.o)

all:	libmy $(NAME)

$(NAME):	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)
			@echo -e "\e[1;32m{ Makefile is ready }\e[00;37m"
			@echo -e "\e[1;36m{ Binary is ready }\e[00;37m"

.PHONY: libmy

libmy:
	$(MAKE) -C lib/my

$(UNIT_TEST): fclean all
	$(CC) -o $(UNIT_TEST) $(SRC_TEST) $(TEST) $(CRITFLAG) $(TEST_LIBS)

tests_run: $(UNIT_TEST)
	@./$(UNIT_TEST)
	@gcovr --exclude tests/

clean:
			$(MAKE) -C lib/my clean
			@rm -f $(OBJ)
			@rm -f *.gc*
			@rm -f coding-style-reports.log
			@rm -f *~
			@rm -f *.gcda
			@rm -f *.gcno
			@rm -f libmy.a
			@rm -f my_navy
			@rm -f test

fclean:	clean
			$(MAKE) -C lib/my fclean
			@rm -f $(NAME)
			@rm -f $(UNIT_TEST)
			@echo -e "\e[1;33m{ REPOSITORIE as been cleaned }\e[00;37m"


re:	fclean all
