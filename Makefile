CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC = main.cpp hashtable.cpp list.cpp parser.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = alpha-redis

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET).exe $(TARGET)
