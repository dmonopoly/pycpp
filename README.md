## What
Example of how to call C++ code from Python.

## How
### Compiling / Preparation
Create an object file from the C++. Pass -c so we don't run the linker and our
output is just the object file(s) from the assembler:

    g++ -c foo.cpp -o foo.o

Create a shared object file (.so) by passing the object file (.o) from above as
input:

    g++ -shared foo.o -o libfoo.so

### Running

    python foo_wrapper.py

or

    python main.py

You should see output with "Hello" printed from the C++ method.

## Misc.
### Source and discussion
http://stackoverflow.com/questions/145270/calling-c-c-from-python
