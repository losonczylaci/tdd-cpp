# CPP

Base C++ project for practicing TDD.

## Prerequisites

- Linux-based system (or WSL)
- See `./install.sh` for the rest.

## Production code

To build production code just call the following command

```console
make all
```

## Testing

This repo uses GTEST as it's testing framework. Test files should be added to the `./test` folder and should follow the `*.test.cpp` naming pattern.

To initiate build and run tests just call the following command

```console
make test
```

## Cpp standard

By default `c++11` is selected as cpp standard.
You may want to switch between cpp standards as you are experimenting cpp feature. You can override this value by specifying `STD` variable.

```console 
make all STD=c++14
```

> Note: Change of cpp standard will not trigger re-compilation. If you do change standard, consider running `clean` make target.

## IDE

I use VSCode as my text editor. I have configured two tasks, a default build task and a default test task. You may want to use them.
