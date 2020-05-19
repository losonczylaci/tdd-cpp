
SRCS = ${wildcard src/*.cpp}
SRC_OBJS = $(patsubst src/%.cpp, bin/%.o, $(SRCS))

TESTS = ${wildcard test/*.cpp}
TEST_OBJS = $(patsubst test/%.cpp, bin/%.o, $(TESTS))

GTEST_INC = googletest/googletest/include
GTEST_LIB = lib/gtest/lib
GTEST_LIBS = $(wildcard lib/gtest/lib/*.a)

CXXFLAGS = -g -Wall -pthread

start: all
	@./bin/main

all: bin/main

bin/main: main.cpp $(SRC_OBJS)
	g++ -o $@ $(CXXFLAGS) -Iinclude $^

clean: 
	rm -rf bin
	rm -rf lib

test: bin/testmain
	@./bin/testmain

lib/gtest/lib/libgtest.a:
	mkdir -p lib/gtest
	cd lib/gtest && cmake ../../googletest/
	cd lib/gtest && make

bin/testmain: $(TEST_OBJS) $(GTEST_LIBS) $(SRC_OBJS) lib/gtest/lib/libgtest.a
	mkdir -p bin
	g++ -o $@ $(CXXFLAGS) -L./$(GTEST_LIB) -lgtest_main -lgtest $(TEST_OBJS) $(SRC_OBJS) -I$(GTEST_INC)

bin/%.o: src/%.cpp
	mkdir -p bin
	g++ -c -o $@ $(CXXFLAGS) $< -Iinclude

bin/%.o: test/%.cpp
	mkdir -p bin
	g++ -c -o $@ $(CXXFLAGS) $< -I$(GTEST_INC) -Iinclude