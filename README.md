# cmaster

A step-by-step path from C fundamentals to systems and embedded engineering.

## How to work

Each lesson lives in its own folder. Every lesson is a set of exercises with
TODO stubs and an automatic test harness. Implement the functions, then run:

```sh
make run L=01-pointers-and-memory
```

Builds use strict warnings plus AddressSanitizer and UBSan, so memory errors
and undefined behavior are caught at runtime.

## Roadmap

### Phase 1: C foundations

| # | Topic | Status |
|---|---|---|
| 01 | Pointers, arrays and structs in functions, `malloc`, dynamic arrays | ⏳ |
| 02 | Strings and character arrays | |
| 03 | File I/O | |
| 04 | Multi-file projects, headers, `static`, Makefiles | |
| 05 | Bit manipulation: masks, flags, register-style code | |
| 06 | Function pointers and callbacks | |
| 07 | Data structures: linked list, stack, queue, ring buffer, hash table | |
| 08 | Debugging with `gdb`, undefined behavior | |

### Phase 2: Engineering in C

| # | Topic | Status |
|---|---|---|
| 09 | Modular design: opaque types, interfaces, error handling | |
| 10 | Unit testing and build systems (Unity, CMake) | |
| 11 | State machines | |
| 12 | Binary protocols: endianness, framing, checksums/CRC, parsers | |
| 13 | Project: a small serial protocol library | |

### Phase 3: Choose a track (decided after Phase 2)

- **Embedded:** microcontrollers (STM32), GPIO/UART/I2C/SPI, interrupts, DMA, FreeRTOS
- **Systems (POSIX):** processes, signals, threads, sockets, a mini shell
- **C++ and architecture:** classes, RAII, modern C++, design patterns, large-scale design
