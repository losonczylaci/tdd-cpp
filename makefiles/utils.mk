
CXXFLAGS = -g -o0 -Wall -pthread

define createDependencies
-MMD -MF$(@:%.o=%.d) -MT$(@)
endef