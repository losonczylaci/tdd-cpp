
STD := c++11

# WARNINGS = -Wall -Wextra -Wshadow -fsanitize=undefined
# CXXFLAGS = -std=$(STD) -g -O0 -pthread --coverage $(WARNINGS)
WARNINGS = 
CXXFLAGS = -std=$(STD) -g -O0 

define createDependencies
-MMD -MF$(@:%.o=%.d) -MT$(@)
endef
