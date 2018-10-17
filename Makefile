HOST=
CPP:=$(HOST)g++

all: main.cpp logs.so
	$(CPP) main.cpp -L. ./logs.so -o main -g

logs.so:logs.cpp logs.h
	$(CPP) logs.cpp -fPIC -shared -o logs.so -g