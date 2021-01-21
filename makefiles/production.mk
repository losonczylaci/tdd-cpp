
sources = ${wildcard src/*.cpp}
sourceObjects = $(patsubst src/%.cpp, $(buildDir)/%.o, $(sources))
sourceDependencies = $(patsubst src/%.cpp, $(buildDir)/%.d, $(sources))

-include $(sourceDependencies)

$(buildDir)/%.o: src/%.cpp
	@mkdir -p $(buildDir)
	@g++ -c -o $@ $(CXXFLAGS) $< -Iinclude $(createDependencies)
	@echo $@

$(buildDir)/main: main.cpp $(sourceObjects)
	@g++ -o $@ $(CXXFLAGS) -Iinclude $^
	@echo $@
