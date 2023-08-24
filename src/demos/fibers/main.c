#include "extdlib/fibers/fibers.h"
#include <extdlib/fibers.h>
#include <extdlib/debug.h>


void* fiber_a(void*)
{
    for(int i = 0; i < 100; i++)
    {
        log$("fiber a: {}", i);
        fiber_yield();
    }
    return 0;
}
void* fiber_b(void*)
{
    for(int i = 0; i < 100; i++)
    {
        log$("fiber b: {}", i);
        fiber_yield();
    }
    return 0;
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    log$("fiber start");

    fiber_init_current();

    fiber_start_and_forget(fiber_a, NULL);
    fiber_start_and_forget(fiber_b, NULL);
    
    for(int i = 0; i < 100; i++)
    {
        log$("main fiber: {}", i);
        fiber_yield();
    }
    return 0;
}
