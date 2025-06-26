# Debugging Memory Leaks and Fragmentation

## Overview

This project demonstrates how to detect and analyze memory leaks in a C++ program using **AddressSanitizer (ASan)**. It deliberately introduces memory leaks to test detection capabilities on **Linux (Ubuntu)** with both `gcc` and `clang` compilers.

## Problem Description

Memory leaks occur when dynamically allocated memory is not freed. Over time, these leaks can cause programs to consume increasing amounts of memory, leading to performance degradation or crashes. This project allocates memory in a loop without freeing it, simulating a typical leak scenario.

The workflow is configured to:

* Build and run the project with ASan enabled.
* Detect memory leaks.
* **Fail** the workflow if **no leak** is detected (to ensure the tool is actually working).

## Example Output

```
ERROR: LeakSanitizer: detected memory leaks
Direct leak of 400000 byte(s) in 1000 object(s) allocated from:
  #0 0x55dd2c62b7aa in operator new[](unsigned long) ...
  #1 0x55dd2c62b92f in leak_memory() ...
  #2 0x55dd2c62b96d in main ...
```

## Explanation of Output

* **Direct leak**: memory allocated by `new int[100]` is never deleted.
* `LeakSanitizer` identifies the source of the leak with a full stack trace.
* The workflow treats this as a successful test because it confirms a leak exists.

## How to Compile and Run

### 1. Clone the Repository

```bash
git clone https://github.com/LyudmilaKostanyan/Debugging-Memory-Leaks.git
cd Debugging-Memory-Leaks
```

### 2. Build the Project (with Clang)

```bash
cmake -S . -B build \
  -DCMAKE_C_COMPILER=clang \
  -DCMAKE_CXX_COMPILER=clang++ \
  -DCMAKE_CXX_FLAGS="-fsanitize=address -g -O1" \
  -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

### 3. Run the Program

```bash
./build/memory_leak
```

You should see the AddressSanitizer report printed to your terminal if leaks are present.

## Note

* The GitHub Actions workflow is configured to **fail if no leaks are found**, and **pass if leaks are detected**.
