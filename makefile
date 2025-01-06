
CXX = g++

CXXFLAGS = -Wall -std=c++11

TARGET = sieve_program

SRCS = main.cpp sieve.cpp

OBJS = main.o sieve.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp sieve.h
	$(CXX) $(CXXFLAGS) -c main.cpp

sieve.o: sieve.cpp sieve.h
	$(CXX) $(CXXFLAGS) -c sieve.cpp

clean:
	rm -f $(OBJS) $(TARGET)