
STD := c++11

WARNINGS = -Wall -Wextra -Wshadow -fsanitize=undefined
CXXFLAGS = -std=$(STD) -g -O0 -pthread --coverage $(WARNINGS)

define createDependencies
-MMD -MF$(@:%.o=%.d) -MT$(@)
endef
