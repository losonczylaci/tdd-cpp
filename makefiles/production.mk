
sources = ${wildcard src/*.cpp}
sourceObjects = $(patsubst src/%.cpp, $(buildDir)/%.o, $(sources))
sourceDependencies = $(patsubst src/%.cpp, $(buildDir)/%.d, $(sources))

-include $(sourceDependencies)

$(buildDir)/%.o: src/%.cpp
	mkdir -p $(buildDir)
	g++ -c -o $@ $(CXXFLAGS) $< -Iinclude $(createDependencies)

$(buildDir)/main: main.cpp
	mkdir -p $(buildDir)
	g++ -o $@ $(CXXFLAGS) -Iinclude $^ -Wl,-Map,$@.map