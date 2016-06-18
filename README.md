# LibFalcon

[LibFalcon](https://github.com/FlashySoft/LibFalcon/) is a simple (and incomplete) C library to be linked with Hobby Operating Syestem Kernels. Almost all essential functions required by kernels are provided. (memcpy, strlen, atoi, etc.) However, there are No math functions at this moment. The reason is that I am in 9th standard, and I do not have enough knowledge about math functions. Libfalcon is distributed under the BSD license; see the accompanying LICENSE file for more information.

## Features of LibFalcon

Apart from standard library functions, Libfalcon also has functions for low-level port I/O and reading from/writing to control registers. In later versions, more and more functions would make use of inline assembly and optimzation mesures, to make the code faster. Libfalcon also uses Durand Miller's Liballoc for kernel heap functions.

## Can I use LibFalcon for commercial and Closed-Source projects?

Yes, use LibFalcon under the terms of the BSD license.

## Installation

### Building LibFalcon

For Installation of Libfalcon You should have:
1. a working copy of GCC. (4.0.0+ recommended.)
2. NASM. (tested with NASM version 2.09.10)
3. make.

Go to the LibFalcon Project root directory and run `make clean`, just to be sure there are no stale object files. After that run `make all`. If everything goes well and LibFalcon Compiles correctly, The build system will print "Build Successfull." A file named 'libfalcon.a' should be located on the Project root directory. The library is now almost ready to be linked with your kernel.

Now you need to provide some functions yourself in your kernel, as LibFalcon relies on them. Without these 'hook functions', you may not be able to link the library with your kernel. (to disable LibAlloc support, run `make all with-liballoc=no`.) The functions are:

  + int liballoc_lock()
  + int liballoc_unlock()
  + void* liballoc_alloc(int)
  + int liballoc_free(void*,int)

See LibAlloc Documentation for information about these functions.

## Using LibFalcon

You can link the library with your kernel by running something like:
      `gcc -o mykernel -ffreestanding -nostdlib kernelobject1.o kernelobject2.o kernelobject3.o .... libfalcon.a`

NOTE: `gcc -o mykernel -ffreestanding -nostdlib kernelobject1.o kernelobject2.o kernelobject3.o .... -L./ -lfalcon` should also work, but is not tested.
