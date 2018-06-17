# Toy Test

This is a simple, quick-building unit test framwork. It doesn't have
all of the features of other frameworks, but it's also only a couple
pages of code.

## Usage:
To compile under Linux or Cygwin:

```bash
mkdir build
cd build
cmake .. && make test
```

To do this under mingw-w64/msys2, you need to change the commands to:

```bash
mkdir build
cd build
cmake .. -G'Unix Makefiles' && make test
```

To create a test suite, you do something like this:

```C++
#include "toy_test.hpp"

toy_test::suite example_suite {
    "test suite name to display to the user",
    {
      { "name of this test",
         []{ code_to_actually_do_the_test; }},
      { "name of another test",
         []{ code_to_test_the_second_thing; }},
     }};

int main(){
    toy_test::run_suites({example_suite, another_suite});
}
```

There are two macros you can use to assert something:
```C++
ASSERT(exp); // checks to make sure that exp is a true expression
THROWS(exp, exception_name); // checks to make sure that exception_name
 	    		     // is thrown when exp is evaluated
```

See demo.cpp, leap_year.hpp, and factorial.hpp for examples.

## License ![CC0](https://licensebuttons.net/p/zero/1.0/88x31.png)

This work is licensed under the terms of the CC0-1.0 Universal
license, or may be considered to be in the public domain,
at your option.
