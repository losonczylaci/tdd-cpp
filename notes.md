# Cpp notes

## gcc compliation process

![compliation process](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/images/GCC_CompilationProcess.png)

1. Preprocess

```console
g++ -E main.cpp > main.i
or
cpp main.cpp > main.i
```

2. Compilation

```console
g++ -S main.i
```

3. Assemble

```console
as main.s
or
g++ -c main.s
```

4. Link

```console
ld -o main main.o
```

## Commands

| command | description            | example                         |
| ------- | ---------------------- | ------------------------------- |
| nm      | list symbols           | nm lib.dll                      |
| file    | get file information   | file lib.dll                    |
| as      | assembler              | as main.s                       |
| ld      | link                   | ld main.exe main.o              |
| ar      | to create static lib   | ar crf libmain.a main.o stuff.o |
| ldd     | list dynamic libraries | ldd main.exe                    |


> Note: path to the lib has to be add to the `LD_LIBRARY_PATH` variable.
> For more info [see](https://stackoverflow.com/questions/5357869/error-while-loading-shared-libraries)


## Header guard

`#pragma` is not the standard way of adding header guared however it supported by most of the compilers.  
(see cpp advanced chapter 6: including files only once)


## useful tools

valgrind
drmempory
clang-tidy
