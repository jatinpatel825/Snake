CPP = g++
CPPFLAGS = -std=c++11

all: snake

snake: main.cc
	$(CPP) $(CPPFLAGS) GetKey.cc Food.cc Snake.cc BaseClass.cc -lpthread -o snek $^
