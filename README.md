# Pipex

## Description
Pipex is a project designed to replicate the functionality of the shell command pipeline in Unix-like operating systems. The project requires the creation of a program that mimics the behavior of the shell command `"< file1 cmd1 | cmd2 > file2"`. 
This involves taking four parameters: two input file names (`file1` and `file2`) and two commands (`cmd1` and `cmd2`). The program then executes the two commands in parallel, with the output of `cmd1` serving as the input to `cmd2`, and writes the result to `file2`.

Pipex serves as a practical exercise helpful on understanding of process management, file descriptors, and inter-process communication in Unix systems.

## Description
this project employs various system calls and techniques to achieve its functionality:

- **Forking:** The program creates child processes using the fork system call to execute the specified commands concurrently.
- **Piping:** It establishes communication channels between the child processes using the pipe system call to create a pipeline for data transfer.
- **Command Execution:** The execve system call is used to replace the child process image with the specified commands, allowing them to be executed.
- **File Redirection:** The program redirects the standard input and output of the child processes to the appropriate files using file descriptors.

## Installation
1. Clone the repository:
    ```bash
    git clone https://github.com/aandom/pipex.git
    ```
2. Navigate to the project directory:
    ```bash
    cd pipex
    ```
3. Compile the program:
    ```bash
    make
    ```

## Usage
To use pipex, follow the following steps:
1. Provide the input and output file names, as well as the two commands as arguments:
    ```bash
    ./pipex file1 cmd1 cmd2 file2
    ```
2. The program will execute the two commands in parallel, with the output of `cmd1` serving as the input to `cmd2`. The result will be written to `file2`.

Example:
```bash
./pipex infile "ls -l" "grep pipex" outfile
```

## Bonus Features
1. Compile the program:
    ```bash
    make bonus
    ```
- **Support Heredoc File (<<) and Append (>>)**
  - The program supports appending output to a file using the >> operator.
  - The program supports the use of heredoc files as input. Heredoc files allow for inline input.

  Example:
    ```bash
    ./pipex here_doc LIMITER "cmd1" "cmd2" "cmd3 file2
    ```

- **Handle Multiple pipes** 
  - Pipex 42 can handle more than two commands in the pipeline. Simply provide additional commands as arguments.

  Example:
    ```bash
    ./pipex file1 cmd1 cmd2 cmd3 file2
    ```

