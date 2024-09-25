
---

# get_next_line

## Description

`get_next_line` is a C function that reads a line from a file descriptor, enabling the user to retrieve one line at a time from files or standard input. This project focuses on efficient memory management and dynamic memory allocation while handling various edge cases, such as end-of-file (EOF) and multiple calls to the function.

## Features

- **Line-by-Line Reading**: Retrieves one line at a time from a file descriptor.
- **Dynamic Memory Allocation**: Utilizes `malloc` and `free` to manage memory efficiently, minimizing leaks.
- **Buffer Management**: Implements a static buffer to store data between calls, allowing for seamless reading across multiple invocations.
- **Supports Multiple File Descriptors**: Can handle multiple file descriptors simultaneously using a static variable for each descriptor.

## Bonus Features

- **Get Next Line from Multiple Files**: Supports reading lines from multiple files simultaneously by managing multiple static buffers.
- **Robust Error Handling**: Gracefully manages errors, including invalid file descriptors and memory allocation failures.

## Key Technologies

- **C Programming Language**: The primary language used for implementing the function.
- **Dynamic Memory Management**: Utilizes `malloc`, `free`, and `realloc` for memory handling.
- **File Descriptor Handling**: Uses standard C functions for managing file input/output operations.

## Learning Outcomes

- Improved understanding of file I/O operations in C.
- Gained experience with dynamic memory allocation and management.
- Developed skills in implementing efficient algorithms for reading and processing input.

## How to Use

1. Clone the repository:
   ```bash
   git clone https://github.com/Bidiche49/get_next_line
   cd get_next_line
   ```
2. Compile the library:
   ```bash
   make
   ```
3. Include `get_next_line.h` and link the compiled library in your projects.

## Example Usage

```c
#include "get_next_line.h"
#include <fcntl.h> // For open()

int main() {
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line); // Free the line after use
    }

    close(fd);
    return 0;
}
```

## Compilation

To compile a project using `get_next_line`:
```bash
gcc -Wall -Wextra -Werror -o your_program your_program.c get_next_line.c
```

---
