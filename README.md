
![ascii-text-art](https://github.com/zelhajou/get_next_line/assets/39954629/101271cd-0de4-4bf4-8516-867175c3a894)

`get_next_line()` is a function designed to read a file descriptor line by line in the C programming language. This repository contains an implementation of the `get_next_line()` function, which can be used to read lines from a file or standard input.

## Introduction

The get_next_line function reads a line from a file descriptor and returns it as a string. It provides a convenient way to process large files line by line without having to load the entire file into memory at once.

![file-descriptors](https://github.com/user-attachments/assets/cad86f37-84d0-4619-8ddb-6072bffdbede)


## Usage

To use the get_next_line function in your C program, you can follow these steps:

1. Clone the repository:

```shell
git clone https://github.com/zakelh6/get_next_line.git
```

2. Include the get_next_line.h header file in your program:

```c
#include "get_next_line.h"
```

3. Compile your program along with the get_next_line function:

```shell
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 your_program.c get_next_line.c get_next_line_utils.c
```

4. Start using the get_next_line function in your program:

```c
int main(void) {
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
```

## Function Signature

The function signature of get_next_line is as follows:

```c
char *get_next_line(int fd);
```

- `fd`: The file descriptor from which to read the next line.

## Return Value

The `get_next_line` function returns a pointer to a string containing the next line read from the file descriptor. It returns `NULL` when the end of the file is reached or an error occurs.
