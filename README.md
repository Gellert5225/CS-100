# CS 100 Programming Project
## Fall 2019 <br>
**Jiahe Gellert Li**, 862157315, jli542@ucr.edu <br>
**Steven Joseph**, 862083506, sjose007@ucr.edu

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

## CommandLine
A class that holds all Command in a `Base*` array.<br>
The public variable `b` will point to the root node.<br>
The overall structure will be a binary tree with leaves being Command, and it will be executed using inorder traversal.

## Command
The actual command string itself, such as "ls" or "cat". <br>
This class has a `char**` which contains the command argument, and it will be populated by a `vector<string>`
> Note: only commands under /bin is available in this version of shell.

## ParseFactory
An abstract factory base class for parsing usre input into either a regular command such as 'ls -a'<br>
or to a test command such as '[ -e /path/to/file ]'

## InputRedirect
Handling input redirect, using <. 

## OutputRedirect
Handling output redirect, using >. It has a flag stating whether user should replace or append the output.

## Pipe
Piping the output from previous command to the next command.


# Prototype/Research
Since the shell program constantly involves user input, we don't want to block the main thread while waiting for user input, or waiting for some commands finishing execution. <br>
A good solution is to use `fork()` to create a new process(thread) for each command, `execvp()` to execute the commands and `waitpid()` with `WNOHANG` flag to allow child processes to join the main process.<br>
The parser code and a sample program for using multithreading is under `prototype` dir.

# Development and Testing Roadmap
- Create minimal implementation of all classes
    - [Base and Connector](https://github.com/cs100/assignment-impromptu/issues/1)
    - [Command](https://github.com/cs100/assignment-impromptu/issues/2)
- [Implement the parser function](https://github.com/cs100/assignment-impromptu/issues/3)
- [Unit test without concurrency](https://github.com/cs100/assignment-impromptu/issues/4)
- [Implement concurrency](https://github.com/cs100/assignment-impromptu/issues/5)
- [Test concurrency](https://github.com/cs100/assignment-impromptu/issues/6)
- Deploy.

[uml_diagram]: ./images/RShell.png
