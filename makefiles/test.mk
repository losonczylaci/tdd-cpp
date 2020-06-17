GTEST_INC = googletest/googletest/include
GMOCK_INC = googletest/googlemock/include
GTEST_LIB = $(libDir)/gtest/lib
GTEST_LIBS = $(wildcard $(libDir)/gtest/lib/*.a)

tests = ${wildcard test/*.cpp}
testsObjects = $(patsubst test/%.cpp, $(buildDir)/%.o, $(tests))
testsDependencies = $(patsubst test/%.cpp, $(buildDir)/%.d, $(tests))

$(libDir)/gtest/lib/libgtest.a:
	mkdir -p $(libDir)/gtest
	cd $(libDir)/gtest && cmake ../../googletest/
	cd $(libDir)/gtest && make

-include $(testsDependencies)

$(buildDir)/%.o: test/%.cpp
	mkdir -p $(buildDir)
	g++ -c -o $@ $(CXXFLAGS) $< -I$(GTEST_INC) -I$(GMOCK_INC) -Iinclude $(createDependencies) 

$(buildDir)/testmain: $(testsObjects) $(GTEST_LIBS) $(sourceObjects) $(libDir)/gtest/lib/libgtest.a
	mkdir -p $(buildDir)
	g++ -o $@ $(CXXFLAGS) -L./$(GTEST_LIB) -lgmock_main -lgmock -lgtest_main -lgtest $(testsObjects) $(sourceObjects) -I$(GTEST_INC) -I$(GMOCK_INC)
