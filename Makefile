################################################################################
# FileName: Makefile
# Author: Minho
# Create: 17/10/2018
# Edit:
# V0.1		17/10/2018	-Initial Version
###############################################################################

HOST=
CPP:=$(HOST)g++

all: main.cpp logs.so
	$(CPP) main.cpp -L. ./logs.so -o main -g

logs.so:logs.cpp logs.h
	$(CPP) logs.cpp -fPIC -shared -o logs.so -g