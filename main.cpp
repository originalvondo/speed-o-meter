#include <iostream>
#include <profiler.h>
#include <thread>

void func1() 
{
    // telling the compiler to profile this function coz why not
    PROFILE_FUNCTION();
    // dummy loop
    for (int i = 0; i < 1000; i++) std::cout << "function 1\n";
}

void func2() 
{
    // telling the compiler to profile this function coz why not
    PROFILE_FUNCTION();
    // dummy loop 2
    for (int i = 0; i < 1000; i++)
        std::cout << "function 2\n";
}

void profile() 
{
    // telling the compiler to profile this function coz why not
    PROFILE_FUNCTION();
    // running the previous functions for profiling
    std::thread a([]() { func1(); } );
    std::thread b([]() { func2(); } );

    a.join();
    b.join();
}

int main() {
    // begin the benchmarking session
    BEGIN_PROFILE_SESSION("profile.json");

    std::thread c([]() { profile(); });
    c.join();

    // end the benchmarking session
    END_PROFILE_SESSION();
    return 0;
}