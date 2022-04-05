all: MEMORY_THREAD MEMORY_SPEED

_INCLUDE = $(shell pwd)/../../memory_pool.cpp

MEMORY_THREAD: memory_thread.cpp 
	g++ -g -o memory_thread memory_thread.cpp $(_INCLUDE) -std=c++11 -lpthread

MEMORY_SPEED: memory_speed.cpp
	g++ -g -o memory_speed memory_speed.cpp $(_INCLUDE) -std=c++11 -lpthread

clear:
	rm -rf memory_thread memory_speed
