NAME = RPN

CXX= c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

SRC = main.cpp    RPN.cpp\

HDR =   RPN.hpp\

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)  $(HDR)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.SECONDARY: $(OBJ)