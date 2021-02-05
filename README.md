# CPP

Base C++ project for practicing TDD.

## OS

- Linux-based system (or WSL)
- See [Dockerfile](./Dockerfile) for the rest.

### Linux users

Docker config is provided. In case you are not familiar with Docker, take a look into the `./Dockerfile` and you can install the required tools manually.

### Windows users

Many targets (such as `memcheck`, `coverage`... etc.) are not supported by default. Also, make sure path to the compiler is added to the `PATH` environment variable.
If you don't want to mess with your `PATH` variable just update the compiler path (if necessary) in the `./build.bat` and you can invoke targets using it.

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

### Docker

There is a cool VSCode exention that allows development inside a container.
You may want to check that out, it is pretty cool.
