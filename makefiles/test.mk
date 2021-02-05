tests = ${wildcard $(testDir)/*.cpp}
testObjs = $(patsubst $(testDir)/%.cpp, $(buildDir)/%.o, $(tests))
testDeps = $(patsubst $(testDir)/%.cpp, $(buildDir)/%.d, $(tests))

-include $(testDeps)

$(buildDir)/testmain: $(sourceObjects) $(testObjs) $(buildDir)/gtest-all.o $(buildDir)/gtest_main.o
	@mkdir -p $(buildDir)
	@g++ -o $@ $^ $(CXXFLAGS)
	@echo $@

$(buildDir)/gtest_main.o: test/gtest/gtest_main.cc
	@mkdir -p $(buildDir)
	@g++ -o $@ -c $< $(CXXFLAGS) -Itest -DGTEST_HAS_PTHREAD=0
	@echo $@

$(buildDir)/gtest-all.o: test/gtest/gtest-all.cc
	@mkdir -p $(buildDir)
	@g++ -o $@ -c $< $(CXXFLAGS) -Itest -DGTEST_HAS_PTHREAD=0
	@echo $@

$(buildDir)/%.o: $(testDir)/%.cpp
	@mkdir -p $(buildDir)
	@g++ -c -o $@ $(CXXFLAGS) $< -Iinclude -Itest $(createDependencies) 
	@echo $@


$(buildDir)/coverage.info: test
	@lcov --capture --directory ./ -o $@ -q $(lcovConfig)

$(buildDir)/coverageFilt.info: $(buildDir)/coverage.info
	@lcov --remove $(buildDir)/coverage.info -o $@ '*/googletest/*' '*/test/*' '*/7/*' -q $(lcovConfig)