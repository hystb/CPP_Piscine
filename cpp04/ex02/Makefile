#---------------------------------------------------#
CC 			= c++

CFLAGS 		= -Wall -Wextra -Werror -std=c++98

NAME 		= AA
#---------------------------------------------------#
SRCS		= \
main.cpp\
Dog.cpp\
Cat.cpp\
AAnimal.cpp\
WrongCat.cpp\
WrongAnimal.cpp\
Brain.cpp\

OBJ_DIR 	= .obj

OBJS		= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

HEADERS		= \
Dog.hpp\
Cat.hpp\
AAnimal.hpp\
WrongCat.hpp\
WrongAnimal.hpp\
Brain.hpp\
#---------------------------------------------------#
all:
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:	fclean
	$(MAKE) all

.PHONY: all clean fclean re
#---------------------------------------------------#
