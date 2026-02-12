NAME = megaphone
CC = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp \

OBJS = ${SRC:%.cpp=objects/%.o}

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

objects/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@$(RM) -rf objects

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re