
# Brutal core library 

The brutal core library is made with care and is meant to simplify and improve C development.
It's meant to be easily portable to new architecture and os.
It was battle tested in the brutal-os, UEFI, barebone x86, risc-v, linux...

It has a lot of different components meant to make the life easier: 

- alloc: allocation system
- base: the root of all the system 
- cli: abstraction of the terminal (clearing it, color changment)
- codec: tga, zlib ... extraction.
- debug: logging, and assertion 
- ds: various datastructures: ring, slot, vectors, maps, bitmaps...
- fibers: coroutines
- gfx: a rasterizer 
- hash: a hashing utility library 
- input: abstraction of the mouse and keyboard 
- io: file , channel, formatting...
- math: a math utility library 
- mem: a memory utility library
- parse: a lexer and parser library
- sync: synchronization library 
- task: multitasking library 
- tests: a unit testing library 
- text: powerfull text manipulation (formatting, utf8, ...)
- time: take care of time
- ui: a pretty simple user interface library 

Everything is implemented in C and requires clang or gcc (need to use statement expression).

