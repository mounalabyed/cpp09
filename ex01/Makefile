PROG = RPN

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

SRC =   main.cpp RPN.cpp

OBJ = $(SRC:.cpp=.o)
  
NAME = $(PROG)

all : $(NAME)

$(PROG) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(PROG) 
	

clean : 
	rm -rf $(OBJ) 

fclean : clean
	rm -rf $(PROG)

re : fclean all