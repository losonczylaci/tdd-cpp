
STD      := c++11

ifeq ($(OS),Windows_NT)
    WARNINGS :=
    COVERAGE :=
else
    WARNINGS := -Wall -Wextra -Wshadow -fsanitize=undefined
    COVERAGE := --coverage
endif

CXXFLAGS = -std=$(STD) -g $(COVERAGE) $(WARNINGS)

define createDependencies
-MMD -MF$(@:%.o=%.d) -MT$(@)
endef
