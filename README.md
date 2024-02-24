# Speed-o-meter: C++ Profiler

Speed-o-meter is a lightweight and easy-to-use profiler for C++ code. It allows developers to profile their C++ applications and analyze their performance using Chrome Tracing.


## How it works

To use Speed-o-meter, simply add `PROFILE_FUNCTION();` at the start of every function you want to profile. This macro instruments the function to measure its execution time.

To begin profiling, use `BEGIN_PROFILE_SESSION(filepath);` at the start of the `main` function. This starts a profiling session and specifies the filepath where the profiling data will be saved.

To end the profiling session, use `END_PROFILE_SESSION();` at the end of the `main` function. This stops the profiling session and saves the collected data to the specified filepath.

If the functions being profiled are in separate threads, Speed-o-meter will also show thread information in Chrome Tracing.


## Viewing the results

Speed-o-meter outputs profiling data in JSON format, which can be viewed using Chrome Tracing. Simply load the generated JSON file into Chrome Tracing to visualize and analyze the performance of your C++ application.


## Usage example

```cpp
#include <profiler.h>

void myFunction() {
    PROFILE_FUNCTION();
    // Code to profile
}

int main() {
    BEGIN_PROFILE_SESSION("profile.json");
    // Code
    myFunction();
    // More code
    END_PROFILE_SESSION();
    return 0;
}
```


## Requirements:

- C++ compiler
- Google Chrome (for viewing profiling data in Chrome Tracing)


## Installation:

Simply include the `profiler.h` header file in your C++ project and link to the `profiler` library to start using Speed-o-meter.

```cmake
add_library(profiler STATIC src/profiler.cpp)
target_include_directories(profiler PUBLIC Includes)
```


## Contributing:

Contributions are welcome! If you encounter any issues or have suggestions for improvements, please open an issue or submit a pull request.


## License:

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
