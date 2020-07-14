
STD := c++11

CXXFLAGS = -std=$(STD) -g -O0 -Wall -pthread --coverage

define createDependencies
-MMD -MF$(@:%.o=%.d) -MT$(@)
endef
