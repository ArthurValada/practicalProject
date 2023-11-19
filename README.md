# Practical Project

## Introduction

This project is a requirement of the Computer Science curriculum, in the subject of Introduction to Algorithms,
from the Federal University of Lavras, Brazil. The activity was proposed to us so that the students in each group, composed of
by 3 people, could choose, even if in a conflicting way, the subject they would address.

The subject that this group chose to address deals with Plants, meeting, in principle, the following requirements:

- Reading and writing CSV and binary files;
- Search;
- Amendment;

In order to meet the minimum requirements of what was called _checkpoint_, the search methods used are, up to the
present moment, linear. Later it will be necessary to add a binary search process and ordering of the
file contents into a vector, using smart sorting algorithms based on at least two fields.

## Group members.

The group members are:
 
- Arthur Valadares Campideli;
- Hugo Prado Lima;
- Gustavo Henrique Marinho Carvalho;

All members belong to the Introduction to Algorithms class, class **10A**.

To access the project source code, visit: https://github.com/ArthurValada/practicalProject

## Git

If you want to clone the project so that you have it on your machine, you can do so using git:
```git
git clone https://github.com/ArthurValada/practicalProject.git
```

## Requirements

C/C++: 12.2.0
Cmake minimum version required: 3.26
Ninja version: 1.10.1

Recommend: GCC 12.2.0

## How to compile

### Load Cmake
```cmake
 cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_MAKE_PROGRAM=/path/to/ninja -DCMAKE_C_COMPILER=/usr/bin/cc -DCMAKE_CXX_COMPILER=/usr/bin/c++ -G Ninja -S /path/to/practicalProject -B /path/to/practicalProject/cmake-build-release
```
### Build

```cmake
cmake --build /path/to/directory/practicalProject/cmake-build-release --target practicalProject -j 6
```

Alternativamente, você também pode ver a seção release do reposítório no github

### Run
Inside cmake-build-release will be the executable called practicalProject, run it.