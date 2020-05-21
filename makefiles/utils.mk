
CXXFLAGS = -g -Wall -pthread

define createDependencies
-MMD -MF$(@:%.o=%.d) -MT$(@)
endef