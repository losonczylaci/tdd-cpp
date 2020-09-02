# CPP

Base C++ project for practicing TDD.

## Prerequisites

- Linux-based system (or WSL)
- See [Dockerfile](./Dockerfile) for the rest.

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

## VSCode

I use VSCode as my text editor and I highly encourage you to do the same.
I have checked in my configurations, just in case you want to use them:

- `launch.json` - which contains the configuration for debugging
- `task.json`- which defines build tasks ( unit-test task and a generic build task )

### Tasks

You can access these tasks by:

- hit `CTRL+P`
- hit `Space` and type `task`
- you can choose from the drop down list

### Docker

There is a cool VSCode exention that allows development inside a container.
You may want to check that out, it is pretty cool.
