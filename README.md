# CS 100 Programming Project
## Fall 2019 <br>
**Jiahe Gellert Li** -- #862157315 <br>
**Steven Joseph**

# Introduction
This is a custom unix shell program which can take various user inputs and exucute them. User can either type a single command or a string of commands separated by connectors.<br>
This program intends to use composite pattern for its design.<br>
This program uses `stringstream` to parse user inputs and abstract them into classes.<br>

---

Available connectors:
- ; Any command immediately follows a semicolon will be executed.
- && The following command will execute iff the preceding command succeeds.
- || The following command will execute iff the preceding command fails.

# Diagram
![UML Diagram][uml_diagram]

# Classes
## Base
The Base class is a generic abstract class.

## Connector
The Connector class is a base class for all connectors such as "; || &&".

## Semicolon, And, Or
These are derived classes from Connector which will have different implementation for execute() function.

## Command
The actual command string itself, such as "ls" or "cat".
> Note: only commands under /bin is available in this version of shell.


# Prototype/Research
Since the shell program constantly involves user input, we don't want to block the main thread while waiting for user input, or waiting for some commands finishing execution. <br>
A good solution is to use `fork()` to create a new process(thread) for each command, `execvp()` to execute the commands and `waitpid()` with `WNOHANG` flag to allow child processes to join the main process.<br>
The parser code and a sample program for using multithreading is under `prototype` dir.

# Development and Testing Roadmap
- Create minimal implementation of all classes
    - Base and Connector
    - Command
- Implement the parser function.
- Unit test without concurrency.
- Implement concurrency.
- Test concurrency. 
- Deploy.

[uml_diagram]: ./images/shell.png