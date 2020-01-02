# LibFalcon

[LibFalcon](https://github.com/hatlesshacker/LibFalcon) is a simple (and incomplete) C library to be linked with Hobby Operating System Kernels. Almost all essential functions required by kernels are provided. (memcpy, strlen, atoi, etc.) However, there are No math functions at this moment, but I'll accept pull requests :-) . Libfalcon is distributed under the BSD license; see the accompanying LICENSE file for more information.

[LibFalcon](https://github.com/hatlesshacker/LibFalcon/) is a simple (and incomplete) C library to be linked with Hobby Operating Syestem Kernels. Almost all essential functions required by kernels are provided. (memcpy, strlen, atoi, etc.) However, there are No math functions at this moment. Also, Note that LibFalcon does NOT aim for any standard compliance (Even though a part of the Library is actually C99 compliant). Libfalcon is distributed under the BSD license; see the accompanying LICENSE file for more information.

## Features of LibFalcon

Apart from standard library functions, Libfalcon also has functions for low-level port I/O and reading from/writing to control registers. In later versions, more and more functions would make use of inline assembly and optimization measures, to make the code faster.

## Can I use LibFalcon for commercial and Closed-Source projects?

Yes, use LibFalcon under the terms of the BSD license.

## Installation

### Building LibFalcon

For Installation of Libfalcon You should have:
1. a working copy of GCC. (6.0.0+ recommended.)
2. NASM. (tested with NASM version 2.09.10)
3. make

Go to the LibFalcon Project root directory and run `make clean`, just to be sure there are no stale object files. After that run `make all`. If everything goes well and LibFalcon Compiles correctly, The build system will print "Build Successfull." A file named 'libfalcon.a' should be located on the Project root directory. The library is now almost ready to be linked with your kernel.

## Using LibFalcon

After successful compilation, the project root folder should contain the `libfalcon.a` file. Link it with your object files to access the library.
