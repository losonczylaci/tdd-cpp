GTEST_INC = googletest/googletest/include
GMOCK_INC = googletest/googlemock/include
GTEST_LIB = $(libDir)/gtest/lib
GTEST_LIBS = $(wildcard $(libDir)/gtest/lib/*.a)

tests = ${wildcard $(testDir)/*.cpp}
testsObjects = $(patsubst $(testDir)/%.cpp, $(buildDir)/%.o, $(tests))
testsDependencies = $(patsubst $(testDir)/%.cpp, $(buildDir)/%.d, $(tests))

$(libDir)/gtest/lib/libgtest.a:
	mkdir -p $(libDir)/gtest
	cd $(libDir)/gtest && cmake ../../googletest/
	cd $(libDir)/gtest && make

-include $(testsDependencies)

$(buildDir)/%.o: $(testDir)/%.cpp
	@mkdir -p $(buildDir)
	@g++ -c -o $@ $(CXXFLAGS) $< -I$(GTEST_INC) -I$(GMOCK_INC) -Iinclude $(createDependencies) 
	@echo $@

$(buildDir)/testmain: $(testsObjects) $(GTEST_LIBS) $(sourceObjects) $(libDir)/gtest/lib/libgtest.a
	@mkdir -p $(buildDir)
	@g++ -o $@ $(CXXFLAGS) -L./$(GTEST_LIB) -lgmock_main -lgmock -lgtest_main -lgtest $(testsObjects) $(sourceObjects) -I$(GTEST_INC) -I$(GMOCK_INC)
	@echo $@

$(buildDir)/coverage.info: test
	@lcov --capture --directory ./ -o $@ -q $(lcovConfig)

$(buildDir)/coverageFilt.info: $(buildDir)/coverage.info
	@lcov --remove $(buildDir)/coverage.info -o $@ '*/googletest/*' '*/test/*' '*/7/*' -q $(lcovConfig)
