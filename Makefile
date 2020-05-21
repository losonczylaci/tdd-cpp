buildDir = build
libDir = lib

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
	@echo "\nRunning unit-tests..."
	@./$(buildDir)/testmain

qa: test lint

lint: 
	@echo "\nRunning linter..."
	clang-tidy-9 --checks='*,-modernize-use-trailing-return-type' --header-filter='.*' $(sources) -- -Iinclude

