
STD      := c++11
WARNINGS := -Wall -Wextra -Wshadow -fsanitize=undefined
COVERAGE := --coverage
CXXFLAGS = -std=$(STD) -g $(COVERAGE) $(WARNINGS)

define createDependencies
-MMD -MF$(@:%.o=%.d) -MT$(@)
endef
