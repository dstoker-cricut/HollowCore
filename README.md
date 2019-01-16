# HollowCore
A cross-platform and cross-language object system written in C11.

[![Build Status](https://travis-ci.org/HollowCore/HollowCore.svg?branch=master)](https://travis-ci.org/HollowCore/HollowCore)

# Build
* Requires cmake and C compiler

```bash
$ cd HollowCore
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Test
* Requires cmake and C compiler

```bash
$ cd HollowCore
$ mkdir build
$ cd build
$ cmake ..
$ make
$ make test
$ ctest --verbose
```

# Code Coverage
* Requires cmake, gcc or llvm, gcov, lcov, genhtml

```bash
$ cd HollowCore
$ mkdir build
$ cd build
$ cmake .. -DCOVERAGE=1
$ make coverage
$ open coverage/html/index.html
```
