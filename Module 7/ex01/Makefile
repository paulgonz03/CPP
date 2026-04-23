NAME = templates
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

OBJS = ${SRC:%.cpp=objects/%.o}

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling..."
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "Build complete!"

objects/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) -rf objects

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re