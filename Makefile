


all: main.cpp
	mkdir -p bin
	g++ -pthread -o ./bin/main $^  

clean: 
	rm -rf bin

run: all
	./bin/main