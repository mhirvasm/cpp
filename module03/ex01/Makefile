# Program name
NAME      = inheritance
# Compiler and flags

CXX       = c++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++20

# Files
SRC       = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ       = $(SRC:.cpp=.o)

# Default
all: $(NAME)

# Linking
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Compile
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cleanup
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re