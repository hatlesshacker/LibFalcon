# LibFalcon
<a href="https://madewithlove.org.in" target="_blank">Made with <span style="color: #e74c3c">&hearts;</span> in India</a>

[LibFalcon](https://github.com/hatlesshacker/LibFalcon/) is a simple (and incomplete) C library to be linked with Hobby Operating Syestem Kernels. Almost all essential functions required by kernels are provided. (memcpy, strlen, atoi, etc.) Also, Note that LibFalcon does NOT aim for any standard compliance (Even though a part of the Library is actually C99 compliant). Libfalcon is distributed under the BSD license; see the accompanying LICENSE file for more information.

## Features of LibFalcon

Apart from standard library functions, Libfalcon also has functions for low-level port I/O and reading from/writing to control registers. In later versions, more and more functions would make use of inline assembly and optimization measures, to make the code faster.

Textmode printing routines ( like puts(), cls() ) are provided as an addon, to help kernels print characters on screen just like normal C-programs.

## Can I use LibFalcon for commercial and Closed-Source projects?

Yes, use LibFalcon under the terms of the BSD license.

## Installation

### Building LibFalcon

For Installation of Libfalcon You should have:
1. a working copy of GCC. (6.0.0+ recommended.)
2. NASM. (tested with NASM version 2.09.10)
3. make

Go to the LibFalcon Project root directory and run `make clean`, just to be sure there are no stale object files. After that run `make`. If everything goes well and LibFalcon Compiles correctly, The build system will print "Build Successfull.". You'd see a directory named 'OUT' in the project root directory, which will house the 'libfalcon.a' library file (to be linked with your kernel source code's object files) and the 'includes/' directory which will serve as the standard includes directory containing all the reuired C headers.

## Using LibFalcon

See Documentation/how-to-use for mode information.
