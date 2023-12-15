# Monty ByteCode Interpreter

## Overview
This project aims to create a Monty ByteCode interpreter. Monty is a scripting language compiled into Monty ByteCodes, and the interpreter manipulates a unique stack with specific instructions.

## Learning Objectives
By completing this project, you will gain knowledge in:
- Understanding LIFO (Last In, First Out) and FIFO (First In, First Out)
- Implementing stacks and queues in C
- Working with doubly linked lists
- Proper use of global variables
- Avoiding plagiarism and self-sufficient problem-solving

## Requirements
- Editors: vi, vim, emacs
- Compilation: Ubuntu 20.04 LTS, gcc with options -Wall -Werror -Wextra -pedantic -std=c89
- Code style: Follow the Betty style
- Limitations: One global variable, no more than 5 functions per file
- Use of C standard library allowed
- Header file: monty.h with guarded inclusion
- GitHub: One repository per group, avoid cloning/forking existing repositories with the same name

## Data Structures
### Stack Structure
```c
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;
```

### Instruction Structure
```c
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```

## Compilation & Output
Compile using:
```bash
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
Output should be printed on stdout, errors on stderr.

## Monty Byte Code Files
Files with .m extension. One instruction per line, can have blank lines. Additional text after opcode or argument is ignored.

## The Monty Program
- Usage: `monty file` where file is the path to the Monty ByteCode file.
- Possible errors: invalid instruction, file opening failure, malloc failure.
- Exit status: EXIT_SUCCESS for successful execution, EXIT_FAILURE for errors.

## Tasks
1. **push, pall**
   - `push <int>`: Pushes an element to the stack.
   - `pall`: Prints all values on the stack.

2. **pint**
   - `pint`: Prints the value at the top of the stack.

3. **pop**
   - `pop`: Removes the top element of the stack.

4. **swap**
   - `swap`: Swaps the top two elements of the stack.

5. **add**
   - `add`: Adds the top two elements of the stack.

6. **nop**
   - `nop`: No-operation, does nothing.

## GitHub Repository
[GitHub repository: monty](<repository_link>)

## Note
Follow the provided instructions, complete each task in order, and adhere to the specified guidelines for successful project completion.
