OS := $(shell uname)

ifeq ($(OS),Linux)
    CLANG-TIDY := clang-tidy
else
    CLANG-TIDY := clang-tidy-9
endif

lcovConfig := --config-file .lcovrc
