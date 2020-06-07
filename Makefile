buildDir := build
libDir := lib

include makefiles/tools.mk
include makefiles/utils.mk
include makefiles/production.mk
include makefiles/test.mk

start: all
	@./$(buildDir)/main

all: $(buildDir)/main

clean: 
	rm -rf $(buildDir)

cleanlib:	
	rm -rf $(libDir)

test: $(buildDir)/testmain
	@echo -e "\nRunning unit-tests..."
	@./$(buildDir)/testmain

qa: memcheck lint

memcheck: $(buildDir)/testmain
	valgrind --leak-check=yes $(buildDir)/testmain

lint: 
	@echo -e "\nRunning linter..."
	$(CLANG-TIDY) --header-filter='.*' $(sources) -- -Iinclude

