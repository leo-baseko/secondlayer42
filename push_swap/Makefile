NAME =			push_swap

RM =			rm -rf
CC =			gcc
FLAGS =			-Wall -Werror -Wextra

INCLUDE =		push_swap.h \

SRC =			push_swap.c \

SRCS =			$(SRC)
OBJS =			$(addsuffix .o, $(basename $(SRC)))

INCS =			$(addprefix -I, $(INCLUDE))

all :			$(NAME)

$(NAME) :		$(OBJS)
					ar rcs $@ $^

clean :
				$(RM) $(OBJS)

fclean :		clean
					$(RM) $(NAME)

re :			fclean all

.c.o:			$(SRCS)
					$(CC) -c -o $@ $< $(FLAGS)

.PHONY: all clean fclean re bonus