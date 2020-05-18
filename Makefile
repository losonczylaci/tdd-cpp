


all: main.cpp lib
	@mkdir -p bin
	@g++ $< -Iinclude -L./lib -l rectangle -o ./bin/main

lib: 
	mkdir -p lib
	g++ -shared src/rectangle.cpp -Iinclude -o lib/librectangle.so

clean: 
	rm -rf bin
	rm -rf lib

run: all
	@./bin/main