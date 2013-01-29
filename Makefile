.PHONY: all check clean
CC = $(CXX)
CXXFLAGS ?= -O2 -Wall -Werror -std=c++11
LDFLAGS ?= -Wl,-O1,--as-needed
all: check
check: test
	./test
test.o: test.cpp abandon-all-reason.h
clean:
	-rm test.o test
