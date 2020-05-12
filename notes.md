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

| command | description          | example                         |
| ------- | -------------------- | ------------------------------- |
| nm      | list symbols         | nm lib.dll                      |
| file    | get file information | file lib.dll                    |
| as      | assembler            | as main.s                       |
| ld      | link                 | ld main.exe main.o              |
| ar      | to create static lib | ar crf libmain.a main.o stuff.o |


