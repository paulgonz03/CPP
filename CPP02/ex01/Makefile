NAME = fixed
CXX = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Fixed.cpp main.cpp\

OBJS = ${SRC:%.cpp=objects/%.o}

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CCFLAGS) $(OBJS) -o $(NAME)

objects/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CXX) $(CCFLAGS) -c $< -o $@
clean:
	@$(RM) -rf objects

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re