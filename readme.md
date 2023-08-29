
![banner](meta/res/banner.png)
# Extended C library utility 

The extdc core library is made with care and is meant to simplify and improve C development.
It's meant to be easily portable to new architecture and os.
It was battle tested in the brutal-os, UEFI, barebone x86, risc-v, linux...

## Origin 

The extdc library was initially a utility library built for the [Brutal operating system project](github.com/brutal-org/brutal), 
we have decided to extract the library to make it usable for other C project. 

Because the library was exported from Brutal, we don't see the original contributors, I wanted to mention that @sleepy-monax did the majority 
of the code.

## Demo of its feature: 

### Formatting library 

The library has a formatting tool that doesn't allocate any memory, you can easily do: 

```c
#include <extdlib/io.h>
// ...
log$("hello {} n°{x}", "world", 10);
```

Here, we write to `stdout`, but you can easily use the `io` library to write to a file, memory, or 
anything else that can be casted to a `Writer`. 

### Result system 

The language manages errors in a modern way. 
Each function can return a result like: 
```c
typedef Result(Error, float) DivResult;

// we use this to reuse the same error between function, 
// and to make the library user know what error may be expected when calling the function 
#define DIVISION_BY_ZERO_ERROR make_error(ERR_KIND_INVALID_PARAMS, "b == 0")

DivResult safe_div(int a, int b)
{   
    if(b == 0){
        return ERR(DivResult, DIVISION_BY_ZERO_ERROR);
    } 
    return OK(HeapResult, a/b);
}
```

The result system benefits of `TRY` macros that can be used inside expressions:  

```c
MaybeError complicated_math_func()
{
    float c = TRY(MaybeError, safe_div(10, 0)); // would return from complicated_math_func and make the parent function handle the error 
    // ...
}
```

> Note: due to language limitation, we have to provide the return function type each time we call TRY and OK/ERR macros.

### Fibers / Coroutines : 

Our library provide the use of fibers (look like coroutine): 

```c
void* fiber_a(void* ctx){
    for(int i = 0; i < 100; i++){
        log$("fiber a: {}", i);
        fiber_yield();
    }
    return 0;
}

void* fiber_b(void* ctx){
    for(int i = 0; i < 100; i++){
        log$("fiber b: {}", i);
        fiber_yield();
    }
    return 0;
}

int main(){

    fiber_init_current();

    fiber_start_and_forget(fiber_a, NULL);
    fiber_start_and_forget(fiber_b, NULL);
    
    for(int i = 0; i < 100; i++){
        log$("main fiber: {}", i);
        fiber_yield();
    }
    return 0;
}
```

Would output: 
```yaml
main fiber: 0
fiber a: 0
fiber b: 0
main fiber: 1
// ...
```

### This is only the surface of the library 
Extdlib has a lot of different components meant to make the life easier: 

- `alloc`: allocation system
- `base`: the root of all the system 
- `cli`: abstraction of the terminal (clearing it, color changment)
- `codec`: tga, zlib ... extraction.
- `debug`: logging, and assertion 
- `ds`: various datastructures: ring, slot, vectors, maps, bitmaps...
- `fibers`: coroutines
- `gfx`: a rasterizer 
- `hash`: a hashing utility library 
- `input`: abstraction of the mouse and keyboard 
- `io`: file , channel, formatting... inspired by rust writer/reader
- `math`: a math utility library 
- `mem`: a memory utility library
- `parse`: a lexer and parser library
- `sync`: synchronization library 
- `task`: multitasking library 
- `tests`: a unit testing library 
- `text`: powerfull text manipulation (formatting, utf8, ...)
- `time`: take care of time
- `ui`: a pretty simple user interface library 

Everything is implemented in C and requires clang or gcc (need to use statement expression).

