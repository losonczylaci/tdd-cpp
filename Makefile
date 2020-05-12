


all: main.cpp rectlib
	@mkdir -p bin
	g++ $< lib/rectlib.a -o ./bin/main

rectlib: 
	mkdir -p lib
	g++ -c include/rectangle.cpp -o lib/rectangle.o
	ar crf lib/rectlib.a lib/rectangle.o

clean: 
	rm -rf bin
	rm -rf lib

run: all
	./bin/main