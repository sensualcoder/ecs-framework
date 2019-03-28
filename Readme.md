# ECS-Framework

Requires no external libraries

## Build
To build, create a build directory
> $ mkdir build

Use cmake to configure and make to build
> $ cmake ..

> $ make

This should result in the libECS.a library being built in the ECS subfolders

## Build driver program
If you want to build the driver program to test the framework, build and run with the following commands:
> $ cmake -DBUILD=DRIVER=On ..

> $ make

> $ ./ECSDriver
