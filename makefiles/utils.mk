
CXXFLAGS = -g -O0 -Wall -pthread

define createDependencies
-MMD -MF$(@:%.o=%.d) -MT$(@)
endef