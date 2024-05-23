# XM23p Loader and Memories

This repository contains the XM23p loader for ECED 3403 – Computer Architecture at Dalhousie University. The loader reads XM23p executable files in S-Record format, loading them into the Harvard architecture-based instruction (IMEM) and data memories (DMEM), with memory display functionality.

## Features

- Load XM23p executable files in S-Record format.
- Load data into 64 KiB word-addressable instruction memory (IMEM).
- Load data into 64 KiB byte-addressable data memory (DMEM).
- Display the contents of IMEM and DMEM.

## Requirements

- C compiler (e.g., GCC)
- Make (optional, for build automation)

## Files

- `loader.c`: Main source code for the XM23p loader.
- `Makefile`: Makefile for building the project (optional).

## Usage

1. **Compile the code:**

    ```sh
    gcc -o xm23p_loader loader.c
    ```

    Alternatively, if you are using the provided `Makefile`:

    ```sh
    make
    ```

2. **Run the loader:**

    ```sh
    ./xm23p_loader <path_to_xme_file>
    ```

    Replace `<path_to_xme_file>` with the path to your XM23p executable file in S-Record format.

## Example

```sh
./xm23p_loader program.xme
