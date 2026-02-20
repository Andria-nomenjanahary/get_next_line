*This project was been created as part of the 42 curriculum by yvoandri*

# get_next_line

## Description

**get_next_line** is one of the core projects of the **42 curriculum**.

The goal of this project is to **write a function that reads a file descriptor line by line**, returning one line at each call, including the terminating newline character (`\n`) when present.

This project introduces important concepts such as:
- Static variables
- File descriptor management
- Memory allocation
- Buffered reading using `read()`

---

## Instructions

### Project structure
```
get_next_line/
├── get_next_line.c          # Core function logic
├── get_next_line_utils.c    # Utility functions
├── get_next_line.h          # Header file
```

### 1 - Clone the repository

First, download the project using `git clone`:

### 2 - Compile the project

You must create a file like main.c
Compile the source files:

```c
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c <main.c>
```
### 3 - Use it in your project

```c
#include "get_next_line.h";
```

Implement the function:

```c
char *get_next_line(int fd);
```
But you need to have a file that contains text.

Here are an example of a main code:

```c
#include "get_next_line.h"
#include "stdio.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("text.txt", O_RDONLY);

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}

```

## Resources

* static variable:
  [https://www.geeksforgeeks.org/c/static-variables-in-c/](https://www.geeksforgeeks.org/c/static-variables-in-c/)
* read manual:
  [https://man7.org/linux/man-pages/man2/read.2.html](https://man7.org/linux/man-pages/man2/read.2.html)
* open manual:
  [https://man7.org/linux/man-pages/man2/open.2.html](https://man7.org/linux/man-pages/man2/open.2.html)
* File Descriptor:
  [https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/](https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/)

## AI usage
* AI tools were used to:
* Clarify edge cases
* Improve code documentation
* Explain static variable behavior

## Core Concepts

The **get_next_line** project introduces several fundamental programming concepts in C.

### 🔹 Buffered Reading

Instead of reading a file character by character, **get_next_line** reads data in chunks using the `read()` system call and a fixed buffer size defined by `BUFFER_SIZE`.  
This approach significantly improves performance and efficiency.

---

### 🔹 Static Memory

A **static variable** is used to store leftover data that has been read but not yet returned as a complete line.  
This allows the function to “remember” where it stopped between successive calls.

---

### 🔹 Line Extraction

Each time `get_next_line()` is called:

- It checks whether a complete line already exists in the stored buffer  
- If not, it continues reading from the file descriptor  
- Once a newline character (`\n`) is found—or the end of file is reached—the function extracts and returns the next line

---

### 🔹 Memory Management

The function dynamically allocates memory for each returned line.  

---

## Function Workflow

1. Validate the file descriptor and `BUFFER_SIZE`
2. Read data from the file descriptor into a buffer
3. Append the buffer to a static storage variable
4. Search for a newline character (`\n`)
5. Extract the line to return
6. Preserve remaining data for the next function call

---

## Return Value

| Condition                         | Return Value                                |
|-----------------------------------|---------------------------------------------|
| A line is successfully read       | Allocated string containing the line        |
| Invalid file descriptor or error  | `NULL`                                      |

---

## Important Notes

- The returned line **includes the newline character (`\n`)** if it exists  
- `get_next_line` works with **any file descriptor** (files, standard input, pipes, etc.)    
- Proper error handling and memory cleanup are essential for correctness


## Project Goal

* Memory handling
* Static storage duration
* Efficient buffered reading

## Features

* Works with any file descriptor
* Supports variable BUFFER_SIZE
* Proper memory management (no leaks)
